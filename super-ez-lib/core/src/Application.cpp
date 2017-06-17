#include "../include/Application.hpp"

bool Application::m_instantiated = false;

Application::Application()
: m_ezdraw(nullptr),
  m_autoQuit(true)
{
  if (m_instantiated)
    throw std::runtime_error("Application is already instantiated");
  else
    m_instantiated = true;

  m_ezdraw = std::make_unique<EZDraw>();

  m_ezdraw->setAutoQuit(m_autoQuit);
}

void Application::setAutoQuit(const bool enable)
{
  m_autoQuit = enable;
  m_ezdraw->setAutoQuit(m_autoQuit);
}
