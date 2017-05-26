#include "../include/Application.hpp"

bool Application::m_instantiated = false;

Application::Application()
: m_ezdraw(nullptr), m_autoQuit(false)
{
  if (m_instantiated)
    throw std::runtime_error("Application is already instantiated");
  else
    m_instantiated = true;

  m_ezdraw = new EZDraw();
  m_ezdraw->setAutoQuit(m_autoQuit);
}

Application::~Application()
{
  delete m_ezdraw;
}

void Application::setAutoQuit(const bool enable)
{
  m_autoQuit = enable;
  m_ezdraw->setAutoQuit(m_autoQuit);
}
