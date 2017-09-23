#include "../include/Pixel.hpp"

Pixel::Pixel(std::shared_ptr<EZImage> image, const Point &position)
: m_image(image),
  m_position(position)
{}

Color Pixel::color() const
{
  const EZPixel p = pixel();
  return Color(uint8_t(p.getRed()), p.getGreen(), p.getBlue());
}

void Pixel::setColor(const Color &color)
{
  EZPixel p = pixel();
  p.setRed(color.red());
  p.setGreen(color.green());
  p.setBlue(color.blue());
}

uint8_t Pixel::alpha() const
{
  return pixel().getAlpha();
}

void Pixel::setAlpha(const uint8_t alpha)
{
  pixel().setAlpha(alpha);
}

EZPixel Pixel::pixel()
{
  if (m_image)
    return m_image->getPixel(m_position.x(), m_position.y());
  else
    throw std::runtime_error("Pixel::pixel image ptr is null");
}

const EZPixel Pixel::pixel() const
{
  if (m_image)
    return m_image->getPixel(m_position.x(), m_position.y());
  else
    throw std::runtime_error("Pixel::pixel const image ptr is null");
}
