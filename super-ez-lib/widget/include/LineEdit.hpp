#ifndef LINEEDIT_HPP
#define LINEEDIT_HPP

#include "Widget.hpp"
#include <GraphicsRectangle.hpp>
#include <GraphicsText.hpp>
#include <GraphicsLine.hpp>

/*!
 * \class LineEdit
 * \brief Saisir du texte
 * \ingroup widget
 */

class LineEdit : public Widget
{
public:
  explicit LineEdit(GraphicsItem *parent = nullptr);

  inline std::string text() const { return m_text->text(); }
  void setText(const std::string &text);

  /*!
   * \name Signaux
   */
  ///@{
  inline co_t textChanged(const slot_t &subscriber) { return m_textChanged.connect(subscriber); }
  ///@}

protected:
  void meHandleEvent(const Event &event);

private:
  GraphicsText *m_text;
  GraphicsRectangle *m_rectangle;
  GraphicsLine *m_line;

  signal_t m_textChanged;
};

#endif
