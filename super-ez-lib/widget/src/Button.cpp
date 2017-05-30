#include "../include/Button.hpp"
#include <algorithm>
#include <KeyEvent.hpp>
#include <GraphicsBlinkAnimation.hpp>
#include <iostream>
#include <MouseEvent.hpp>

Button::Button(GraphicsItem *parent)
: Widget(parent),m_text(nullptr),m_rectangle(nullptr)
{
  m_text = new GraphicsText(this);

  m_rectangle = new GraphicsRectangle(this);
  m_rectangle->setHeight(m_text->font().height());

  m_text->setText("");
}

Button::Button(const std::string &text, GraphicsItem *parent)
: Widget(parent),m_text(nullptr),
  m_rectangle(nullptr)
{
  m_text = new GraphicsText(this);
  m_rectangle = new GraphicsRectangle(this);
  m_rectangle->setHeight(m_text->font().height()*1.2);
  m_rectangle->setWidth(text.size()*6.2);
  m_text->setText(text);
}

void Button::setText(const std::string &text)
{
  m_text->setText(text);
  m_rectangle->setWidth(text.size());

  m_textChanged();
}

void Button::meHandleEvent(const Event &event)
{
  if(event.type() == Event::MouseType) {
    const MouseEvent &mouse = dynamic_cast<const MouseEvent&>(event);
    if (mouse.button() == MouseEvent::LeftButton && mouse.state() == MouseEvent::ButtonPressed){
      if (isOver(mouse.position()))
          m_clicked_left();

    }
    if (mouse.button() == MouseEvent::RightButton && mouse.state() == MouseEvent::ButtonPressed){
      if (isOver(mouse.position()))
          m_clicked_right();
  }
}
}
