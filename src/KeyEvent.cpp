#include "../include/KeyEvent.hpp"

KeyEvent::KeyEvent(const Key key, const KeyState state, const std::string &keyName, const std::string &keyString)
: m_key(key), m_state(state), m_keyName(keyName), m_keyString(keyString)
{}

KeyEvent::KeyEvent(const EZEvent &event, const KeyState state)
: KeyEvent(event.keySym(), state, event.keyName(), std::string(event.keyString(), event.keyCount()))
{}

std::ostream &KeyEvent::write(std::ostream &os) const
{
  return os << "key " << m_key << " state " << m_state << " name " << m_keyName << " string " << m_keyString;
}
