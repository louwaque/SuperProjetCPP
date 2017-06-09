#include "../include/LineEdit.hpp"
#include <algorithm>
#include <KeyEvent.hpp>
#include <GraphicsBlinkAnimation.hpp>

LineEdit::LineEdit(const Ptr &parent)
: Widget(parent),
  m_text(nullptr),
  m_rectangle(nullptr),
  m_line(nullptr)
{
  m_text = make<GraphicsText>(this);

  m_rectangle = make<GraphicsRectangle>(this);
  m_rectangle->setHeight(m_text->font().height());

  m_line = make<GraphicsLine>(this);

  make<GraphicsBlinkAnimation>(m_line);

  setText("");
}

void LineEdit::setText(const std::string &text)
{
  m_text->setText(text);
  m_rectangle->setWidth(m_text->font().width()*std::max(int(m_text->text().size() + 1), 40));

  m_line->first().setRelative(m_text->font().width()*std::max(int(m_text->text().size()), 0), 0);
  m_line->second().setRelative(m_text->font().width()*std::max(int(m_text->text().size()), 0), m_text->font().height());

  m_textChanged();
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
