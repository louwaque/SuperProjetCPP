#ifndef GRAPHICSPOLYGON_HPP
#define GRAPHICSPOLYGON_HPP

#include "GraphicsShape.hpp"

class GraphicsPolygon : public GraphicsShape
{
public:
  explicit GraphicsPolygon(GraphicsItem *parent = nullptr);

  Point &newPoint();
  void popPoint();

  inline size_t nbPoints() const { return m_points.size(); }
  void setNbPoints(const size_t nb);

  GraphicsTypes type() const {
    return PolygonType;
  }
};

#endif
