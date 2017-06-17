#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <chrono>
#include <ez-lib/ez-draw++.hpp>
#include "Canvas.hpp"
#include "MouseEvent.hpp"
#include "KeyEvent.hpp"

/*!
 * \class Window
 * \ingroup core
 * \brief Représente une fenêtre
 */

class Window : private EZWindow
{
  typedef std::chrono::high_resolution_clock Clock;

public:
  Window(const size_t width = 400, const size_t height = 400, const std::string &title = "");
  virtual ~Window();

  inline bool doubleBuffer() const { return m_doubleBuffer; }

  void setDoubleBuffer(const bool active = true);

  inline size_t width() const { return EZWindow::getWidth(); }

  inline void setWidth(const size_t width) { EZWindow::setWidth(width); }

  inline size_t height() const { return EZWindow::getHeight(); }

  inline void setHeight(const size_t height) { EZWindow::setHeight(height); }

  inline void resize(const size_t width, const size_t height) { EZWindow::setWidthHeight(width, height); }

  inline bool isVisible() const { return EZWindow::isVisible(); }

  inline void setVisible(const bool visible) { EZWindow::setVisible(visible); }

  inline void drawRequest() { EZWindow::sendExpose(); }

  inline Canvas &canvas() { return m_canvas; }

protected:
  typedef std::chrono::milliseconds Milliseconds;

protected:
  virtual void drawEvent() {}
  virtual void resizeEvent(const size_t width, const size_t height) {}
  virtual void closeEvent() {}
  virtual void handleEvent(const Event &event) {}
  virtual void updateEvent(const Milliseconds &time) {}

private:
  inline void expose() { drawEvent(); }
  inline void configureNotify(int width, int height) { resizeEvent(width, height); }
  inline void close() { closeEvent(); }
  inline void buttonPress(int mouse_x, int mouse_y, int button) { handleEvent(MouseEvent(EZWindow::currentEvent(), MouseEvent::ButtonPressed)); }
  inline void buttonRelease(int mouse_x, int mouse_y, int button) { handleEvent(MouseEvent(EZWindow::currentEvent(), MouseEvent::ButtonReleased)); }
  inline void motionNotify(int mouse_x, int mouse_y, int button) { handleEvent(MouseEvent(EZWindow::currentEvent(), MouseEvent::MouseMoved)); }
  inline void keyPress(EZKeySym keysym) { handleEvent(KeyEvent(EZWindow::currentEvent(), KeyEvent::KeyPressed)); }
  inline void keyRelease(EZKeySym keysym) { handleEvent(KeyEvent(EZWindow::currentEvent(), KeyEvent::KeyReleased)); }
  void timerNotify();

private:
  bool m_doubleBuffer;
  Canvas m_canvas;
  Milliseconds m_updateFrequency;
  Clock::time_point m_lastUpdate;
  Milliseconds m_elapsedTime;
};

#endif
