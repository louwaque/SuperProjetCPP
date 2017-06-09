#include "../include/GraphicsLine.hpp"

GraphicsLine::GraphicsLine(const Id &parent)
: GraphicsShape(parent)
{
  m_points.emplace_back(&position());
  m_points.emplace_back(&position());
}

GraphicsLine::GraphicsLine(const Ptr &parent)
: GraphicsShape()
{
  setParent(parent);
}

GraphicsLine::GraphicsLine(const GraphicsItem *parent)
: GraphicsShape()
{
  setParent(parent);
}
