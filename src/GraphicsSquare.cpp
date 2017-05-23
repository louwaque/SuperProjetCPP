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
    // Point distP(m_bottomRight->anchor() - m_topLeft->anchor());
    // int dist = std::hypot(distP.x(), distP.y());
    // std::cerr << dist << std::endl;
    // return Point(pos.x() - dist, pos.y() + dist);
    return pos;
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
