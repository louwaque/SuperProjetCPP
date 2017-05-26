#include "../include/GraphicsTriangle.hpp"
#include "../include/GraphicsPoint.hpp"
#include "../include/GraphicsAnchor.hpp"

GraphicsTriangle::GraphicsTriangle(GraphicsItem *parent)
: GraphicsShape(parent)
{
  GraphicsPoint *first = new GraphicsAnchor(this);
  GraphicsPoint *second = new GraphicsPoint(this);
  GraphicsPoint *third = new GraphicsPoint(this);
  m_points.push_back(first);
  m_points.push_back(second);
  m_points.push_back(third);
}
