#include "../include/GraphicsSquare.hpp"
#include "../include/GraphicsPoint.hpp"
#include "../include/GraphicsAnchor.hpp"
#include <cmath>

GraphicsSquare::GraphicsSquare(GraphicsItem *parent)
: GraphicsItem(parent),
  m_topLeft(),
  m_bottomRight({[this](const Point &pos) {
    Point diffP(pos - m_topLeft);
    double radius = std::hypot(diffP.x(), diffP.y());
    if (pos < Point()) radius = - radius;
    return Point(std::cos(std::sqrt(2)/2.0)*radius, std::sin(std::sqrt(2)/2.0)*radius);
  }})
{
}

void GraphicsSquare::meDraw(Canvas *canvas)
{
  if (canvas)
    canvas->drawRectangle(position().absolute() + m_topLeft, position().absolute() + m_bottomRight, isFill());
}

bool GraphicsSquare::meIsOver(const Point &absoluteP)
{
  return position().absolute() + m_topLeft < absoluteP and absoluteP < position().absolute() + m_bottomRight;
}
