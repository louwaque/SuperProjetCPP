#ifndef GRAPHICSELLIPSE_HPP
#define GRAPHICSELLIPSE_HPP

#include "GraphicsShape.hpp"

class GraphicsEllipse : public GraphicsShape
{
public:
  explicit GraphicsEllipse(GraphicsItem *parent = nullptr);

  Point &center() {
    return m_points[0];
  }

  //FIXME change the name ?
  Point &radius() {
    return m_points[1];
  }

  GraphicsTypes type() const {
    return EllipseType;
  }

protected:
  void meDraw(Canvas *canvas);
  bool meIsOver(const Point &absoluteP);
};

#endif
