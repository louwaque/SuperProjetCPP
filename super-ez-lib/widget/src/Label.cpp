#include "../include/Label.hpp"

Label::Label(GraphicsItem *parent)
: Widget(parent),
  m_text(nullptr)
{
  m_text = new GraphicsText(this);

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
    m_textChanged();

    //FIXME utiliser une sorte de padding ou margin ?
    setWidth(minimumWidth() + 10);
    setHeight(minimumHeight() + 2);
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

void Label::alignText()
{
  m_text->setAlign(EZAlign::MC);
  m_text->setAbsolute(Point(absolute().x()+width()/2.0, absolute().y()+height()/2.0));
}
