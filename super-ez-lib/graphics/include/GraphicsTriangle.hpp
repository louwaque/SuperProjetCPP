#ifndef GRAPHICSTRIANGLE_HPP
#define GRAPHICSTRIANGLE_HPP

/*!
 * \file GraphicsTriangle.hpp
 * \brief Classe GraphicsTriangle
 * \author Loïc Escales, Leo Sudreau
 * \version 0.1
 * \date 22 mai 2017
 */

#include "GraphicsShape.hpp"

/*!
 * \class GraphicsTriangle
 * \brief Un triangle quelconque
 * \ingroup graphics
 */

class GraphicsTriangle : public GraphicsShape
{
public:
  explicit GraphicsTriangle(const Id &parent = boost::uuids::nil_generator()());
  explicit GraphicsTriangle(const Ptr &parent);
  explicit GraphicsTriangle(const GraphicsItem *parent);

  /*!
   *  \brief Donne le premier point du triangle.
   */

  inline Point &first() { return m_points[0]; }

  /*!
   *  \brief Donne le second point du triangle.
   */

  inline Point &second() {  return m_points[1]; }

  /*!
   *  \brief Donne le troisième point du triangle.
   */

  inline Point &third() {  return m_points[2]; }
};

#endif
