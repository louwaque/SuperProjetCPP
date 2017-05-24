#ifndef TOOLSWINDOWS_HPP
#define TOOLSWINDOWS_HPP

/*!
 * \file GraphicsItem.hpp
 * \brief Classe GraphicsItem
 * \author Loïc Escales, Leo Sudreau
 * \version 0.1
 * \date 24 mai 2017
 */

#include "GraphicsItem.hpp"

/*!
 * \class ToolsWindows
 * \brief Permet la creation d'un fenetre d'édition des formes
 *
 */

class ToolsWindows : public GraphicsItem {

  public:

    /*!
     * \brief Constructeur de ToolsWindows par default.
     *
     * Crée une instance de GraphicsText sans Contenu
     *
     */

    ToolsWindows(GraphicsItem *parent = nullptr);

  private:

};

#endif
