#ifndef GRAPHICSCIRCLE_HPP
#define GRAPHICSCIRCLE_HPP

#include "GraphicsShape.hpp"

/*!
 * \class GraphicsCircle
 * \brief Un cercle
 * \ingroup graphics
 */

class GraphicsCircle : public GraphicsShape
{
public:
  explicit GraphicsCircle(GraphicsItem *parent);

  GraphicsItem *center() {
    return m_points[0];
  }

  GraphicsItem *radius() {
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
