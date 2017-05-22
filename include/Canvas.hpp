#ifndef CANVAS_HPP
#define CANVAS_HPP

#include "../ez-lib/ez-draw++.hpp"
#include "Point.hpp"

class Canvas {
public:
  explicit Canvas(EZWindow &window);

  unsigned int width() const {
    return m_window.getWidth();
  }

  unsigned int height() const {
    return m_window.getHeight();
  }

  void clear() const {
    m_window.clear();
  }

  void setColor(const EZColor color) {
    m_window.setColor(color);
  }

  void setThick(const unsigned int thick = 1) {
    m_window.setThick(thick);
  }

  void drawPoint(const int x, const int y) {
    m_window.drawPoint(x, y);
  }

  void drawPoint(const Point &p) {
    m_window.drawPoint(p.x(), p.y());
  }

  void drawLine(const int firstX, const int firstY, const int secondX, const int secondY) {
    m_window.drawLine(firstX, firstY, secondX, secondY);
  }

  void drawLine(const Point &first, const Point &second) {
    m_window.drawLine(first.x(), first.y(), second.x(), second.y());
  }

  void drawRectangle(const int topLeftX, const int topLeftY, const int bottomRightX, const int bottomRightY, const bool isFill = false);

  void drawRectangle(const Point &topLeft, const Point &bottomRight, const bool isFill = false) {
    drawRectangle(topLeft.x(), topLeft.y(), bottomRight.x(), bottomRight.y(), isFill);
  }

  void drawCircle(const int topLeftX, const int topLeftY, const int bottomRightX, const int bottomRightY, const bool isFill = false);

  void drawCircle(const Point &topLeft, const Point &bottomRight, const bool isFill = false) {
    drawCircle(topLeft.x(), topLeft.y(), bottomRight.x(), bottomRight.y(), isFill);
  }

  void drawTriangle(const int firstX, const int firstY, const int secondX, const int secondY, const int thirdX, const int thirdY, const bool isFill = false);

  void drawTriangle(const Point &first, const Point &second, const Point &third, const bool isFill = false) {
    drawTriangle(first.x(), first.y(), second.x(), second.y(), third.x(), third.y(), isFill);
  }

  void drawText(const EZAlign align, const int x, const int y, const std::string &text) {
    m_window.drawText(align, x, y, text);
  }

  void drawText(const EZAlign align, const Point &pos, const std::string &text) {
    m_window.drawText(align, pos.x(), pos.y(), text);
  }

private:
  EZWindow &m_window;
};

#endif
