#include "../include/GraphicsEllipse.hpp"
#include "../include/GraphicsPoint.hpp"
#include "../include/GraphicsAnchor.hpp"

GraphicsEllipse::GraphicsEllipse(GraphicsItem *parent)
: GraphicsShape(parent)
{
  GraphicsItem *center = new GraphicsAnchor(this);
  GraphicsItem *radius = new GraphicsPoint(this);
  m_points.push_back(center);
  m_points.push_back(radius);
}

void GraphicsEllipse::meDraw(Canvas *canvas)
{
  if (canvas)
    canvas->drawCircle(center()->absolute(), radius()->absolute(), isFill());
}

bool GraphicsEllipse::meIsOver(const Point &absoluteP)
{
  return false;
}
