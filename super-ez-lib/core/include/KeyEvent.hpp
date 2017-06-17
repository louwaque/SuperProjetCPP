#ifndef KEYEVENT_HPP
#define KEYEVENT_HPP

#include <string>
#include "Event.hpp"

class Window;

/*!
 * \file KeyEvent.hpp
 * \brief Classe KeyEvent
 * \author Loïc Escales, Leo Sudreau
 * \version 0.1
 * \date 24 mai 2017
 */

 /*!
  * \class KeyEvent
  * \ingroup core
  * \brief Événement émit par le clavier
  */

class KeyEvent : public Event
{
public:
  typedef EZKeySym Key;

  enum KeyState {
    KeyPressed,
    KeyReleased
  };

  KeyEvent(const Key key, const KeyState state, const std::string &keyName, const std::string &keyString);

  inline Key key() const { return m_key; }
  inline KeyState state() const { return m_state; }
  inline std::string keyName() const { return m_keyName; }
  inline std::string keyString() const { return m_keyString; }

  EventType type() const { return KeyType; }

protected:
  std::ostream &write(std::ostream &os) const;

private:
  KeyEvent(const EZEvent &event, const KeyState state);

private:
  Key m_key;
  KeyState m_state;
  std::string m_keyName;
  std::string m_keyString;

  friend Window;
};

#endif
