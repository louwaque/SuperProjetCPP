#include "../include/LineEdit.hpp"
#include <algorithm>
#include <KeyEvent.hpp>
#include <GraphicsBlinkAnimation.hpp>

LineEdit::LineEdit(GraphicsItem *parent)
: Widget(parent), m_text(nullptr), m_rectangle(nullptr), m_line(nullptr)
{
  m_text = new GraphicsText(this);

  m_rectangle = new GraphicsRectangle(this);
  m_rectangle->setHeight(m_text->font().height());

  m_line = new GraphicsLine(this);
  new GraphicsBlinkAnimation(m_line);

  setText("");
}

void LineEdit::setText(const std::string &text)
{
  m_text->setText(text);
  m_rectangle->setWidth(m_text->font().width()*std::max(int(m_text->text().size() + 1), 40));

  // m_line->first()->setRelative(Point(m_text->font().width()*std::max(int(m_text->text().size()), 0), 0));
  // m_line->second()->setRelative(Point(0, int(m_text->font().height())));
}

void LineEdit::meHandleEvent(const Event &event)
{
  if (event.type() == Event::KeyType && m_rectangle->hasFocus()) {
    const KeyEvent &key = dynamic_cast<const KeyEvent&>(event);
    if (key.state() == KeyEvent::KeyPressed) {
      std::string text = m_text->text();
      if (key.key() == KeyEvent::Key::BackSpace && !text.empty()) {
        text.pop_back();
        setText(text);
      } else {
        setText(text+key.keyString());
      }
    }
  }
}
