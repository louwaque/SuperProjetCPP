#include "../include/Window.hpp"

Window::Window(const size_t width, const size_t height, const std::string &title)
: EZWindow(width, height, title.c_str()), m_doubleBuffer(true), m_canvas(*this)
{
  EZWindow::setDoubleBuffer(m_doubleBuffer);
}

Window::~Window()
{
}

void Window::setDoubleBuffer(const bool active) {
  m_doubleBuffer = active;
  EZWindow::setDoubleBuffer(m_doubleBuffer);
}
