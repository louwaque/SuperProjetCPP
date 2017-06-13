#include "../include/GraphicsPolygon.hpp"

GraphicsPolygon::GraphicsPolygon(const Id &parent)
: GraphicsShape(parent)
{
  m_points.emplace_back(&position());
}

GraphicsPolygon::GraphicsPolygon(const Ptr &parent)
: GraphicsPolygon()
{
  setParent(parent);
}

GraphicsPolygon::GraphicsPolygon(const GraphicsItem *parent)
: GraphicsPolygon()
{
  setParent(parent);
}

Point &GraphicsPolygon::newPoint()
{
  m_points.emplace_back(&position());
  return m_points.back();
}

void GraphicsPolygon::popPoint()
{
  if (m_points.size() > 1)
    m_points.pop_back();
}

void GraphicsPolygon::setNbPoints(const size_t nb)
{
  if (nb > 0) {
    while (nb > nbPoints())
      newPoint();

    while (nbPoints() > nb)
      popPoint();
  }
}
