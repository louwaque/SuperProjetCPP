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
    ToolsWindow(GraphicsItem *parent = nullptr);

private:
  Layout *m_layout;
};

#endif
