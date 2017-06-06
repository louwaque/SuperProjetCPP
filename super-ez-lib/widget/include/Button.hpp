#ifndef BUTTON_HPP
#define BUTTON_HPP

/*!
 * \file Button.hpp
 * \brief Classe Button
 * \author Loïc Escales, Leo Sudreau
 * \version 0.1
 * \date 29 mai 2017
 */

#include "Label.hpp"

/*!
 * \class Button
 * \brief Permet la creation d'un boutton
 *
 */

class Button : public Widget
{
public:

  /*!
   * \brief Constructeur de la classe Button
   *
   * Creer un bouton avec le text donnée en paramètre
   *
   */

  Button(GraphicsItem *parent = nullptr);
  Button(const std::string &text, GraphicsItem *parent = nullptr);

  inline const Label &label() const { return *m_label; }
  inline Label &label() { return *m_label; }

  size_t minimumWidth() const { return m_label->minimumWidth(); }
  size_t minimumHeight() const { return m_label->minimumHeight(); }

  inline co_t clicked(const slot_t &subscriber) { return m_clicked.connect(subscriber); }

protected:
  void meHandleEvent(const Event &event);

private:
  Label *m_label;

  signal_t m_clicked;
};


#endif