#include "../include/GraphicsEllipse.hpp"
#include "../include/GraphicsPoint.hpp"
#include "../include/GraphicsAnchor.hpp"

GraphicsEllipse::GraphicsEllipse(GraphicsItem *parent)
: GraphicsShape(parent)
{
  m_points.emplace_back();
  m_points.emplace_back();
}

void GraphicsEllipse::meDraw(Canvas *canvas)
{
  if (canvas)
    canvas->drawCircle(center(), radius(), isFill());
}

bool GraphicsEllipse::meIsOver(const Point &absoluteP)
{
  //FIXME hardcore
  return false;
}
