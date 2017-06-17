#include "../include/GraphicsBlinkAnimation.hpp"

GraphicsBlinkAnimation::GraphicsBlinkAnimation(GraphicsItem *parent)
: GraphicsAnimation(parent),
  m_blinkFrequency(1000),
  m_elapsedTime(0),
  m_becomeColor(Color(Color::White)),
  m_parentColor(Color(Color::White)),
  m_colorApplied(false),
  m_becomeInvisible(true)
{}

GraphicsBlinkAnimation::GraphicsBlinkAnimation(const Color &color, GraphicsItem *parent)
: GraphicsBlinkAnimation(parent)
{
  m_becomeColor = color;
  m_becomeInvisible = false;
}

void GraphicsBlinkAnimation::meUpdate(const unsigned int time)
{
  m_elapsedTime += time;
  while (m_elapsedTime > m_blinkFrequency) {
    m_elapsedTime -= m_blinkFrequency;

    if (parent()) {
      if (m_becomeInvisible) {
        parent()->setVisible(!parent()->isVisible());
      } else {
        if (m_colorApplied) {
          parent()->setColor(m_parentColor);
        } else {
          m_parentColor = parent()->color();
          parent()->setColor(m_becomeColor);
        }
        m_colorApplied = !m_colorApplied;
      }
    }
  }
}
