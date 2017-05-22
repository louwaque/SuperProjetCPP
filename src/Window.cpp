#include "../include/Window.hpp"

Window::Window(const size_t width, const size_t height, const std::string &title)
: m_window(*this, width, height, title.c_str()), m_doubleBuffer(true), m_canvas(m_window)
{
  m_window.setDoubleBuffer(m_doubleBuffer);
}

Window::~Window()
{
}

void Window::setDoubleBuffer(const bool active) {
  m_doubleBuffer = active;
  m_window.setDoubleBuffer(m_doubleBuffer);
}
