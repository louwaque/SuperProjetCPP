#ifndef EVENT_HPP
#define EVENT_HPP

#include "../ez-lib/ez-draw++.hpp"

/*!
 * \file Event.hpp
 * \brief Classe Event
 * \author Loïc Escales, Leo Sudreau
 * \version 0.1
 * \date 24 mai 2017
 */

 /*!
  * \class Event
  * \brief Permet la gestion des evenements
  *
  */

class Event
{
public:


  enum EventType : uint32_t {
    UndefinedType = 0x00,
    MouseType = 0x01,
    KeyType = 0x02,
  };

  virtual EventType type(Event *Event) = 0;

private:



};

#endif
