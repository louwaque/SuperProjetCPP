#include "../include/GraphicsLine.hpp"

GraphicsLine::GraphicsLine(GraphicsItem *parent)
: GraphicsShape(parent)
{
  m_points.emplace_back(&position());
  m_points.emplace_back(&position());
}
