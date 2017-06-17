#include "../include/GraphicsShape.hpp"

GraphicsShape::GraphicsShape(GraphicsItem *parent)
: GraphicsItem(parent),
  m_points()
{}

void GraphicsShape::meDraw(Canvas *canvas)
{
  if (canvas) {
    if (isFill() && m_points.size() >= 3)
      for (size_t i = 2; i < m_points.size(); ++i)
        canvas->drawTriangle(m_points[0], m_points[i-1], m_points[i], true);
    else
      for (size_t i = 0; i < m_points.size(); ++i)
        canvas->drawLine(m_points[i], m_points[(i+1)%m_points.size()]);
  }
}
