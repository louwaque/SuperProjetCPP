#include "../include/GraphicsPolygon.hpp"
#include "../include/GraphicsPoint.hpp"
#include "../include/GraphicsAnchor.hpp"

GraphicsPolygon::GraphicsPolygon(GraphicsItem *parent)
: GraphicsShape(parent)
{}

Point &GraphicsPolygon::newPoint()
{
  m_points.emplace_back();
  return m_points.back();
}

void GraphicsPolygon::popPoint()
{
  if (m_points.size() > 2)
    m_points.pop_back();
}

void GraphicsPolygon::setNbPoints(const size_t nb)
{
  if (nb <= 1)
    return;

  while (nb > nbPoints())
    newPoint();

  while (nbPoints() > nb)
    popPoint();
}
