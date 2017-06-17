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
  explicit GraphicsCircle(GraphicsItem *parent = nullptr);

  inline const Point &center() const { return m_points[0]; }
  inline Point &center() { return m_points[0]; }

  //FIXME utilise un point ou on fait un propriété radius
  //      et pour modifier la taille on laisse MainWindow se débrouiller ?
  inline const Point &radiusPt() const { return m_points[1]; }
  inline Point &radiusPt() { return m_points[1]; }

  int radius() const;
  void setRadius(const int radius);

protected:
  void meDraw(Canvas *canvas);
  bool meIsOver(const Point &absoluteP);
};

#endif
