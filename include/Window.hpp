#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include "../ez-lib/ez-draw++.hpp"
#include "Point.hpp"
#include "Canvas.hpp"

class Window
{
public:
  typedef EZKeySym Key;

  enum MouseButton : int {
    LeftButton,
    RightButton
  };

  Window(const size_t width = 400, const size_t height = 400, const std::string &title = "");
  virtual ~Window();

  bool doubleBuffer() const {
    return m_doubleBuffer;
  }

  void setDoubleBuffer(const bool active = true);

  size_t width() const {
    return m_window.getWidth();
  }

  void setWidth(const size_t width) {
    m_window.setWidth(width);
  }

  size_t height() const {
    return m_window.getHeight();
  }

  void setHeight(const size_t height) {
    return m_window.setHeight(height);
  }

  void resize(const size_t width, const size_t height) {
    m_window.setWidthHeight(width, height);
  }

  bool isVisible() const {
    return m_window.isVisible();
  }

  void setVisible(const bool visible) {
    m_window.setVisible(visible);
  }

  void drawRequest() {
    m_window.sendExpose();
  }

  Canvas &canvas() {
    return m_canvas;
  }

protected:
  //souri en même temps que touche clavier
  virtual void drawEvent();
  virtual void resizeEvent(const size_t with, const size_t height);
  virtual void closeEvent();
  virtual void mousePressEvent(const Point &mousePos, const MouseButton button);
  virtual void mouseReleaseEvent(const Point &mousePos, const MouseButton button);
  virtual void mouseMoveEvent(const Point &mousePos, const MouseButton button);
  virtual void keyPressEvent(const Key key);
  virtual void keyReleaseEvent(const Key key);

private:
  class WindowProxy : public EZWindow
  {
  public:
    explicit WindowProxy(Window &window, int width = 320, int height = 200, const char *title = "")
    : EZWindow(width, height, title), m_window(window) {}

    virtual void expose() { m_window.drawEvent(); }
    virtual void configureNotify(int width, int height) { m_window.resizeEvent(width, height); };
    virtual void close() { m_window.closeEvent(); }
    virtual void buttonPress(int mouse_x, int mouse_y, int button) { m_window.mousePressEvent({mouse_x, mouse_y}, MouseButton(button)); }
    virtual void buttonRelease(int mouse_x, int mouse_y, int button) { m_window.mouseReleaseEvent({mouse_x, mouse_y}, MouseButton(button)); };
    virtual void motionNotify(int mouse_x, int mouse_y, int button) { m_window.mouseMoveEvent({mouse_x, mouse_y}, MouseButton(button)); };
    virtual void keyPress(EZKeySym keysym) { m_window.keyPressEvent(keysym); }
    virtual void keyRelease(EZKeySym keysym) { m_window.keyReleaseEvent(keysym); };

  private:
    Window &m_window;
  };

private:
  WindowProxy m_window;
  bool m_doubleBuffer;
  Canvas m_canvas;
};

#endif
