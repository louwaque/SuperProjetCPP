#include "../include/Layout.hpp"

Layout::Layout(GraphicsItem *parent)
: Widget(parent),
  m_orientation(Horizontal),
  m_spacing(0),
  m_widgets(),
  m_minimumWidth(0),
  m_minimumHeight(0)
{
  widthChanged(boost::bind(&Layout::organize, this));
  heightChanged(boost::bind(&Layout::organize, this));
}

Layout::Layout(const Orientation orientation, GraphicsItem *parent)
: Layout(parent)
{
  setOrientation(orientation);
}

void Layout::push_back(Widget *widget)
{
  if (widget) {
    m_widgets.push_back(widget);
    widget->setParent(this);
    organize();
  }
}

Widget *Layout::pop_back()
{
  Widget *widget = m_widgets.back();
  widget->setParent(nullptr);
  m_widgets.pop_back();
  organize();
  return widget;
}

void Layout::organize()
{
  for (Widget *widget : m_widgets) {
    m_minimumWidth = std::max(m_minimumWidth, widget->minimumWidth());
    m_minimumHeight = std::max(m_minimumHeight, widget->minimumHeight());
  }
  size_t x(0), y(0);
  for (Widget *widget : m_widgets) {
    widget->position().setRelative(x, y);
    if (m_orientation == Horizontal) {
      widget->setWidth(widget->minimumWidth());
      widget->setHeight(height());
      x += m_spacing + widget->width();
    } else if (m_orientation == Vertical) {
      widget->setWidth(width());
      widget->setHeight(widget->minimumHeight());
      y += m_spacing + widget->height();
    }
  }
}
