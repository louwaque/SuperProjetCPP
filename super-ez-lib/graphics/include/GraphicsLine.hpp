#ifndef GRAPHICSLINE_HPP
#define GRAPHICSLINE_HPP

#include "GraphicsShape.hpp"

/*!
 * \class GraphicsLine
 * \brief Une ligne
 * \ingroup graphics
 */

class GraphicsLine : public GraphicsShape
{
public:
  explicit GraphicsLine(GraphicsItem *parent = nullptr);

  GraphicsItem *first() {
    return m_points[0];
  }

  GraphicsItem *second() {
    return m_points[1];
  }

  GraphicsTypes type() const {
    return LineType;
  }
};

#endif
