#include "../include/Image.hpp"

Image::Image()
: Image(0, 0)
{}

Image::Image(const size_t width, const size_t height)
: m_image(std::make_shared<EZImage>(width, height))
{}

Image::Image(const std::string &fileName)
: m_image(std::make_shared<EZImage>(fileName.c_str()))
{}

Image::Image(const Image &image)
: m_image(std::make_shared<EZImage>(*image.m_image))
{}

Image::Image(EZImage *image)
: m_image(std::make_shared<EZImage>(*image))
{}

void Image::setFileName(const std::string &fileName)
{
  m_image = std::make_shared<EZImage>(fileName.c_str());
}

Pixel Image::pixel(const Point &position)
{
  return Pixel(m_image, position);
}

const Pixel Image::pixel(const Point &position) const
{
  return pixel(position);
}

Image Image::scale(const double factor) const
{
  if (factor > 0)
    return m_image->scale(factor);
  else
    throw std::runtime_error("Image::scale a negative factor is prohibited");
}

Image Image::rainbow(const size_t width, const size_t height)
{
  Image image(width, height);
  for (int x = 0; x < image.width(); ++x) {
    for (int y = 0; y < image.height(); ++y) {
      auto p = image.pixel({x, y});
      auto c = p.color();
      c.setValue(1);
      c.setSaturation(1);
      c.setHue(y/double(image.height())*360.0);
      p.setColor(c);
    }
  }
  return image;
}
