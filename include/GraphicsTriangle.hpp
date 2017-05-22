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
 * \brief Permet la creation d'un triangle
 *
 * Représente un point avec une abscisse et une ordonnée
 */

class GraphicsTriangle : public GraphicsShape {

public:

  /*!
   * \brief Constructeur par default de la classe GraphicsTriangle.
   *
   * Crée une instance de GraphicsTriangle.
   *
   */

  explicit GraphicsTriangle(GraphicsItem *parent = nullptr);

  /*!
   *  \brief recupere les coordonées du premier point du triangle.
   *
   *  \return coordonées d'un point
   */

  inline GraphicsItem *first() { return m_points[0]; }

  /*!
   *  \brief recupere les coordonées du second point du triangle.
   *
   *  \return coordonées d'un point
   */

  inline GraphicsItem *second() {  return m_points[1]; }

  /*!
   *  \brief recupere les coordonées du troisième point du triangle.
   *
   *  \return coordonées d'un point
   */

  inline GraphicsItem *third() {  return m_points[2]; }

  /*!
   *  \brief recupere le type de l'instance courrante.
   *
   *  \return type de GraphicsTriangle.
   */

  inline GraphicsTypes type() const { return TriangleType; }
};

#endif
