#ifndef GRAPHICSRECTANGLE_HPP
#define GRAPHICSRECTANGLE_HPP

#include "GraphicsItem.hpp"

class GraphicsRectangle : public GraphicsItem
{
public:
  explicit GraphicsRectangle(GraphicsItem *parent = nullptr);

  GraphicsItem *topLeft() {
    return m_topLeft;
  }

  GraphicsItem *bottomRight() {
    return m_bottomRight;
  }

  GraphicsTypes type() const {
    return RectangleType;
  }

protected:
  void meDraw(Canvas *canvas);
  bool meIsOver(const Point &absoluteP);

private:
  GraphicsItem *m_topLeft, *m_bottomRight;
};


#endif
