#ifndef GRAPHICSELLIPSE_HPP
#define GRAPHICSELLIPSE_HPP

#include "GraphicsShape.hpp"

/*!
 * \class GraphicsEllipse
 * \brief Une ellipse
 * \ingroup graphics
 */

class GraphicsEllipse : public GraphicsShape
{
public:
  explicit GraphicsEllipse(GraphicsItem *parent = nullptr);

  inline const Point &center() const { return m_points[0]; }
  inline Point &center() { return m_points[0]; }

  //FIXME change the name
  inline const Point &radius() const { return m_points[1]; }
  inline Point &radius() { return m_points[1]; }

protected:
  void meDraw(Canvas *canvas);
  bool meIsOver(const Point &absoluteP);
};

#endif
