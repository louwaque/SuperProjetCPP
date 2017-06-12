#ifndef APPLICATION_HPP
#define APPLICATION_HPP

/*!
 * \file Application.hpp
 * \brief Classe GraphicsApplication
 * \author Loïc Escales, Leo Sudreau
 * \version 0.1
 * \date 12 juin 2017
 */

#include <ez-lib/ez-draw++.hpp>

/*!
 * \class Application
 * \brief Classe Apllication
 * \ingroup core
 *
 *  Cette classe est nécessaire à l'utilisation de certaines du module core ( éléments graphiques ).
 *  Q'une seul instance de cette classe doit être crée.
 *
 *
 */

class Application
{
public:
  Application();
  ~Application();
  Application(const Application &src) = delete;

  inline void exec() { m_ezdraw->mainLoop(); }

  inline static void quit() { EZDraw::quit(); }

  inline bool autoQuit() const { return m_autoQuit; }
  void setAutoQuit(const bool enable);

private:
  static bool m_instantiated;
  EZDraw *m_ezdraw;
  bool m_autoQuit;
};

#endif
