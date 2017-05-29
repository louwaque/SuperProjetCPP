#include "../include/Button.hpp"
#include <algorithm>
#include <KeyEvent.hpp>
#include <GraphicsBlinkAnimation.hpp>

Button::Button(GraphicsItem *parent)
:Widget(parent), m_text(nullptr),m_rectagle(nullptr)
{
  m_text = new GraphicsText(this);

  m_rectangle = new GraphicsRectangle(this);
  m_rectangle -> setHeight(m_text->font().height());

  setText("");
}

Button::Button(GraphicsItem *parent, std::string &text)
:Widget(parent),m_text(nullptr),m_rectangle(nullptr)
{
  m_text = new GraphicsText(this);

  m_rectangle = new GraphicsRectangle(this);
  m_rectangle -> setHeight(m_text->font().height());

  setText(text);
}

void Button::setText(const std:string &text)
{
  m_text -> setText(text);
  m_rectangle->setWidth(m_text->font().width()*std::max(int(m_text->text().size() + 1), 40));

  m_textChanged;
}
