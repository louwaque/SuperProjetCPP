#include "../include/Label.hpp"
#include <UTF8Helper.hpp>

Label::Label(GraphicsItem *parent)
: Widget(parent),
  m_text(nullptr),
  m_textSize(0),
  m_align(LabelAlign::Left)
{
  m_text = make<GraphicsText>(this);

  widthChanged(boost::bind(&Label::alignText, this));
  heightChanged(boost::bind(&Label::alignText, this));

  alignText();
}

Label::Label(const std::string &text, GraphicsItem *parent)
: Label(parent)
{
  setText(text);
}

void Label::setText(const std::string &text)
{
  if (m_text->text() != text) {
    m_text->setText(text);
    m_textSize = UTF8Helper::size(m_text->text());
    m_textChanged();
    m_minimumWidthChanged();

    //FIXME utiliser une sorte de padding ou margin ?
    // setWidth(minimumWidth() + 10);
    // setHeight(minimumHeight() + 2);
  }
}

void Label::setFont(const Font &font)
{
  if (m_text->font() != font) {
    m_text->setFont(font);
    m_fontChanged();
    m_minimumWidthChanged();
    m_minimumHeightChanged();
  }
}

size_t Label::minimumWidth() const
{
  return m_text->font().width() * m_textSize;
}

size_t Label::minimumHeight() const
{
  return m_text->font().height();
}

void Label::alignText()
{
  if (m_align == LabelAlign::Left) {
    m_text->setAlign(Canvas::TextAlign::ML);
    m_text->position().setRelative(0, height()/2.0);
  } else if (m_align == LabelAlign::Right) {
    m_text->setAlign(Canvas::TextAlign::MR);
    m_text->position().setRelative(width(), height()/2.0);
  } else if (m_align == LabelAlign::Center) {
    m_text->setAlign(Canvas::TextAlign::MC);
    m_text->position().setRelative(width()/2.0, height()/2.0);
  }
}
