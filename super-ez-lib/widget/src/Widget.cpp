#include "../include/Widget.hpp"

Widget::Widget(GraphicsItem *parent)
: GraphicsItem(parent),
  m_width(0),
  m_height(0),
  m_background(nullptr)
{
  m_background = new GraphicsRectangle(this);

  widthChanged([this]() {
    m_background->setWidth(width());
  });
  heightChanged([this]() {
    m_background->setHeight(height());
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
