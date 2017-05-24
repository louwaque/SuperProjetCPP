#ifndef KEYEVENT_HPP
#define KEYEVENT_HPP

#include "Event.hpp"
#include "../ez-lib/ez-draw++.hpp"

/*!
 * \file KeyEvent.hpp
 * \brief Classe KeyEvent
 * \author Loïc Escales, Leo Sudreau
 * \version 0.1
 * \date 24 mai 2017
 */

 /*!
  * \class MouseEvent
  * \brief Permet la gestion des evenements au clavier.
  *
  */

class KeyEvent : public Event {
  public:
   virtual EventType type(Event *Event);


  private:

};

#endif
