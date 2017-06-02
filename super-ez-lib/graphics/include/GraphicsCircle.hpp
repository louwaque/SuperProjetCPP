#ifndef GRAPHICSCIRCLE_HPP
#define GRAPHICSCIRCLE_HPP

#include "GraphicsShape.hpp"

class GraphicsCircle : public GraphicsShape
{
public:
  explicit GraphicsCircle(GraphicsItem *parent);

  Point &center() {
    return m_points[0];
  }

  //FIXME utilise un point ou on fait un propriété radius
  //      et pour modifier la taille on laisse MainWindow se débrouiller ?
  Point &radius() {
    return m_points[1];
  }

  GraphicsTypes type() const {
    return CircleType;
  }

protected:
  void meDraw(Canvas *canvas);
  bool meIsOver(const Point &absoluteP);
};

#endif
