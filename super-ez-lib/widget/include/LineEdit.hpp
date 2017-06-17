#ifndef LINEEDIT_HPP
#define LINEEDIT_HPP

#include "Label.hpp"
#include <GraphicsRectangle.hpp>
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

  inline std::string text() const { return m_text; }
  void setText(const std::string &text);

  inline bool editable() const { return m_editable; }
  inline void setEditable(const bool editable) { m_editable = editable; }

  size_t minimumWidth() const;
  size_t minimumHeight() const;

  /*!
   * \name Signaux
   */
  ///@{
  inline co_t textChanged(const slot_t &subscriber) { return m_textChanged.connect(subscriber); }
  inline co_t accepted(const slot_t &subscriber) { return m_accepted.connect(subscriber); }
  ///@}

protected:
  void meUpdate(const unsigned int time);
  void meHandleEvent(const Event &event);

private:
  void updateCursor();

private:
  const size_t m_margin;

  std::string m_text;
  size_t m_cursor;
  bool m_editable;

  std::shared_ptr<Label> m_label;
  std::shared_ptr<GraphicsRectangle> m_rectangle;
  std::shared_ptr<GraphicsLine> m_line;

  signal_t m_textChanged;
  signal_t m_accepted;
};

#endif
