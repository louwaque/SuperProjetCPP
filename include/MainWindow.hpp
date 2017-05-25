#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "Window.hpp"
#include "GraphicsItem.hpp"

class MainWindow : public Window
{
public:
  MainWindow();

protected:
  void drawEvent();
  void mousePressEvent(const Point &mousePos, const MouseEvent::MouseButton button);
  void mouseReleaseEvent(const Point &mousePos, const MouseEvent::MouseButton button);
  void mouseMoveEvent(const Point &mousePos, const MouseEvent::MouseButton button);
  void updateEvent(const unsigned int time);
  void handleEvent(const Event &event);

private:
  GraphicsItem m_scene;
  GraphicsItem *currentItem;
};

#endif
