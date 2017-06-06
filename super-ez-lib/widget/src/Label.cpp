#include "../include/Label.hpp"

Label::Label(GraphicsItem *parent)
: Widget(parent),
  m_text(nullptr)
{
  m_text = new GraphicsText(this);
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
    m_textChanged();

    //FIXME vraiment bof
    setWidth(minimumWidth() + 5);
    setHeight(minimumHeight() + 1);
  }
}

size_t Label::minimumWidth() const
{
  return m_text->font().width() * m_text->text().size();
}

size_t Label::minimumHeight() const
{
  return m_text->font().height();
}
