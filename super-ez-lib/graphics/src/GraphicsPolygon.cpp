#include "../include/GraphicsPolygon.hpp"

GraphicsPolygon::GraphicsPolygon(const Ptr &parent)
: GraphicsShape(parent)
{}

Point &GraphicsPolygon::newPoint()
{
  m_points.emplace_back(&position());
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
