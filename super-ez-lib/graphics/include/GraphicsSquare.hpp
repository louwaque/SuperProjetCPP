#ifndef GRAPHICSSQUARE_HPP
#define GRAPHICSSQUARE_HPP

#include "GraphicsItem.hpp"

/*!
 * \class GraphicsSquare
 * \brief Un carré
 * \ingroup graphics
 */

//FIXME utiliser GraphicsShape
class GraphicsSquare : public GraphicsItem
{
public:
  explicit GraphicsSquare(GraphicsItem *parent = nullptr);

  inline const Point &topLeft() const { return m_topLeft; }
  inline Point &topLeft() { return m_topLeft; }

  inline const Point &bottomRight() const { return m_bottomRight; }
  inline Point &bottomRight() { return m_bottomRight; }

protected:
  void meDraw(Canvas *canvas);
  bool meIsOver(const Point &absoluteP);

private:
  static Point corrector(const Point &pos, const Point &corner);

private:
  Point m_topLeft, m_bottomRight;
};

#endif
