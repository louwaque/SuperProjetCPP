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
  void updateEvent(const Milliseconds &time);
  void handleEvent(const Event &event);
  void createRectangle();

private:
  void organize();

private:
  GraphicsItem::Ptr m_scene;
  std::shared_ptr<Layout> m_layout, m_layoutConfig;
  std::shared_ptr<Widget> m_config;
  GraphicsItem *currentItem;
};

#endif
