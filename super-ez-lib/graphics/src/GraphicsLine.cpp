#include "../include/GraphicsLine.hpp"
#include "../include/GraphicsPoint.hpp"
#include "../include/GraphicsAnchor.hpp"

GraphicsLine::GraphicsLine(GraphicsItem *parent)
: GraphicsShape(parent)
{
  m_points.emplace_back();
  m_points.emplace_back();
}
