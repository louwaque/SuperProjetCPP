#ifndef GRAPHICSLINE_HPP
#define GRAPHICSLINE_HPP

#include "GraphicsShape.hpp"

class GraphicsLine : public GraphicsShape
{
public:
  explicit GraphicsLine(GraphicsItem *parent = nullptr);

  Point &first() {
    return m_points[0];
  }

  Point &second() {
    return m_points[1];
  }

  GraphicsTypes type() const {
    return LineType;
  }
};

#endif
