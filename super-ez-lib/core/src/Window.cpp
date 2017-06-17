#include "../include/Window.hpp"

Window::Window(const size_t width, const size_t height, const std::string &title)
: EZWindow(width, height, title.c_str()),
  m_doubleBuffer(true),
  m_canvas(*this),
  m_updateFrequency(20),
  m_lastUpdate(Clock::now()),
  m_elapsedTime(0)
{
  EZWindow::setDoubleBuffer(m_doubleBuffer);
  EZWindow::startTimer(m_updateFrequency.count());
}

Window::~Window()
{}

void Window::setDoubleBuffer(const bool active)
{
  m_doubleBuffer = active;
  EZWindow::setDoubleBuffer(m_doubleBuffer);
}

void Window::timerNotify()
{
  auto currentTime = Clock::now();
  m_elapsedTime += std::chrono::duration_cast<Milliseconds>(currentTime - m_lastUpdate);
  m_lastUpdate = currentTime;
  while (m_elapsedTime > m_updateFrequency) {
    updateEvent(m_updateFrequency);
    m_elapsedTime -= m_updateFrequency;
  }
  EZWindow::startTimer(m_updateFrequency.count());
}
