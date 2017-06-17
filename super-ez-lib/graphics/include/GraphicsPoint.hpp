#ifndef GRAPHICSPOINT_HPP
#define GRAPHICSPOINT_HPP

#include "GraphicsItem.hpp"

/*!
 * \class GraphicsPoint
 * \brief Un point
 * \ingroup graphics
 */

class GraphicsPoint : public GraphicsItem
{
public:
  explicit GraphicsPoint(GraphicsItem *parent = nullptr);
  GraphicsPoint(const Point &pos, GraphicsItem *parent = nullptr);

  unsigned int radius() const
  {
    return m_radius;
  }

  void setRadius(unsigned int radius)
  {
    m_radius = radius;
  }

protected:
  void meDraw(Canvas *canvas);
  void meHandleEvent(const Event &event);
  bool meIsOver(const Point &absoluteP);

private:
  unsigned int m_radius;
};

#endif
