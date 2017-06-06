#include "../include/Button.hpp"
#include <MouseEvent.hpp>

Button::Button(GraphicsItem *parent)
: Widget(parent),
  m_label(nullptr)
{
  m_label = new Label(this);
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
    if (mouse.state() != MouseEvent::MouseMoved && isOver(mouse.position()))
      m_clicked();
  }
}
