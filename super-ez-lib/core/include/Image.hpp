#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <ez-lib/ez-draw++.hpp>
#include <memory>
#include <string>

#include "Point.hpp"
#include "Color.hpp"
#include "Pixel.hpp"

class Canvas;

/*!
 * \file Image.hpp
 * \brief Classe Image
 * \author Loïc Escales, Leo Sudreau
 * \version 0.1
 * \date 11 juin 2017
 */

 /*!
  * \class Image
  * \ingroup core
  * \brief Représente une image
  */

class Image
{
public:
  Image();
  Image(const size_t width, const size_t height);
  Image(const std::string &fileName);
  Image(const Image &image);

  void setFileName(const std::string &fileName);

  inline size_t width() const { return m_image->getWidth(); }
  inline size_t height() const { return m_image->getHeight(); }

  inline bool hasAlpha() const { return m_image->getAlpha(); }
  inline void setAlpha(const bool hasAlpha) { m_image->setAlpha(hasAlpha); }

  inline uint8_t opacity() const { return m_image->getOpacity(); }
  inline void setOpacity(const uint8_t opacity) { m_image->setOpacity(opacity); }

  Pixel pixel(const Point &position);
  const Pixel pixel(const Point &position) const;

  inline void fill(const Color &color, const uint8_t alpha) { m_image->fillRGBA(color.red(), color.green(), color.blue(), alpha); }
  inline void blend(const Image &src, const Point &position) { m_image->blend(*src.m_image, position.x(), position.y()); }
  inline void blend(const Image &src, const Point &position, const Point &source, const size_t width, const size_t height) { m_image->blendSubimage(*src.m_image, position.x(), position.y(), source.x(), source.y(), width, height); }

  Image extract(const Point &position, const size_t width, const size_t height) const { return m_image->extract(position.x(), position.y(), width, height); }
  Image verticalSymmetry() const { return m_image->verticalSymmetry(); }
  Image horizontalSymmetry() const { return m_image->horizontalSymmetry(); }
  Image scale(const double factor) const;

  static Image rainbow(const size_t width, const size_t height);

private:
  Image(EZImage *image);

private:
  std::shared_ptr<EZImage> m_image;

  friend Canvas;
};

#endif
