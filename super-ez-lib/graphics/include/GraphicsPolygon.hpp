#ifndef GRAPHICSPOLYGON_HPP
#define GRAPHICSPOLYGON_HPP

#include "GraphicsShape.hpp"

class GraphicsPolygon : public GraphicsShape
{
public:
  explicit GraphicsPolygon(GraphicsItem *parent = nullptr);

  GraphicsItem *newPoint();
  void popPoint();

  size_t nbPoints() const {
    return m_points.size();
  }

  void setNbPoints(const size_t nb);

  GraphicsTypes type() const {
    return PolygonType;
  }
};

#endif
