#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <Window.hpp>
#include <Widget.hpp>
#include <Layout.hpp>

class MainWindow : public Window
{
public:
  MainWindow();

protected:
  void drawEvent();
  void resizeEvent(const size_t width, const size_t height);
  void updateEvent(const unsigned int time);
  void handleEvent(const Event &event);
  void createRectangle();

private:
  void organize();

private:
  GraphicsItem m_scene;
  Layout *m_layout;
  Widget *m_config;
  GraphicsItem *currentItem;
};

#endif
