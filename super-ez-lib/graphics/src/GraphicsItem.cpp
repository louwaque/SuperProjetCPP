#include "../include/GraphicsItem.hpp"
#include <MouseEvent.hpp>
#include <iostream>
#include <algorithm>
#include <utility>

GraphicsItem *GraphicsItem::m_focusItem = nullptr;
std::map<GraphicsItem::Id, GraphicsItem*> GraphicsItem::m_graphicsItems;

GraphicsItem::GraphicsItem(const Id &parent)
: m_id(boost::uuids::random_generator()()),
  m_parent(nullptr),
  m_children(),
  m_position(),
  m_z(0),
  m_color(Color(Color::Black)),
  m_thick(1),
  m_isFill(false),
  m_isEnable(true),
  m_isVisible(true)
{
  m_graphicsItems[m_id] = this;
  setParent(parent);
}

GraphicsItem::GraphicsItem(const Ptr &parent)
: GraphicsItem()
{
  setParent(parent);
}

GraphicsItem::GraphicsItem(const GraphicsItem *parent)
: GraphicsItem()
{
  setParent(parent);
}

GraphicsItem::~GraphicsItem()
{
  m_graphicsItems.erase(m_id);
  setParent(nullptr);
}

void GraphicsItem::setParent(const Id &parent)
{
  if (parentId() != parent) {
    auto ptr = m_graphicsItems[parent];
    if (ptr)
      setParent(ptr);
    else
      setParent(nullptr);
  }
}

void GraphicsItem::setParent(const Ptr &parent)
{
  setParent(parent.get());
}

void GraphicsItem::setParent(const GraphicsItem *parent)
{
  if (m_parent == parent)
    return;

  if (parent) {
    if (parent == this)
      throw std::runtime_error("GraphicsItem::setParent: parent == this");

    for(auto &ptr : m_children) {
      if (ptr.get() == parent)
        throw std::runtime_error("GraphicsItem::setParent: parent is in children");
    }
  }

  if (m_parent) {
    auto p = m_parent;
    m_parent = nullptr;
    m_position.setOrigin(nullptr);

    auto it = std::find_if(p->m_children.begin(), p->m_children.end(), [this](const Ptr &ptr){
      if (ptr)
        return ptr->id() == m_id;
      else
        return false;
    });

    if (it != p->m_children.end())
      p->m_children.erase(it);
  }

  if (parent) {
    GraphicsItem * p = const_cast<GraphicsItem*>(parent);
    m_parent = p;

    try {
      p->m_children.emplace_back(shared_from_this());
    } catch(std::bad_weak_ptr& e) {
      p->m_children.emplace_back(this);
    }

    p->sortChildren();
    m_position.setOrigin(&p->position());
  }
}

void GraphicsItem::setZ(const int z)
{
  m_z = z;
  if(parent())
    parent()->sortChildren();
}

void GraphicsItem::draw(Canvas *canvas)
{
  if (!m_isVisible)
    return;

  for (auto &ptr : m_children)
    if (ptr)
      ptr->draw(canvas);

  if(canvas) {
    canvas->setColor(m_color.hexa());
    canvas->setThick(m_thick);
  }
  meDraw(canvas);
}

void GraphicsItem::update(const unsigned int time)
{
  if (!m_isEnable)
    return;

  for (auto &ptr : m_children)
    if (ptr)
      ptr->update(time);

  meUpdate(time);
}

void GraphicsItem::handleEvent(const Event &event)
{
  if (!m_isEnable)
    return;

  if (event.type() == Event::MouseType) {
    const MouseEvent &mouse = dynamic_cast<const MouseEvent&>(event);
    if (mouse.button() == MouseEvent::LeftButton &&
        mouse.state() == MouseEvent::ButtonPressed) {
          if (isOver(mouse.position()))
            setFocusItem(this);
          else if (focusItem() == this)
            setFocusItem(nullptr);
      }
  }

  for (auto &ptr : m_children)
    if (ptr)
      ptr->handleEvent(event);

  meHandleEvent(event);
}


bool GraphicsItem::isOver(const Point &p)
{
  if (!m_isEnable)
    return false;

  bool result = false;

  for (const auto &ptr : m_children)
    if (ptr)
      result |= ptr->isOver(p);

  return result || meIsOver(p);
}

void GraphicsItem::sortChildren()
{
  std::sort(m_children.begin(), m_children.end(), [this](const Ptr &l, const Ptr &r) {
    if (l && r)
      return l->z() < r->z();
    else
      throw std::runtime_error("GraphicsItem::sortChildren: null pointer");
  });
}

template<>
GraphicsItem::GraphicsItemList GraphicsItem::children(const SearchTypes option) const
{
  return children<GraphicsItem>(option);
}

bool operator==(const GraphicsItem &l, const GraphicsItem &r)
{
  return l.id() == r.id();
}

bool operator!=(const GraphicsItem &l, const GraphicsItem &r)
{
  return l.id() != r.id();
}
