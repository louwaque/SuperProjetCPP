#include "../include/GraphicsEllipse.hpp"

GraphicsEllipse::GraphicsEllipse(GraphicsItem *parent)
: GraphicsShape(parent)
{
  m_points.emplace_back(&position());
  m_points.emplace_back(&position());
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
