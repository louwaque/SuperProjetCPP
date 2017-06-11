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
