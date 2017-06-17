#include "../include/GraphicsImage.hpp"

GraphicsImage::GraphicsImage(GraphicsItem *parent)
: GraphicsItem(parent)
{}

void GraphicsImage::meDraw(Canvas *canvas)
{
  if (canvas)
    canvas->drawImage(m_image, position());
}

bool GraphicsImage::meIsOver(const Point &absoluteP)
{
  return position() < absoluteP && absoluteP < position() + Point(m_image.width(), m_image.height());
}
