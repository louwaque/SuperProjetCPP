#ifndef GRAPHICSSQUARE_HPP
#define GRAPHICSSQUARE_HPP

#include "GraphicsItem.hpp"

class GraphicsSquare : public GraphicsItem
{
public:
  explicit GraphicsSquare(GraphicsItem *parent = nullptr);

  inline Point &topLeft() { return m_topLeft; }

  inline Point &bottomRight() { return m_bottomRight; }

  GraphicsTypes type() const {
    return SquareType;
  }

protected:
  void meDraw(Canvas *canvas);
  bool meIsOver(const Point &absoluteP);

private:
  static Point corrector(const Point &pos, const Point &corner);

private:
  Point m_topLeft, m_bottomRight;
};

#endif
