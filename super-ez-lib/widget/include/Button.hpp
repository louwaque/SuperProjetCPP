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
 * \brief Faire une action après un clic
 * \ingroup widget
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

  Button(const Ptr &parent = nullptr);
  Button(const std::string &text, const Ptr &parent = nullptr);

  inline std::string text() const { return m_label->text(); }
  inline void setText(const std::string &text) { m_label->setText(text); }

  size_t minimumWidth() const { return std::max(50ul, m_label->minimumWidth()); }
  size_t minimumHeight() const { return std::max(20ul, m_label->minimumHeight()); }

  /*!
   * \name Signaux
   */
  ///@{
  inline co_t clicked(const slot_t &subscriber) { return m_clicked.connect(subscriber); }
  ///@}

protected:
  void meHandleEvent(const Event &event);

private:
  std::shared_ptr<GraphicsRectangle> m_background;
  std::shared_ptr<Label> m_label;

  signal_t m_clicked;
};


#endif
