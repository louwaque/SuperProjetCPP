#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <chrono>
#include "../ez-lib/ez-draw++.hpp"
#include "Point.hpp"
#include "Canvas.hpp"
#include "MouseEvent.hpp"
#include "KeyEvent.hpp"

class Window : private EZWindow
{
  typedef std::chrono::high_resolution_clock Clock;

public:
  Window(const size_t width = 400, const size_t height = 400, const std::string &title = "");
  virtual ~Window();

  bool doubleBuffer() const {
    return m_doubleBuffer;
  }

  void setDoubleBuffer(const bool active = true);

  size_t width() const {
    return EZWindow::getWidth();
  }

  void setWidth(const size_t width) {
    EZWindow::setWidth(width);
  }

  size_t height() const {
    return EZWindow::getHeight();
  }

  void setHeight(const size_t height) {
    EZWindow::setHeight(height);
  }

  void resize(const size_t width, const size_t height) {
    EZWindow::setWidthHeight(width, height);
  }

  bool isVisible() const {
    return EZWindow::isVisible();
  }

  void setVisible(const bool visible) {
    EZWindow::setVisible(visible);
  }

  void drawRequest() {
    EZWindow::sendExpose();
  }

  Canvas &canvas() {
    return m_canvas;
  }

protected:
  //souri en même temps que touche clavier
  virtual void drawEvent() {}
  virtual void resizeEvent(const size_t with, const size_t height) {}
  virtual void closeEvent() {}
  virtual void mousePressEvent(const Point &mousePos, const MouseEvent::MouseButton button) {}
  virtual void mouseReleaseEvent(const Point &mousePos, const MouseEvent::MouseButton button) {}
  virtual void mouseMoveEvent(const Point &mousePos, const MouseEvent::MouseButton button) {}
  virtual void keyPressEvent(const KeyEvent::Key key) {}
  virtual void keyReleaseEvent(const KeyEvent::Key key) {}
  virtual void handleEvent(const Event &event) {}
  virtual void updateEvent(const unsigned int time) {}

private:
  void expose() { drawEvent(); }
  void configureNotify(int width, int height) { resizeEvent(width, height); }
  void close() { closeEvent(); }
  void buttonPress(int mouse_x, int mouse_y, int button);
  void buttonRelease(int mouse_x, int mouse_y, int button);
  void motionNotify(int mouse_x, int mouse_y, int button);
  void keyPress(EZKeySym keysym);
  void keyRelease(EZKeySym keysym);
  void timerNotify();

private:
  bool m_doubleBuffer;
  Canvas m_canvas;
  unsigned int m_updateFrequency;
  Clock::time_point m_lastUpdate;
  unsigned int m_elapsedTime;
};

#endif
