#include "../include/GraphicsItem.hpp"
#include <MouseEvent.hpp>
#include <iostream>

GraphicsItem *GraphicsItem::m_focusItem = nullptr;

GraphicsItem::GraphicsItem(GraphicsItem *parent)
: m_parent(nullptr),
  m_children(),
  m_position(),
  m_z(0),
  m_color(Color(Color::Black)),
  m_thick(1),
  m_isFill(false),
  m_isEnable(true),
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
    for (size_t i = 0; i < m_parent->m_children.size(); ++i) {
      if (m_parent->m_children[i].get() == this) {
        m_parent->m_children[i].release();
        m_parent->m_children.erase(m_parent->m_children.begin()+i);
      }
    }
  }
  m_parent = parent;
  if (m_parent) {
    m_parent->m_children.push_back(std::unique_ptr<GraphicsItem>(this));
    m_position.setOrigin(&m_parent->position());
  } else {
    m_position.setOrigin(nullptr);
  }
}

GraphicsItem::GraphicsItemList GraphicsItem::children(const GraphicsTypes filter, const SearchTypes option) const
{
  GraphicsItemList list;
  for (auto &ptr : m_children) {
    if (option == ChildrenRecursively) {
      GraphicsItemList sublist = ptr->children(filter, option);
      list.insert(list.end(), sublist.begin(), sublist.end());
    }
    if (filter == UndefinedType or ptr->type() == filter)
      list.push_back(ptr.get());
  }
  return list;
}

void GraphicsItem::draw(Canvas *canvas)
{
  if (!m_isVisible)
    return;

  for (auto &ptr : m_children)
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
    ptr->handleEvent(event);

  meHandleEvent(event);
}


bool GraphicsItem::isOver(const Point &p)
{
  if (!m_isEnable)
    return false;

  bool result = false;
  for (auto &ptr : m_children)
    result |= ptr->isOver(p);

  return result || meIsOver(p);
}
