#include "../include/MouseEvent.hpp"

MouseEvent::MouseEvent(const MouseButton button, const MouseState state, const Point &position)
: m_button(button), m_state(state), m_position(position)
{}

MouseEvent::MouseEvent(const EZEvent &event, const MouseState state)
: MouseEvent(MouseButton(event.mouseButton()), state, {event.mouseX(), event.mouseY()})
{}

std::ostream &MouseEvent::write(std::ostream &os) const
{
  return os << "button " << m_button << " state " << m_state << " position " << m_position;
}
