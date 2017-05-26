#include "../include/GraphicsPolygon.hpp"
#include "../include/GraphicsPoint.hpp"
#include "../include/GraphicsAnchor.hpp"

GraphicsPolygon::GraphicsPolygon(GraphicsItem *parent)
: GraphicsShape(parent)
{
  GraphicsPoint *a = new GraphicsAnchor(this);
  m_points.push_back(a);
}

GraphicsItem *GraphicsPolygon::newPoint()
{
  GraphicsItem *item = new GraphicsPoint(this);
  m_points.push_back(item);
  return item;
}

void GraphicsPolygon::popPoint()
{
  if (m_points.size() > 2) {
    delete m_points.back();
    m_points.pop_back();
  }
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
