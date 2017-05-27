#include "../include/GraphicsAnchor.hpp"

GraphicsAnchor::GraphicsAnchor(GraphicsItem *parent)
: GraphicsPoint(parent)
{
  setColor(Color(Color::Red));
}

void GraphicsAnchor::setRelative(const Point &pos)
{
  if(parent())
    parent()->setRelative(pos);
}

void GraphicsAnchor::setAbsolute(const Point &pos)
{
  if (parent()) {
    if (parent()->parent())
      parent()->setRelative(pos - parent()->parent()->absolute());
    else
      parent()->setRelative(pos);
  }
}
