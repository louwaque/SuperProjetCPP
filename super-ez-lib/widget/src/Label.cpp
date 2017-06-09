#include "../include/Label.hpp"

Label::Label(const Id &parent)
: Widget(parent),
  m_text(nullptr)
{
  m_text = make<GraphicsText>(this);

  widthChanged(boost::bind(&Label::alignText, this));
  heightChanged(boost::bind(&Label::alignText, this));

  alignText();
}

Label::Label(const Ptr &parent)
: Label()
{
  setParent(parent);
}

Label::Label(const GraphicsItem *parent)
: Label()
{
  setParent(parent);
}

Label::Label(const std::string &text, const Id &parent)
: Label(parent)
{
  setText(text);
}

Label::Label(const std::string &text, const Ptr &parent)
: Label(text)
{
  setParent(parent);
}

Label::Label(const std::string &text, const GraphicsItem *parent)
: Label(text)
{
  setParent(parent);
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
  m_text->position().set(position().x()+width()/2.0, position().y()+height()/2.0);
}
