#include "../include/GraphicsAnimation.hpp"

GraphicsAnimation::GraphicsAnimation(const Id &parent)
: GraphicsItem(parent)
{}

GraphicsAnimation::GraphicsAnimation(const Ptr &parent)
: GraphicsAnimation()
{
  setParent(parent);
}

GraphicsAnimation::GraphicsAnimation(const GraphicsItem *parent)
: GraphicsAnimation()
{
  setParent(parent);
}
