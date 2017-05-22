#include "../include/GraphicsPoint.hpp"

GraphicsPoint::GraphicsPoint(GraphicsItem *parent)
: GraphicsItem(parent), m_radius(5)
{
}

GraphicsPoint::GraphicsPoint(const Point &anchor, GraphicsItem *parent)
: GraphicsPoint(parent)
{
  setAnchor(anchor);
}

void GraphicsPoint::meDraw(Canvas *canvas)
{
  if (canvas)
    canvas->drawCircle(absolute() - m_radius, absolute() + m_radius, isFill());
}

bool GraphicsPoint::meIsOver(const Point &absoluteP)
{
  return absolute() - m_radius < absoluteP and absoluteP < absolute() + m_radius;
}
