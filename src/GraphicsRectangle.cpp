#include "../include/GraphicsRectangle.hpp"
#include "../include/GraphicsPoint.hpp"
#include "../include/GraphicsAnchor.hpp"

GraphicsRectangle::GraphicsRectangle(GraphicsItem *parent)
: GraphicsItem(parent), m_topLeft(nullptr), m_bottomRight(nullptr)
{
  m_topLeft = new GraphicsAnchor(this);
  m_bottomRight = new GraphicsPoint(this);
}

void GraphicsRectangle::meDraw(Canvas *canvas)
{
  if (canvas)
    canvas->drawRectangle(topLeft()->absolute(), bottomRight()->absolute(), isFill());
}

bool GraphicsRectangle::meIsOver(const Point &absoluteP)
{
  return topLeft()->absolute() < absoluteP and absoluteP < bottomRight()->absolute();
}
