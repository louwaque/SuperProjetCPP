#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <ez-lib/ez-draw++.hpp>

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
