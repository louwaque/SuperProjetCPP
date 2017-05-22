#ifndef GRAPHICSTEXT_HPP
#define GRAPHICSTEXT_HPP

/*!
 * \file GraphicsText.hpp
 * \brief Classe GraphicsText
 * \author Loïc Escales, Leo Sudreau
 * \version 0.1
 * \date 22 mai 2017
 */

#include "GraphicsItem.hpp"

/*!
 * \class GraphicsText
 * \brief Permet la creation de text
 *
 */

class GraphicsText : public GraphicsItem {

public:

  /*!
   * \brief Constructeur de GraphicsText par default.
   *
   * Crée une instance de GraphicsText sans texte.
   *
   */

  explicit GraphicsText(GraphicsItem *parent = nullptr);

  /*!
   * \brief Constructeur de GraphicsText avec un texte en paramètre.
   *
   * Crée une instance de GraphicsText avec un texte.
   *
   */

  explicit GraphicsText(const std::string &text, GraphicsItem *parent = nullptr);

  /*!
   * \brief Recupere le contenu de GraphicsText.
   *
   * /return texte de l'instance.
   *
   */

  inline std::string text() const { return m_text; }

  /*!
   * \brief Modifie le contenu de GraphicsText.
   *
   * /param text : nouveau texte de l'instance de GraphicsText.
   *
   */

  inline void setText(const std::string &text = "") { m_text = text; }

  inline EZAlign align() const { return m_align; }

  inline void setAlign(const EZAlign align = EZAlign::TL) {m_align = align; }

  /*!
   *  \brief recupere le type de l'instance courrante.
   *
   *  \return type de GraphicsText.
   */

  inline GraphicsTypes type() const { return TextType; }

protected:

  void meDraw(Canvas *canvas);
  bool meIsOver(const Point &absoluteP);

private:

  std::string m_text; /*!< Contenu de GraphicsText */
  //FIXME : Je veux mettre à la poubelle EZDraw
  EZAlign m_align;
};

#endif
