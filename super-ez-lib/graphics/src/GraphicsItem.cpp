#include "../include/GraphicsItem.hpp"
#include <MouseEvent.hpp>
#include <iostream>
#include <algorithm>
#include <utility>

GraphicsItem *GraphicsItem::m_focusItem = nullptr;
std::map<GraphicsItem::Id, GraphicsItem::Ptr> GraphicsItem::m_graphicsItems;

GraphicsItem::GraphicsItem(const Id &parent)
: m_id(boost::uuids::random_generator()()),
  m_parent(boost::uuids::nil_generator()()),
  m_children(),
  m_position(),
  m_z(0),
  m_color(Color(Color::Black)),
  m_thick(1),
  m_isFill(false),
  m_isVisible(true)
{
  std::cerr << "new GraphicsItem: " << this << '\n';
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
  setParent();
  std::cerr << "GraphicsItem deleted :" << this << " of type : " << type() << std::endl;
}

void GraphicsItem::setParent(const Id &parent)
{
  if (m_parent == parent)
    return;

  auto ptr = m_graphicsItems[m_parent];
  if (ptr)
    ptr->m_children.erase(std::remove(ptr->m_children.begin(), ptr->m_children.end(), id()), ptr->m_children.end());

  m_parent = parent;

  ptr = m_graphicsItems[m_parent];
  if (ptr) {
    ptr->m_children.push_back(id());
    m_position.setOrigin(&ptr->position());
  } else {
    m_position.setOrigin(nullptr);
  }
}

void GraphicsItem::setParent(const Ptr &parent)
{
  if (parent)
    setParent(parent->id());
  else
    setParent();
}

void GraphicsItem::setParent(const GraphicsItem *parent)
{
  if (parent)
    setParent(parent->id());
  else
    setParent();
}

GraphicsItem::GraphicsItemList GraphicsItem::children(const GraphicsTypes filter, const SearchTypes option) const
{
  GraphicsItemList list;
  for (const Id id : m_children) {
    auto ptr = m_graphicsItems[id];
    if (ptr) {
      if (option == ChildrenRecursively) {
        GraphicsItemList sublist = ptr->children(filter, option);
        list.insert(list.end(), sublist.begin(), sublist.end());
      }
      if (filter == UndefinedType or ptr->type() == filter)
        list.push_back(ptr.get());
    }
  }
  return list;
}

void GraphicsItem::draw(Canvas *canvas)
{
  if (!m_isVisible)
    return;

  for (const Id id : m_children) {
    auto ptr = m_graphicsItems[id];
    if (ptr)
      ptr->draw(canvas);
  }
  if(canvas) {
    canvas->setColor(m_color.hexa());
    canvas->setThick(m_thick);
  }
  meDraw(canvas);
}

void GraphicsItem::update(const unsigned int time)
{
  for (const Id id : m_children) {
    auto ptr = m_graphicsItems[id];
    if (ptr)
      ptr->update(time);
  }

  meUpdate(time);
}

void GraphicsItem::handleEvent(const Event &event)
{
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

  for (const Id id : m_children) {
    auto ptr = m_graphicsItems[id];
    if (ptr)
      ptr->handleEvent(event);
  }

  meHandleEvent(event);
}


bool GraphicsItem::isOver(const Point &p)
{
  if (!m_isVisible)
    return false;

  bool result = false;
  for (const Id id : m_children) {
    auto ptr = m_graphicsItems[id];
    if (ptr)
      result |= ptr->isOver(p);
  }
  return result || meIsOver(p);
}

bool operator==(const GraphicsItem &l, const GraphicsItem &r)
{
  return l.id() == r.id();
}

bool operator!=(const GraphicsItem &l, const GraphicsItem &r)
{
  return l.id() != r.id();
}
