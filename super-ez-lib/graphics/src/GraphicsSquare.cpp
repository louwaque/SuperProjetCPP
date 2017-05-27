#include "../include/GraphicsSquare.hpp"
#include "../include/GraphicsPoint.hpp"
#include "../include/GraphicsAnchor.hpp"
#include <cmath>

GraphicsSquare::GraphicsSquare(GraphicsItem *parent)
: GraphicsItem(parent),
  m_topLeft(),
  m_bottomRight()
{
  m_bottomRight.setCorrector([this](const Point &pos) {
    Point diffP(pos - m_topLeft);
    double radius = std::hypot(diffP.x(), diffP.y());
    if (pos < Point()) radius = - radius;
    return Point(std::cos(std::sqrt(2)/2.0)*radius, std::sin(std::sqrt(2)/2.0)*radius);
  });
}

void GraphicsSquare::meDraw(Canvas *canvas)
{
  if (canvas)
    canvas->drawRectangle(absolute() + m_topLeft, absolute() + m_bottomRight, isFill());
}

bool GraphicsSquare::meIsOver(const Point &absoluteP)
{
  return absolute() + m_topLeft < absoluteP and absoluteP < absolute() + m_bottomRight;
}
