#ifndef PIXEL_HPP
#define PIXEL_HPP

#include <ez-lib/ez-draw++.hpp>
#include <memory>

#include "Point.hpp"
#include "Color.hpp"

class Image;

/*!
 * \file Pixel.hpp
 * \brief Classe Pixel
 * \author Loïc Escales, Leo Sudreau
 * \version 0.1
 * \date 11 juin 2017
 */

 /*!
  * \class Pixel
  * \ingroup core
  * \brief Représente un pixel dans une Image
  */

class Pixel
{
public:
  Color color() const;
  void setColor(const Color &color);

  uint8_t alpha() const;
  void setAlpha(const uint8_t alpha);

  Point position() const { return m_position; }

private:
  Pixel(std::shared_ptr<EZImage> image, const Point &position);

  EZPixel pixel();
  const EZPixel pixel() const;

  friend Image;

private:
  std::shared_ptr<EZImage> m_image;
  const Point m_position;
};

#endif
