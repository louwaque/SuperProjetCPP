#include "../include/Color.hpp"
#include <sstream>

Color::Color(const Colors color)
: m_color(color)
{}

Color::Color(const uint32_t hexa)
: m_color(hexa)
{}

Color::Color(const std::string &hexa)
: m_color(0)
{
  setHexaStr(hexa);
}

Color::Color(const uint8_t red, const uint8_t green, const uint8_t blue)
: m_color(red << 16 | green << 8 | blue)
{}

Color::Color(const double hue, const double saturation, const double value)
: m_color(EZWindow::getHSV(hue, saturation, value))
{}

Color::Color(const ulong grey)
: m_color(EZWindow::getGrey(grey))
{}

void Color::setRed(const uint8_t red)
{
  m_color &= ~Red;
  m_color |= (red << 16);
}

void Color::setGreen(const uint8_t green)
{
  m_color &= ~Green;
  m_color |= (green << 8);
}


void Color::setBlue(const uint8_t blue)
{
  m_color &= ~Blue;
  m_color |= blue;
}

double Color::hue() const
{
  double h(0), r(red()/255.0), g(green()/255.0), b(blue()/255.0);
  double max = r > g ? std::max(r, b) : std::max(g, b);
  double min = r < g ? std::min(r, b) : std::min(g, b);

  if (max == min) {
    h = 0;
  } else if (max == r) {
    h = (60 * ((g-b)/(max-min)) + 360);
    while (h > 360)
      h -= 360;
  } else if (max == g) {
    h = 60 * ((b-r)/(max-min)) + 120;
  } else if (max == b) {
    h = 60 * ((r-g)/(max-min)) + 240;
  }

  return h;
}

double Color::saturation() const
{
  double s(0), r(red()/255.0), g(green()/255.0), b(blue()/255.0);
  double max = r > g ? std::max(r, b) : std::max(g, b);

  if (max == 0) {
    s = 0;
  } else {
    double min = r < g ? std::min(r, b) : std::min(g, b);
    s = 1 - min/max;
  }

  return s;
}

double Color::value() const
{
  double r(red()/255.0), g(green()/255.0), b(blue()/255.0);
  double max = r > g ? std::max(r, b) : std::max(g, b);

  return max;
}

std::string Color::hexaStr() const
{
  std::stringstream buf;
  buf << "0x" << std::hex << m_color;
  return buf.str();
}

void Color::setHexaStr(const std::string &hexa)
{
  std::stringstream buf(hexa);
  buf >> std::hex >> m_color;
}
