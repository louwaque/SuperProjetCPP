#include "../include/Widget.hpp"

Widget::Widget(GraphicsItem *parent)
: GraphicsItem(parent),
  m_width(0),
  m_height(0)
{
  minimumWidthChanged([this](){
    if (minimumWidth() == width())
      m_widthChanged();
  });
  minimumHeightChanged([this](){
    if (minimumHeight() == height())
      m_heightChanged();
  });
}

void Widget::setWidth(const size_t width)
{
  if (width != m_width) {
    m_width = width;
    m_widthChanged();
  }
}

void Widget::setHeight(const size_t height)
{
  if (height != m_height) {
    m_height = height;
    m_heightChanged();
  }
}

bool Widget::meIsOver(const Point &absoluteP)
{
  return position() < absoluteP && absoluteP < position() + Point(width(), height());
}
