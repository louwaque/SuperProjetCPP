#include "../include/GraphicsSquare.hpp"
#include "../include/GraphicsPoint.hpp"
#include "../include/GraphicsAnchor.hpp"
#include <cmath>
#include <iostream>

GraphicsSquare::GraphicsSquare(GraphicsItem *parent)
: GraphicsItem(parent), m_topLeft(nullptr), m_bottomRight(nullptr)
{
  m_topLeft = new GraphicsAnchor(this);
  m_bottomRight = new GraphicsPoint(this);
  m_bottomRight->setPositionCorrector([this](const Point &pos) {
    Point diffP(pos - m_topLeft->anchor());
    double radius = std::hypot(diffP.x(), diffP.y());
    return Point(std::cos(std::sqrt(2)/2.0)*radius, std::sin(std::sqrt(2)/2.0)*radius);
  });
}

void GraphicsSquare::meDraw(Canvas *canvas)
{
  if (canvas)
    canvas->drawRectangle(topLeft()->absolute(), bottomRight()->absolute(), isFill());
}

bool GraphicsSquare::meIsOver(const Point &absoluteP)
{
  return topLeft()->absolute() < absoluteP and absoluteP < bottomRight()->absolute();
}
