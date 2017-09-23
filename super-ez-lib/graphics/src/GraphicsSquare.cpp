#include "../include/GraphicsSquare.hpp"
#include <boost/bind.hpp>
#include <cmath>

GraphicsSquare::GraphicsSquare(GraphicsItem *parent)
: GraphicsItem(parent),
  m_topLeft({boost::bind(&GraphicsSquare::corrector, _1, boost::cref(m_bottomRight))}, &position()),
  m_bottomRight({boost::bind(&GraphicsSquare::corrector, _1, boost::cref(m_topLeft))}, &position())
{}

void GraphicsSquare::meDraw(Canvas *canvas)
{
  if (canvas)
    canvas->drawRectangle(topLeft(), bottomRight(), isFill());
}

bool GraphicsSquare::meIsOver(const Point &absoluteP)
{
  return topLeft() < absoluteP and absoluteP < bottomRight();
}

Point GraphicsSquare::corrector(const Point &pos, const Point &corner)
{
  Point diffP(pos - corner), res;
  if (abs(diffP.x()) >= abs(diffP.y()))
    res = {diffP.x(), diffP.x()};
  else
    res = {diffP.y(), diffP.y()};
  return corner + res;
}
