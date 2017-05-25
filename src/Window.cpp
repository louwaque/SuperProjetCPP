#include "../include/Window.hpp"

Window::Window(const size_t width, const size_t height, const std::string &title)
: EZWindow(width, height, title.c_str()), m_doubleBuffer(true), m_canvas(*this), m_updateFrequency(20), m_lastUpdate(Clock::now()), m_elapsedTime(0)
{
  EZWindow::setDoubleBuffer(m_doubleBuffer);
  EZWindow::startTimer(m_updateFrequency);
}

Window::~Window()
{
}

void Window::setDoubleBuffer(const bool active) {
  m_doubleBuffer = active;
  EZWindow::setDoubleBuffer(m_doubleBuffer);
}

void Window::buttonPress(int mouse_x, int mouse_y, int button)
{
  mousePressEvent({mouse_x, mouse_y}, MouseEvent::MouseButton(button));
  handleEvent(MouseEvent(EZWindow::currentEvent(), MouseEvent::ButtonPressed));
}

void Window::buttonRelease(int mouse_x, int mouse_y, int button)
{
  mouseReleaseEvent({mouse_x, mouse_y}, MouseEvent::MouseButton(button));
  handleEvent(MouseEvent(EZWindow::currentEvent(), MouseEvent::ButtonReleased));
}

void Window::motionNotify(int mouse_x, int mouse_y, int button)
{
  mouseMoveEvent({mouse_x, mouse_y}, MouseEvent::MouseButton(button));
  handleEvent(MouseEvent(EZWindow::currentEvent(), MouseEvent::MouseMoved));
}

void Window::keyPress(EZKeySym keysym)
{
  keyPressEvent(keysym);
  handleEvent(KeyEvent(EZWindow::currentEvent(), KeyEvent::KeyPressed));
}

void Window::keyRelease(EZKeySym keysym)
{
  keyReleaseEvent(keysym);
  handleEvent(KeyEvent(EZWindow::currentEvent(), KeyEvent::KeyReleased));
}

void Window::timerNotify()
{
  auto currentTime = Clock::now();
  m_elapsedTime += std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - m_lastUpdate).count();
  m_lastUpdate = currentTime;
  while (m_elapsedTime > m_updateFrequency) {
    updateEvent(m_updateFrequency);
    m_elapsedTime -= m_updateFrequency;
  }
  EZWindow::startTimer(m_updateFrequency);
}
