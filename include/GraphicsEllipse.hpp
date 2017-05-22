#ifndef GRAPHICSELLIPSE_HPP
#define GRAPHICSELLIPSE_HPP

#include "GraphicsShape.hpp"

class GraphicsEllipse : public GraphicsShape
{
public:
  explicit GraphicsEllipse(GraphicsItem *parent = nullptr);

  GraphicsItem *center() {
    return m_points[0];
  }

  //change the name ?
  GraphicsItem *radius() {
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
