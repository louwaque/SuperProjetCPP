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
  size_t oldMW = m_minimumWidth, oldMH = m_minimumHeight;
  m_minimumWidth = 0;
  m_minimumHeight = 0;
  if (m_orientation == Horizontal) {
    for (Widget *widget : m_widgets) {
      m_minimumWidth += widget->minimumWidth();
      m_minimumHeight = std::max(m_minimumHeight, widget->minimumHeight());
    }
  } else if (m_orientation == Vertical) {
    for (Widget *widget : m_widgets) {
      m_minimumWidth = std::max(m_minimumWidth, widget->minimumWidth());
      m_minimumHeight += widget->minimumHeight();
    }
  }

  if (m_minimumWidth != oldMW)
    m_minimumWidthChanged();
  if (m_minimumHeight != oldMH)
    m_minimumHeightChanged();

  if (!m_widgets.empty()) {
    int x(0), y(0), w(0), h(0);

    if (m_orientation == Horizontal) {
      w = width()/m_widgets.size() - m_spacing;
      h = height();
    } else if (m_orientation == Vertical) {
      w = width();
      h = height()/m_widgets.size() - m_spacing;
    }

    for (Widget *widget : m_widgets) {
      widget->position().setRelative(x, y);
      widget->setWidth(w);
      widget->setHeight(h);
      if (m_orientation == Horizontal) {
        x += m_spacing + w;
      } else if (m_orientation == Vertical) {
        y += m_spacing + h;
      }
    }
  }
}
