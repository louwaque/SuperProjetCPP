#include "../include/GraphicsRectangle.hpp"

GraphicsRectangle::GraphicsRectangle(const Id &parent)
: GraphicsItem(parent),
  m_topLeft(&position()),
  m_bottomRight(&position())
{}

GraphicsRectangle::GraphicsRectangle(const Ptr &parent)
: GraphicsRectangle()
{
  setParent(parent);
}

GraphicsRectangle::GraphicsRectangle(const GraphicsItem *parent)
: GraphicsRectangle()
{
  setParent(parent);
}

void GraphicsRectangle::meDraw(Canvas *canvas)
{
  if (canvas)
    canvas->drawRectangle(m_topLeft, m_bottomRight, isFill());
}

bool GraphicsRectangle::meIsOver(const Point &absoluteP)
{
  return m_topLeft < absoluteP and absoluteP < m_bottomRight;
}

void GraphicsRectangle::setWidth(const size_t width)
{
  m_bottomRight.setRelativeX(width);
}

void GraphicsRectangle::setHeight(const size_t height)
{
  m_bottomRight.setRelativeY(height);
}
