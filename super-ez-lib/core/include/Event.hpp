#ifndef EVENT_HPP
#define EVENT_HPP

#include <iostream>
#include <ez-lib/ez-draw++.hpp>

/*!
 * \file Event.hpp
 * \brief Classe Event
 * \author Loïc Escales, Leo Sudreau
 * \version 0.1
 * \date 24 mai 2017
 */

 /*!
  * \class Event
  * \ingroup core
  * \brief Représente un événement
  */

class Event
{
public:
  enum EventType {
    MouseType,
    KeyType
  };

  Event() {};
  virtual ~Event() {};

  virtual EventType type() const = 0;

protected:
  virtual std::ostream &write(std::ostream &os) const = 0;

  friend std::ostream &operator<<(std::ostream &os, const Event &event);
};

#endif
