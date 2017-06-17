#include "../include/GraphicsCircle.hpp"
#include <cmath>

GraphicsCircle::GraphicsCircle(GraphicsItem *parent)
: GraphicsShape(parent)
{
  m_points.emplace_back(&position());
  m_points.emplace_back(&position());
}

int GraphicsCircle::radius() const
{
  Point distP = radiusPt() - center();
  return hypot(distP.x(), distP.y());
}

void GraphicsCircle::setRadius(const int radius)
{
  //FIXME faire des maths
}

void GraphicsCircle::meDraw(Canvas *canvas)
{
  if (canvas)
    canvas->drawCircle(center() - radius(), center() + radius(), isFill());
}

bool GraphicsCircle::meIsOver(const Point &absoluteP)
{
  //FIXME pas trop compliqué donc faut le faire !
  return false;
}
