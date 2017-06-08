#include "../include/GraphicsItem.hpp"
#include <MouseEvent.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <iostream>
#include <algorithm>

GraphicsItem *GraphicsItem::m_focusItem = nullptr;

GraphicsItem::GraphicsItem(GraphicsItem *parent)
: m_id(boost::uuids::random_generator()()),
  m_parent(nullptr),
  m_children(),
  m_position(),
  m_z(0),
  m_color(Color(Color::Black)),
  m_thick(1),
  m_isFill(false),
  m_isVisible(true)
{
  setParent(parent);
}

GraphicsItem::~GraphicsItem()
{
  setParent(nullptr);
  std::cerr << "GraphicsItem deleted :" << this << " of type : " << type() << std::endl;
}

void GraphicsItem::setParent(GraphicsItem *parent)
{
  if (m_parent == parent)
    return;

  if (m_parent) {
    m_parent->m_children.erase(std::remove_if(m_parent->m_children.begin(), m_parent->m_children.end(), [this](const std::shared_ptr<GraphicsItem> &ptr){
      return *ptr == *this;
    }), m_parent->m_children.end());
  }
  m_parent = parent;
  if (m_parent) {
    m_parent->m_children.push_back(std::shared_ptr<GraphicsItem>(this));
    m_position.setOrigin(&m_parent->position());
  } else {
    m_position.setOrigin(nullptr);
  }
}

GraphicsItem::GraphicsItemList GraphicsItem::children(const GraphicsTypes filter, const SearchTypes option) const
{
  GraphicsItemList list;
  for (auto &ptr : m_children) {
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
  for (auto &ptr : m_children)
    if (ptr)
      ptr->update(time);

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

  for (auto &ptr : m_children)
    if (ptr)
      ptr->handleEvent(event);

  meHandleEvent(event);
}


bool GraphicsItem::isOver(const Point &p)
{
  if (!m_isVisible)
    return false;

  bool result = false;
  for (auto &ptr : m_children)
    if (ptr)
      result |= ptr->isOver(p);
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
