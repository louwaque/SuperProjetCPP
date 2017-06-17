#include "../include/GraphicsPoint.hpp"
#include <MouseEvent.hpp>

GraphicsPoint::GraphicsPoint(GraphicsItem *parent)
: GraphicsItem(parent),
  m_radius(5)
{}

GraphicsPoint::GraphicsPoint(const Point &pos, GraphicsItem *parent)
: GraphicsPoint(parent)
{
  position().set(pos);
}

void GraphicsPoint::meDraw(Canvas *canvas)
{
  if (canvas)
    canvas->drawCircle(position() - m_radius, position() + m_radius, hasFocus());
}

void GraphicsPoint::meHandleEvent(const Event &event)
{
  if (event.type() == Event::MouseType) {
    const MouseEvent &mouse = dynamic_cast<const MouseEvent&>(event);
    if (mouse.button() == MouseEvent::LeftButton &&
        mouse.state() == MouseEvent::MouseMoved &&
        hasFocus())
        position().set(mouse.position());
  }
}

bool GraphicsPoint::meIsOver(const Point &absoluteP)
{
  return position() - m_radius < absoluteP and absoluteP < position() + m_radius;
}
