#ifndef MOUSEEVENT_HPP
#define MOUSEEVENT_HPP

#include "Event.hpp"
#include "Point.hpp"

/*!
 * \file MouseEvent.hpp
 * \brief Classe MouseEvent
 * \author Loïc Escales, Leo Sudreau
 * \version 0.1
 * \date 24 mai 2017
 */

 /*!
  * \class MouseEvent
  * \brief Permet la gestion des evenements à la souri.
  *
  */

class MouseEvent : public Event
{
public:
  enum MouseButton : uint {
    LeftButton = 1,
    MiddleButton = 2,
    RightButton = 3,
    UpWheel = 4,
    DownWheel = 5,
    LeftWheel = 6,
    RightWheel = 7
  };

  enum MouseState {
    ButtonPressed,
    ButtonReleased,
    MouseMoved
  };

  MouseEvent(const MouseButton button, const MouseState state, const Point &position);
  explicit MouseEvent(const EZEvent &event, const MouseState state);

  inline MouseButton button() const { return m_button; }
  inline MouseState state() const { return m_state; }
  inline Point position() const { return m_position; }

  inline EventType type() const { return MouseType; };

protected:
  std::ostream &write(std::ostream &os) const;

private:
  MouseButton m_button;
  MouseState m_state;
  Point m_position;
};

#endif
