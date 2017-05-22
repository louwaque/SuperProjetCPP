#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "Window.hpp"
#include "GraphicsItem.hpp"

class MainWindow : public Window
{
public:
  MainWindow();

  void drawEvent();
  void mousePressEvent(const Point &mousePos, const MouseButton button);
  void mouseReleaseEvent(const Point &mousePos, const MouseButton button);
  void mouseMoveEvent(const Point &mousePos, const MouseButton button);

private:
  GraphicsItem m_scene;
  GraphicsItem *currentItem;
};

#endif
