#ifndef COLOR_HPP
#define COLOR_HPP

#include <cstdint>
#include <string>
#include "../ez-lib/ez-draw++.hpp"

class Color {
public:
  enum Colors : uint32_t {
    Black = 0x000000,
    White = 0xFFFFFF,
    Grey = 0x969696,
    Red = 0xFF0000,
    Green = 0x00FF00,
    Blue = 0x0000FF,
    Yellow = 0xFFFF00,
    Cyan = 0x00FFFF,
    Mangenta = 0xFF00FF
  };

  //pas super top
  explicit Color(const Colors color = Black);
  Color(const uint8_t red, const uint8_t green, const uint8_t blue);
  Color(const double hue, const double saturation, const double value);
  explicit Color(const ulong grey);

  uint8_t red() const {
    return (m_color & Red) >> 16;
  }

  void setRed(const uint8_t red);

  uint8_t green() const {
    return (m_color & Green) >> 8;
  }

  void setGreen(const uint8_t green);

  uint8_t blue() const {
    return m_color & Blue;
  }

  void setBlue(const uint8_t blue);

  double hue() const;

  void setHue(const double hue) {
    m_color = EZWindow::getHSV(hue, saturation(), value());
  }

  double saturation() const;

  void setSaturation(const double saturation) {
    m_color = EZWindow::getHSV(hue(), saturation, value());
  }

  double value() const;

  void setValue(const double value) {
    m_color = EZWindow::getHSV(hue(), saturation(), value);
  }

  uint32_t hexa() const {
    return m_color;
  }

  void setHexa(const uint32_t hexa) {
    m_color = hexa;
  }

  std::string hexaStr() const;

private:
  uint32_t m_color;
};

#endif
