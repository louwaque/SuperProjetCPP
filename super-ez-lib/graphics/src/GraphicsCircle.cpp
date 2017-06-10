#include "../include/GraphicsCircle.hpp"
#include <cmath>

GraphicsCircle::GraphicsCircle(const Id &parent)
: GraphicsShape(parent)
{
  m_points.emplace_back(&position());
  m_points.emplace_back(&position());
}

GraphicsCircle::GraphicsCircle(const Ptr &parent)
: GraphicsCircle()
{
  setParent(parent);
}

GraphicsCircle::GraphicsCircle(const GraphicsItem *parent)
: GraphicsCircle()
{
  setParent(parent);
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
