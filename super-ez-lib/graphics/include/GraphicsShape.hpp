#ifndef GRAPHICSSHAPE_HPP
#define GRAPHICSSHAPE_HPP

/*!
 * \file GraphicsShape.hpp
 * \brief Classe GraphicsShape
 * \author Loïc Escales, Leo Sudreau
 * \version 0.1
 * \date 23 mai 2017
 */

#include <vector>
#include "GraphicsItem.hpp"

/*!
 * \class GraphicsShape
 * \brief Une forme
 * \ingroup graphics
 */

class GraphicsShape : public GraphicsItem
{
public:
  explicit GraphicsShape(GraphicsItem *parent = nullptr);

protected:
  void meDraw(Canvas *canvas);

protected:
  std::vector<Point> m_points;
};

#endif
