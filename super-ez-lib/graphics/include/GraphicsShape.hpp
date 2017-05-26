#ifndef GRAPHICSSHAPE_HPP
#define GRAPHICSSHAPE_HPP

/*!
 * \file GraphicsShape.hpp
 * \brief Classe GraphicsShape
 * \author Loïc Escales, Leo Sudreau
 * \version 0.1
 * \date 23 mai 2017
 */

#include "GraphicsItem.hpp"

class GraphicsShape : public GraphicsItem
{
public:

  explicit GraphicsShape(GraphicsItem *parent = nullptr);

  inline GraphicsTypes type() const { return ShapeType; }

protected:

  void meDraw(Canvas *canvas);

protected:

  GraphicsItemList m_points;
};

#endif
