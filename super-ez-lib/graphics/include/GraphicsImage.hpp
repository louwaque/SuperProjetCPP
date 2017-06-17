#ifndef GRAPHICSIMAGE_HPP
#define GRAPHICSIMAGE_HPP

#include "GraphicsItem.hpp"
#include "Image.hpp"

/*!
 * \class GraphicsImage
 * \brief Une image
 * \ingroup graphics
 */

class GraphicsImage : public GraphicsItem
{
public:
  explicit GraphicsImage(GraphicsItem *parent = nullptr);

  const Image &image() const { return m_image; }
  Image &image() { return m_image; }

protected:
  void meDraw(Canvas *canvas);
  bool meIsOver(const Point &absoluteP);

private:
  Image m_image;
};

#endif
