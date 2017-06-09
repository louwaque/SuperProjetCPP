#include "../include/GraphicsLine.hpp"

GraphicsLine::GraphicsLine(const Id &parent)
: GraphicsShape(parent)
{
  m_points.emplace_back(&position());
  m_points.emplace_back(&position());
}

GraphicsLine::GraphicsLine(const Ptr &parent)
: GraphicsLine()
{
  setParent(parent);
}

GraphicsLine::GraphicsLine(const GraphicsItem *parent)
: GraphicsLine()
{
  setParent(parent);
}
