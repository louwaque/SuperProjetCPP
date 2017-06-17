#ifndef GRAPHICSBLINKANIMATION_HPP
#define GRAPHICSBLINKANIMATION_HPP

#include "GraphicsAnimation.hpp"

/*!
 * \class GraphicsBlinkAnimation
 * \brief Faire clignoter sont parent
 * \ingroup graphics
 */

class GraphicsBlinkAnimation : public GraphicsAnimation
{
public:
  explicit GraphicsBlinkAnimation(GraphicsItem *parent = nullptr);
  GraphicsBlinkAnimation(const Color &color, GraphicsItem *parent = nullptr);

  inline unsigned int blinkFrequency() const { return m_blinkFrequency; }
  inline void setBlinkFrequency(const unsigned int frequency) { m_blinkFrequency = frequency; }

  inline Color becomeColor() const { return m_becomeColor; }
  inline void setBecomeColor(const Color &color) { m_becomeColor = color; }

  inline bool becomeInvisible() const { return m_becomeInvisible; }
  inline void setBecomeInvisible(const bool invisible) { m_becomeInvisible = invisible; }

protected:
  void meUpdate(const unsigned int time);

private:
  unsigned int m_blinkFrequency;
  unsigned int m_elapsedTime;
  Color m_becomeColor;
  Color m_parentColor;
  bool m_colorApplied;
  bool m_becomeInvisible;
};

#endif
