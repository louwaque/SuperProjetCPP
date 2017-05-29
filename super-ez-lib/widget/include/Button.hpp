#ifndef BUTTON_HPP
#define BUTTON_HPP

/*!
 * \file Button.hpp
 * \brief Classe Button
 * \author Loïc Escales, Leo Sudreau
 * \version 0.1
 * \date 29 mai 2017
 */

#include "Widget.hpp"
#include <GraphicsRectangle.hpp>
#include <GraphicsText.hpp>
#include <string>

/*!
 * \class Button
 * \brief Permet la creation d'un boutton
 *
 */

class Button : public Widget {

public:

  /*!
   * \brief Constructeur de la classe Button
   *
   * Creer un bouton avec le text donnée en paramètre
   *
   */

  Button(GraphicsItem *parent = nullptr);
  Button(const std::string &text, GraphicsItem *parent = nullptr);

  inline std::string text() const { return m_text->text(); }
  void setText(const std::string &text);

  inline co_t textChanged(const slot_t &subscriber) { return m_textChanged.connect(subscriber); }


protected:

  void meHandleEvent(const Event &event);

private:

  GraphicsText *m_text;
  GraphicsRectangle *m_rectangle;
  signal_t m_textChanged;

};


#endif
