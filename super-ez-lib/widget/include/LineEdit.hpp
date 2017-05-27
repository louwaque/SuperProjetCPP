#ifndef LINEEDIT_HPP
#define LINEEDIT_HPP

#include "Widget.hpp"
#include <GraphicsRectangle.hpp>
#include <GraphicsText.hpp>
#include <GraphicsLine.hpp>

class LineEdit : public Widget
{
public:
  explicit LineEdit(GraphicsItem *parent = nullptr);

  inline std::string text() const { return m_text->text(); }
  void setText(const std::string &text);

  inline boost::signals2::connection textChanged(const signal_t::slot_type &subscriber) { return m_textChanged.connect(subscriber); }

protected:
  void meHandleEvent(const Event &event);

private:
  GraphicsText *m_text;
  GraphicsRectangle *m_rectangle;
  GraphicsLine *m_line;

  signal_t m_textChanged;
};

#endif
