#include "../include/GraphicsImage.hpp"

GraphicsImage::GraphicsImage(const Id &parent)
: GraphicsItem(parent)
{}

GraphicsImage::GraphicsImage(const Ptr &parent)
: GraphicsImage()
{
  setParent(parent);
}

GraphicsImage::GraphicsImage(const GraphicsItem *parent)
: GraphicsImage()
{
  setParent(parent);
}

void GraphicsImage::meDraw(Canvas *canvas)
{
  if (canvas)
    canvas->drawImage(m_image, position());
}

bool GraphicsImage::meIsOver(const Point &absoluteP)
{
  return position() < absoluteP && absoluteP < position() + Point(m_image.width(), m_image.height());
}
