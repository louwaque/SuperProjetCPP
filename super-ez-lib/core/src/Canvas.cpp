#include "../include/Canvas.hpp"

Canvas::Canvas(EZWindow &window)
: m_window(window)
{}

void Canvas::drawRectangle(const int topLeftX, const int topLeftY, const int bottomRightX, const int bottomRightY, const bool isFill)
{
  if (isFill)
    m_window.fillRectangle(topLeftX, topLeftY, bottomRightX, bottomRightY);

  m_window.drawRectangle(topLeftX, topLeftY, bottomRightX, bottomRightY);
}

void Canvas::drawCircle(const int topLeftX, const int topLeftY, const int bottomRightX, const int bottomRightY, const bool isFill)
{
  if (isFill)
    m_window.fillCircle(topLeftX, topLeftY, bottomRightX, bottomRightY);

  m_window.drawCircle(topLeftX, topLeftY, bottomRightX, bottomRightY);
}

void Canvas::drawTriangle(const int firstX, const int firstY, const int secondX, const int secondY, const int thirdX, const int thirdY, const bool isFill)
{
  if (isFill)
    m_window.fillTriangle(firstX, firstY, secondX, secondY, thirdX, thirdY);

  m_window.drawTriangle(firstX, firstY, secondX, secondY, thirdX, thirdY);
}
