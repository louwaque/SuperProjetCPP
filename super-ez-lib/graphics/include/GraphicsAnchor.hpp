#ifndef GRAPHICSANCHOR_HPP
#define GRAPHICSANCHOR_HPP

#include "GraphicsPoint.hpp"

class GraphicsAnchor : public GraphicsPoint
{
public:
  explicit GraphicsAnchor(GraphicsItem *parent = nullptr);

  void setAnchor(const Point &anchor);
  void setAbsolute(const Point &pos);

  GraphicsTypes type() const {
    return PointType;//FIXME AnchorType;
  }
};

#endif
