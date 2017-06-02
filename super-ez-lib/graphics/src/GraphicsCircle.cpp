#include "../include/GraphicsCircle.hpp"
#include "../include/GraphicsPoint.hpp"
#include "../include/GraphicsAnchor.hpp"
#include <cmath>

GraphicsCircle::GraphicsCircle(GraphicsItem *parent)
: GraphicsShape(parent)
{
  m_points.emplace_back();
  m_points.emplace_back();
}

void GraphicsCircle::meDraw(Canvas *canvas)
{
  if (canvas) {
    Point distP = radius() - center();
    int dist = hypot(distP.x(), distP.y());
    canvas->drawCircle(center() - dist, center() + dist, isFill());
  }
}

bool GraphicsCircle::meIsOver(const Point &absoluteP)
{
  //FIXME pas trop compliqué donc faut le faire !
  return false;
}
