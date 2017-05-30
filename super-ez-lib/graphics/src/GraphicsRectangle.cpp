#include "../include/GraphicsRectangle.hpp"
#include "../include/GraphicsPoint.hpp"
#include "../include/GraphicsAnchor.hpp"


GraphicsRectangle::GraphicsRectangle(GraphicsItem *parent)
: GraphicsItem(parent),
  m_topLeft(Point::make()),
  m_bottomRight(Point::make())
{
  //FIXME PointRelative ?
  // m_topLeft.setOriginDynamic(position());
  // m_bottomRight.setOriginDynamic(position());
}

void GraphicsRectangle::meDraw(Canvas *canvas)
{
  if (canvas)
    canvas->drawRectangle(*m_topLeft, *m_bottomRight, isFill());
}

bool GraphicsRectangle::meIsOver(const Point &absoluteP)
{
  return *position() + *m_topLeft < absoluteP and absoluteP < *position() + *m_bottomRight;
}

void GraphicsRectangle::setWidth(const size_t width)
{
  m_bottomRight->setX(width);
}

void GraphicsRectangle::setHeight(const size_t height)
{
  m_bottomRight->setY(height);
}
