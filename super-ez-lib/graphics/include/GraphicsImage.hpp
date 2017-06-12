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
  explicit GraphicsImage(const Id &parent = boost::uuids::nil_generator()());
  explicit GraphicsImage(const Ptr &parent);
  explicit GraphicsImage(const GraphicsItem *parent);

  const Image &image() const { return m_image; }
  Image &image() { return m_image; }

protected:
  void meDraw(Canvas *canvas);
  bool meIsOver(const Point &absoluteP);

private:
  Image m_image;
};

#endif
