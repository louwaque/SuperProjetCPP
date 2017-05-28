#include "../include/GraphicsRectangle.hpp"
#include "../include/GraphicsPoint.hpp"
#include "../include/GraphicsAnchor.hpp"


GraphicsRectangle::GraphicsRectangle(GraphicsItem *parent)
: GraphicsItem(parent),
  m_topLeft(),
  m_bottomRight()
{
  m_topLeft.setParent(&relative());
  m_bottomRight.setParent(&relative());
}

void GraphicsRectangle::meDraw(Canvas *canvas)
{
  if (canvas)
    canvas->drawRectangle(m_topLeft.absolute(), m_bottomRight.absolute(), isFill());
}

bool GraphicsRectangle::meIsOver(const Point &absoluteP)
{
  return absolute() + m_topLeft < absoluteP and absoluteP < absolute() + m_bottomRight;
}

void GraphicsRectangle::setWidth(const size_t width)
{
  m_bottomRight.setX(width);
}

void GraphicsRectangle::setHeight(const size_t height)
{
  m_bottomRight.setY(height);
}
