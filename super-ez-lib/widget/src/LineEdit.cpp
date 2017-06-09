#include "../include/LineEdit.hpp"
#include <algorithm>
#include <KeyEvent.hpp>
#include <GraphicsBlinkAnimation.hpp>

LineEdit::LineEdit(GraphicsItem *parent)
: Widget(parent),
  m_text(),
  m_cursor(0),
  m_label(nullptr),
  m_rectangle(nullptr),
  m_line(nullptr)
{
  m_label = new Label(this);
  m_rectangle = new GraphicsRectangle(this);
  m_line = new GraphicsLine(this);
  new GraphicsBlinkAnimation(m_line);

  widthChanged([this]() {
    m_rectangle->setWidth(width());
    m_label->setWidth(width());
  });
  heightChanged([this]() {
    m_rectangle->setHeight(height());
    m_label->setHeight(height());
  });

  m_label->fontChanged([this]() {
    m_minimumHeightChanged();
  });

  setText("");
}

void LineEdit::setText(const std::string &text)
{
  if (m_text != text) {
    m_text = text;
    updateCursor();
    m_textChanged();
  }
}

size_t LineEdit::minimumWidth() const
{
  return 10;
}

size_t LineEdit::minimumHeight() const
{
  return m_label->font().height();
}

void LineEdit::meHandleEvent(const Event &event)
{
  if (event.type() == Event::KeyType && m_rectangle->hasFocus()) {
    const KeyEvent &key = dynamic_cast<const KeyEvent&>(event);
    if (key.state() == KeyEvent::KeyPressed) {
      std::string text = m_text;
      if (key.key() == KeyEvent::Key::BackSpace && !text.empty()) {
        text.pop_back();
        setText(text);
      } else {
        setText(text+key.keyString());
      }
    } else {
      if (key.key() == KeyEvent::Key::Right && m_cursor < m_text.size()) {
        ++m_cursor;
        updateCursor();
      } else if (key.key() == KeyEvent::Key::Left && m_cursor > 0) {
        --m_cursor;
        updateCursor();
      }
    }
  }
}

void LineEdit::updateCursor()
{
  if (m_text.size() > m_cursor)
    m_cursor = m_text.size();

  //FIXME utiliser substr
  m_label->setText(m_text);
  size_t x = m_label->font().width()*m_cursor;

  m_line->first().setRelative(x, 2);
  m_line->second().setRelative(x, m_label->font().height() - 2);
}
