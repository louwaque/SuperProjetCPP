#include "../include/Button.hpp"
#include <MouseEvent.hpp>
#include <iostream>

Button::Button(GraphicsItem *parent)
: Widget(parent),
  m_background(nullptr),
  m_label(nullptr)
{
  m_background = new GraphicsRectangle(this);
  m_background->setColor(Color(Color::Green));

  m_label = new Label(this);

  widthChanged([this]() {
    m_background->setWidth(width());
    m_label->setWidth(width());
  });
  heightChanged([this]() {
    m_background->setHeight(height());
    m_label->setHeight(height());
  });

  m_label->widthChanged([this]() {
    setWidth(m_label->width());
  });
  m_label->heightChanged([this]() {
    setHeight(m_label->height());
  });
}

Button::Button(const std::string &text, GraphicsItem *parent)
: Button(parent)
{
  m_label->setText(text);
}

void Button::meHandleEvent(const Event &event)
{
  if(event.type() == Event::MouseType) {
    const MouseEvent &mouse = dynamic_cast<const MouseEvent&>(event);
    if (isOver(mouse.position())) {
      if (mouse.state() == MouseEvent::ButtonPressed) {
        m_background->setFill(true);
      } else {
        m_background->setFill(false);
      }
      if (mouse.state() == MouseEvent::ButtonReleased)
        m_clicked();
    }
  }
}
