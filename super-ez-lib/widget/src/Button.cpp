#include "../include/Button.hpp"
#include <MouseEvent.hpp>
#include <iostream>

Button::Button(const Id &parent)
: Widget(parent),
  m_background(nullptr),
  m_label(nullptr)
{
  m_background = make<GraphicsRectangle>(this);
  m_background->setColor(Color::Green);

  m_label = make<Label>(this);
  m_label->setAlign(Label::LabelAlign::Center);

  widthChanged([this]() {
    m_background->setWidth(width());
    m_label->setWidth(width());
  });
  heightChanged([this]() {
    m_background->setHeight(height());
    m_label->setHeight(height());
  });

  m_label->minimumWidthChanged([this](){
    m_minimumWidthChanged();
  });
  m_label->minimumHeightChanged([this](){
    m_minimumHeightChanged();
  });
}

Button::Button(const Ptr &parent)
: Button()
{
  setParent(parent);
}

Button::Button(const GraphicsItem *parent)
: Button()
{
  setParent(parent);
}

Button::Button(const std::string &text, const Id &parent)
: Button(parent)
{
  setText(text);
}

Button::Button(const std::string &text, const Ptr &parent)
: Button(text)
{
  setParent(parent);
}

Button::Button(const std::string &text, const GraphicsItem *parent)
: Button(text)
{
  setParent(parent);
}

size_t Button::minimumWidth() const
{
  return m_label->minimumWidth();
}

size_t Button::minimumHeight() const
{
  return m_label->minimumHeight();
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
