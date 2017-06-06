#ifndef GRAPHICSSQUARE_HPP
#define GRAPHICSSQUARE_HPP

#include "GraphicsItem.hpp"

/*!
 * \class GraphicsSquare
 * \brief Un carré
 * \ingroup graphics
 */

class GraphicsSquare : public GraphicsItem
{
public:
  explicit GraphicsSquare(GraphicsItem *parent = nullptr);

  GraphicsItem *topLeft() {
    return m_topLeft;
  }

  GraphicsItem *bottomRight() {
    return m_bottomRight;
  }

  GraphicsTypes type() const {
    return SquareType;
  }

protected:
  void meDraw(Canvas *canvas);
  bool meIsOver(const Point &absoluteP);

private:
  GraphicsItem *m_topLeft, *m_bottomRight;
};

#endif
