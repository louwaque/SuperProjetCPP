#include "../include/GraphicsAnimation.hpp"

GraphicsAnimation::GraphicsAnimation(const Id &parent)
: GraphicsItem(parent)
{}

GraphicsAnimation::GraphicsAnimation(const Ptr &parent)
: GraphicsItem(parent)
{}

GraphicsAnimation::GraphicsAnimation(const GraphicsItem *parent)
: GraphicsItem(parent)
{}
