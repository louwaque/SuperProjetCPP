#ifndef GRAPHICSSHAPE_HPP
#define GRAPHICSSHAPE_HPP

#include "GraphicsItem.hpp"

class GraphicsShape : public GraphicsItem
{
public:
  explicit GraphicsShape(GraphicsItem *parent = nullptr);

  GraphicsTypes type() const {
    return ShapeType;
  }

protected:
  void meDraw(Canvas *canvas);

protected:
  GraphicsItemList m_points;
};

#endif
