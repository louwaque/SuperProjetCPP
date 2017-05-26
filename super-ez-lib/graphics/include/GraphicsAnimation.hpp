#ifndef GRAPHICSANIMATION_HPP
#define GRAPHICSANIMATION_HPP

#include "GraphicsItem.hpp"

class GraphicsAnimation : public GraphicsItem
{
public:
  explicit GraphicsAnimation(GraphicsItem *parent = nullptr);

  GraphicsTypes type() const { return AnimationType; }
};

#endif
