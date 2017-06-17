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
#include <memory>
#include <boost/core/noncopyable.hpp>

/**
 * \defgroup core Core
 * \brief Classes pour créer une application graphique
 */

/*!
 * \class Application
 * \ingroup core
 * \brief Classe Application
 *
 * Cette classe est nécessaire à l'utilisation de certaines classes du module core ( éléments graphiques ).
 * Une seule instance de cette classe doit être créé.
 */

class Application : private boost::noncopyable
{
public:
  Application();

  inline void exec() { m_ezdraw->mainLoop(); }

  inline static void quit() { EZDraw::quit(); }

  inline bool autoQuit() const { return m_autoQuit; }
  void setAutoQuit(const bool enable);

private:
  static bool m_instantiated;
  std::unique_ptr<EZDraw> m_ezdraw;
  bool m_autoQuit;
};

#endif
