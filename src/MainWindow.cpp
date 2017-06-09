#include "../include/MainWindow.hpp"

#include "ToolsWindow.hpp"
#include <LineEdit.hpp>
#include <Button.hpp>
#include <Layout.hpp>
#include <iostream>


MainWindow::MainWindow()
: Window(400, 400, "SuperProjetCPP"),
  m_scene(),
  m_tool(nullptr),
  currentItem(nullptr)
{
  m_tool = new ToolsWindow(&m_scene);
  m_tool->setHeight(height());
  m_tool->setWidth(150);
  m_tool->position().set(5, 5);
}

void MainWindow::drawEvent()
{
  m_scene.draw(&canvas());
}

void MainWindow::resizeEvent(const size_t width, const size_t height)
{
  m_tool->setWidth(std::min(150ul, width));
  m_tool->setHeight(height);
}

void MainWindow::updateEvent(const unsigned int time)
{
  m_scene.update(time);
  drawRequest();
}

void MainWindow::handleEvent(const Event &event)
{
  m_scene.handleEvent(event);
  drawRequest();
}
