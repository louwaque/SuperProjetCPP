#include "../include/Widget.hpp"

Widget::Widget(GraphicsItem *parent)
: GraphicsItem(parent),
  m_width(0),
  m_height(0)
{}

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
