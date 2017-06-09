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
  GraphicsBlinkAnimation *blink = new GraphicsBlinkAnimation(m_line);
  blink->setBlinkFrequency(200);

  widthChanged([this]() {
    m_rectangle->setWidth(width());
    m_label->setWidth(width());
  });
  heightChanged([this]() {
    m_rectangle->setHeight(height());
    m_label->setHeight(height());
  });

  m_label->fontChanged([this]() {
    m_minimumWidthChanged();
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
  return m_label->font().width()*5;
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
      if (key.key() == KeyEvent::Key::BackSpace) {
          if (!text.empty() && m_cursor > 0) {
          text.erase(m_cursor - 1, 1);
          --m_cursor;
        }
      } else if (key.key() == KeyEvent::Key::Delete) {
        if (m_cursor < text.size()) {
          text.erase(m_cursor, 1);
        }
      } else if (key.key() == KeyEvent::Key::Return) {
        m_accepted();
      } else if (!key.keyString().empty()) {
        text.insert(m_cursor, key.keyString());
        ++m_cursor;
      } else if (key.key() == KeyEvent::Key::Right && m_cursor < m_text.size()) {
        ++m_cursor;
      } else if (key.key() == KeyEvent::Key::Left && m_cursor > 0) {
        --m_cursor;
      }
      setText(text);
      updateCursor();
    }
  }
}

void LineEdit::updateCursor()
{
  if (m_cursor > m_text.size())
    m_cursor = m_text.size();

  size_t nbDisplayableLetters = m_rectangle->width()/m_label->font().width();

  size_t pos = 0, count = nbDisplayableLetters;

  size_t x = 0;

  if (m_text.size() > nbDisplayableLetters) {
    if (m_cursor < nbDisplayableLetters/2) {
      pos = 0;
      x = m_cursor;
    } else if (m_text.size() - m_cursor < nbDisplayableLetters/2) {
      pos = m_text.size() - nbDisplayableLetters;
      x = nbDisplayableLetters - (m_text.size() - m_cursor);
    } else {
      pos = m_cursor - nbDisplayableLetters/2;
      x = nbDisplayableLetters/2;
    }
    m_label->setText(m_text.substr(pos, count));
  } else {
    m_label->setText(m_text);
    x = m_cursor;
  }

  x *= m_label->font().width();

  m_line->first().setRelative(x, 2);
  m_line->second().setRelative(x, m_rectangle->height() - 2);
}
