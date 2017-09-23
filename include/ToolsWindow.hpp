#ifndef TOOLSWINDOW_HPP
#define TOOLSWINDOW_HPP

/*!
 * \file ToolsWindow.hpp
 * \brief Classe ToolsWindow
 * \author Loïc Escales, Leo Sudreau
 * \version 0.1
 * \date 24 mai 2017
 */

#include <Layout.hpp>

/*!
 * \class ToolsWindow
 * \brief Barre d'outils pour créer des formes
 */

class ToolsWindow : public Widget
{
public:
  ToolsWindow(const std::shared_ptr<Layout> &layoutConfig, GraphicsItem *parent = nullptr);

  size_t minimumWidth() const;
  size_t minimumHeight() const;

protected:
  void meDraw(Canvas* canvas);

private:
  void configItem(GraphicsItem::Ptr item);

private:
  std::shared_ptr<Layout> m_layout, m_layoutConfig;
  Point m_spawnPoint;
};

#endif
