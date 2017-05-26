#include "../include/GraphicsItem.hpp"
#include <iostream>

GraphicsItem::GraphicsItem(GraphicsItem *parent)
: m_parent(nullptr), m_children(), m_anchor(), m_positionCorrector(), m_z(0), m_color(Color(Color::Black)), m_thick(1), m_isFill(false), m_isVisible(true)
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
  if (m_parent)
    m_parent->m_children.push_back(std::unique_ptr<GraphicsItem>(this));
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

Point GraphicsItem::absolute() const
{
  if (m_parent)
    return m_anchor + m_parent->absolute();
  else
    return m_anchor;
}

void GraphicsItem::setAbsolute(const Point &pos)
{
  if (m_parent)
    setAnchor(pos - m_parent->absolute());
  else
    setAnchor(pos);
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
  for (auto &ptr : m_children)
    ptr->update(time);

  meUpdate(time);
}

void GraphicsItem::handleEvent(const Event &event)
{
  for (auto &ptr : m_children)
    ptr->handleEvent(event);

  meHandleEvent(event);
}


bool GraphicsItem::isOver(const Point &p)
{
  if (!m_isVisible)
    return false;

  bool result = false;
  for (auto &ptr : m_children)
    result |= ptr->isOver(p);
  return result || meIsOver(p);
}
