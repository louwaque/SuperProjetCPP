#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <boost/locale.hpp>
#include <boost/core/noncopyable.hpp>
#include <ez-lib/ez-draw++.hpp>
#include "Color.hpp"
#include "Point.hpp"
#include "Font.hpp"
#include "Image.hpp"

class Window;

/*!
 * \class Canvas
 * \ingroup core
 * \brief Permet de dessiner dans une fenêtre
 */

class Canvas : private boost::noncopyable
{
public:
  typedef EZAlign TextAlign;

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

  inline void drawText(const TextAlign align, const int x, const int y, const std::string &text) { m_window.drawText(align, x, y, boost::locale::conv::from_utf(text, "Latin1")); }

  inline void drawText(const TextAlign align, const Point &pos, const std::string &text) { m_window.drawText(align, pos.x(), pos.y(), boost::locale::conv::from_utf(text, "Latin1")); }

  inline void drawImage(const Image &image, const Point &pos) { image.m_image->paint(m_window, pos.x(), pos.y()); }

  inline void drawImage(const Image &image, const Point &pos, const Point &source, const size_t width, const size_t height) { image.m_image->paintSubimage(m_window, pos.x(), pos.y(), source.x(), source.y(), width, height); }

private:
  explicit Canvas(EZWindow &window);

  EZWindow &m_window;

  friend Window;
};

#endif
