#ifndef GRAPHICSTRIANGLE_HPP
#define GRAPHICSTRIANGLE_HPP

#include "GraphicsShape.hpp"

class GraphicsTriangle : public GraphicsShape
{
public:
  explicit GraphicsTriangle(GraphicsItem *parent = nullptr);

  GraphicsItem *first() {
    return m_points[0];
  }

  GraphicsItem *second() {
    return m_points[1];
  }

  GraphicsItem *third() {
    return m_points[2];
  }

  GraphicsTypes type() const {
    return TriangleType;
  }
};

#endif
