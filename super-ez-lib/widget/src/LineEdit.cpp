#include "../include/LineEdit.hpp"
#include <algorithm>
#include <KeyEvent.hpp>
#include <GraphicsBlinkAnimation.hpp>
#include <UTF8Helper.hpp>

LineEdit::LineEdit(GraphicsItem *parent)
: Widget(parent),
  m_margin(5),
  m_text(),
  m_cursor(0),
  m_editable(true),
  m_label(nullptr),
  m_rectangle(nullptr),
  m_line(nullptr)
{
  m_label = make<Label>(this);
  m_label->position().setRelative(m_margin, m_margin);

  m_rectangle = make<GraphicsRectangle>(this);

  m_line = make<GraphicsLine>(this);

  auto blink = make<GraphicsBlinkAnimation>(m_line.get());
  blink->setBlinkFrequency(200);

  widthChanged([this]() {
    m_rectangle->setWidth(width());
    m_label->setWidth(width() - m_margin * 2);
    updateCursor();
  });
  heightChanged([this]() {
    m_rectangle->setHeight(height());
    m_label->setHeight(height() - m_margin * 2);
    updateCursor();
  });

  m_label->fontChanged([this]() {
    m_minimumWidthChanged();
    m_minimumHeightChanged();
  });
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
  return m_label->font().width() + m_margin * 2;
}

size_t LineEdit::minimumHeight() const
{
  return m_label->font().height() + m_margin * 2;
}

void LineEdit::meUpdate(const unsigned int time)
{
  m_line->setEnable(m_rectangle->hasFocus());
  if (!m_rectangle->hasFocus())
    m_line->setVisible(false);
}

void LineEdit::meHandleEvent(const Event &event)
{
  if (event.type() == Event::KeyType && m_rectangle->hasFocus()) {
    const KeyEvent &key = dynamic_cast<const KeyEvent&>(event);
    if (key.state() == KeyEvent::KeyPressed) {
      std::string text = m_text;
      if (key.key() == KeyEvent::Key::BackSpace) {
          if (!text.empty() && m_cursor > 0 && m_editable) {
          UTF8Helper::erase(text, m_cursor - 1, 1);
          --m_cursor;
          setText(text);
        }
      } else if (key.key() == KeyEvent::Key::Delete) {
        if (m_cursor < UTF8Helper::size(text) && m_editable) {
          UTF8Helper::erase(text, m_cursor, 1);
          setText(text);
        }
      } else if (key.key() == KeyEvent::Key::Return) {
        m_accepted();
      } else if (!key.keyString().empty() && m_editable) {
        UTF8Helper::insert(text, m_cursor, key.keyString());
        ++m_cursor;
        setText(text);
      } else if (key.key() == KeyEvent::Key::Right && m_cursor < UTF8Helper::size(m_text)) {
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
  size_t m_textSize = UTF8Helper::size(m_text);
  if (m_cursor > m_textSize)
    m_cursor = m_textSize;

  size_t nbDisplayableLetters = m_label->width()/m_label->font().width();

  size_t pos = 0, count = nbDisplayableLetters;

  size_t x = 0;

  if (m_textSize > nbDisplayableLetters) {
    if (m_cursor < nbDisplayableLetters/2) {
      pos = 0;
      x = m_cursor;
    } else if (m_textSize - m_cursor < nbDisplayableLetters/2) {
      pos = m_textSize - nbDisplayableLetters;
      x = nbDisplayableLetters - (m_textSize - m_cursor);
    } else {
      pos = m_cursor - nbDisplayableLetters/2;
      x = nbDisplayableLetters/2;
    }
    m_label->setText(UTF8Helper::substr(m_text, pos, count));
  } else {
    m_label->setText(m_text);
    x = m_cursor;
  }

  x *= m_label->font().width();

  m_line->first().setRelative(x + m_margin, m_margin);
  m_line->second().setRelative(x + m_margin, m_rectangle->height() - m_margin);
}
