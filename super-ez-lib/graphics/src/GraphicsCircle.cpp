#include "../include/GraphicsCircle.hpp"
#include "../include/GraphicsPoint.hpp"
#include "../include/GraphicsAnchor.hpp"
#include <cmath>

GraphicsCircle::GraphicsCircle(GraphicsItem *parent)
: GraphicsShape(parent)
{
  GraphicsItem *center = new GraphicsAnchor(this);
  GraphicsItem *radius = new GraphicsPoint(this);
  m_points.push_back(center);
  m_points.push_back(radius);
}

void GraphicsCircle::meDraw(Canvas *canvas)
{
  if (canvas) {
    Point distP = radius()->absolute() - center()->absolute();
    int dist = hypot(distP.x(), distP.y());
    canvas->drawCircle(center()->absolute() - dist, center()->absolute() + dist, isFill());
  }
}

bool GraphicsCircle::meIsOver(const Point &absoluteP)
{
  return false;
}
