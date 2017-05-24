#ifndef MOUSEEVENT_HPP
#define MOUSEEVENT_HPP

#include "Event.hpp"
#include "../ez-lib/ez-draw++.hpp"

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

class MouseEvent : public Event {

  public:

    virtual EventType type(Event *Event);

  private:

};

#endif
