#include "../include/GraphicsEllipse.hpp"

GraphicsEllipse::GraphicsEllipse(const Id &parent)
: GraphicsItem(parent),
m_points()
{
  m_points.emplace_back(&position());
  m_points.emplace_back(&position());
}

GraphicsEllipse::GraphicsEllipse(const Ptr &parent)
:GraphicsEllipse()
{
  setParent(parent);
}

GraphicsEllipse::GraphicsEllipse(const GraphicsItem *parent)
:GraphicsEllipse()
{
  setParent(parent);
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
