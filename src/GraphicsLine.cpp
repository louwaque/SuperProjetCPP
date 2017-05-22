#include "../include/GraphicsLine.hpp"
#include "../include/GraphicsPoint.hpp"
#include "../include/GraphicsAnchor.hpp"

GraphicsLine::GraphicsLine(GraphicsItem *parent)
: GraphicsShape(parent)
{
  GraphicsPoint *first = new GraphicsAnchor(this);
  GraphicsPoint *second = new GraphicsPoint(this);
  m_points.push_back(first);
  m_points.push_back(second);
}
