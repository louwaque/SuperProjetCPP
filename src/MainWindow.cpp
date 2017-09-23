#include "../include/MainWindow.hpp"

#include "ToolsWindow.hpp"
#include <LineEdit.hpp>
#include <Button.hpp>
#include "ConfigItem.hpp"

MainWindow::MainWindow()
: Window(800, 600, "SuperProjetCPP"),
  m_scene(nullptr),
  m_layout(nullptr),
  m_config(nullptr),
  currentItem(nullptr)
{
  m_scene = GraphicsItem::make<GraphicsItem>();

  m_layout = GraphicsItem::make<Layout>(m_scene.get());
  m_layout->setSpacing(10);
  m_layout->position().set(5, 5);

  m_layoutConfig = GraphicsItem::make<Layout>(m_scene.get());
  m_layoutConfig->position().setRelativeX(5);
  m_layoutConfig->setSpacing(5);

  auto tool = GraphicsItem::make<ToolsWindow>(m_layoutConfig);
  m_layout->push_back(tool);

  organize();
}

void MainWindow::drawEvent()
{
  m_scene->draw(&canvas());
}

void MainWindow::resizeEvent(const size_t width, const size_t height)
{
  organize();
}

void MainWindow::updateEvent(const Milliseconds &time)
{
  m_scene->update(time.count());
  drawRequest();
}

void MainWindow::handleEvent(const Event &event)
{
  m_scene->handleEvent(event);
  drawRequest();
}

void MainWindow::organize()
{
  //m_layout->setWidth(width() - m_layout->position().x());
  // ne marche pas bien, surement un prb de Layout...

  m_layoutConfig->setWidth(std::min(width()*0.30, 400.0));
  m_layoutConfig->position().setRelativeY(m_layout->height() + 25);
}
