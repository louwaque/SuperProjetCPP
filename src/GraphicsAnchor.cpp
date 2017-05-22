#include "../include/GraphicsAnchor.hpp"

GraphicsAnchor::GraphicsAnchor(GraphicsItem *parent)
: GraphicsPoint(parent)
{
  setColor(Color(Color::Red));
}

void GraphicsAnchor::setAnchor(const Point &anchor)
{
  if(parent())
    parent()->setAnchor(anchor);
}

void GraphicsAnchor::setAbsolute(const Point &pos)
{
  if (parent()) {
    if (parent()->parent())
      parent()->setAnchor(pos - parent()->parent()->absolute());
    else
      parent()->setAnchor(pos);
  }
}
