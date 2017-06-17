#ifndef GRAPHICSANIMATION_HPP
#define GRAPHICSANIMATION_HPP

#include "GraphicsItem.hpp"

/*!
 * \class GraphicsAnimation
 * \brief Classe de base pour les animations
 * \ingroup graphics
 */

class GraphicsAnimation : public GraphicsItem
{
public:
  explicit GraphicsAnimation(GraphicsItem *parent = nullptr);
};

#endif
