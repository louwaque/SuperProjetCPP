#include "../include/GraphicsTriangle.hpp"

GraphicsTriangle::GraphicsTriangle(const Id &parent)
: GraphicsShape(parent)
{
  m_points.emplace_back(&position());
  m_points.emplace_back(&position());
  m_points.emplace_back(&position());
}

GraphicsTriangle::GraphicsTriangle(const Ptr &parent)
: GraphicsTriangle()
{
  setParent(parent);
}

GraphicsTriangle::GraphicsTriangle(const GraphicsItem *parent)
: GraphicsTriangle()
{
  setParent(parent);
}
