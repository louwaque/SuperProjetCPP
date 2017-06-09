#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <ez-lib/ez-draw++.hpp>
#include "Color.hpp"
#include "Point.hpp"
#include "Font.hpp"

class Window;

class Canvas
{
public:
  inline size_t width() const { return m_window.getWidth(); }

  inline size_t height() const { return m_window.getHeight(); }

  inline void clear() { m_window.clear(); }

  inline void setColor(const Color &color) { m_window.setColor(color.hexa()); }

  inline void setThick(const size_t thick = 1) { m_window.setThick(thick); }

  inline void setFont(const Font &font) { m_window.setFont(font.id()); }

  inline void drawPoint(const int x, const int y) { m_window.drawPoint(x, y); }

  inline void drawPoint(const Point &p) { m_window.drawPoint(p.x(), p.y()); }

  inline void drawLine(const int firstX, const int firstY, const int secondX, const int secondY) { m_window.drawLine(firstX, firstY, secondX, secondY); }

  inline void drawLine(const Point &first, const Point &second) { m_window.drawLine(first.x(), first.y(), second.x(), second.y()); }

  void drawRectangle(const int topLeftX, const int topLeftY, const int bottomRightX, const int bottomRightY, const bool isFill = false);

  inline void drawRectangle(const Point &topLeft, const Point &bottomRight, const bool isFill = false) { drawRectangle(topLeft.x(), topLeft.y(), bottomRight.x(), bottomRight.y(), isFill); }

  void drawCircle(const int topLeftX, const int topLeftY, const int bottomRightX, const int bottomRightY, const bool isFill = false);

  inline void drawCircle(const Point &topLeft, const Point &bottomRight, const bool isFill = false) { drawCircle(topLeft.x(), topLeft.y(), bottomRight.x(), bottomRight.y(), isFill); }

  void drawTriangle(const int firstX, const int firstY, const int secondX, const int secondY, const int thirdX, const int thirdY, const bool isFill = false);

  inline void drawTriangle(const Point &first, const Point &second, const Point &third, const bool isFill = false) { drawTriangle(first.x(), first.y(), second.x(), second.y(), third.x(), third.y(), isFill); }

  inline void drawText(const EZAlign align, const int x, const int y, const std::string &text) { m_window.drawText(align, x, y, text); }

  inline void drawText(const EZAlign align, const Point &pos, const std::string &text) { m_window.drawText(align, pos.x(), pos.y(), text); }

private:
  explicit Canvas(EZWindow &window);

  EZWindow &m_window;

  friend Window;
};

#endif
