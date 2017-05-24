#ifndef POINT_HPP
#define POINT_HPP

/*!
 * \file Point.hpp
 * \brief Classe point
 * \author Loïc Escales, Leo Sudreau
 * \version 0.1
 * \date 22 mai 2017
 */

#include <iostream>

/*!
 * \class Point
 * \brief Représente un point (x, y)
 *
 * Représente un point avec une abscisse et une ordonnée
 */

class Point
{
public:

  /*!
   * \brief Constructeur par défaut de la classe Point.
   *
   * Crée une instance de la classe Point avec les coordonnées (0, 0).
   */

  Point();

  /*!
   * \brief Constructeur de la classe Point.
   *
   * Crée une instance de la classe Point.
   *
   * \param x : abscisse
   * \param y : ordonnée
   */

  Point(int x, int y);

  /*!
   * \brief Constructeur par copie
   *
   * Constructeur par copie de la classe Point
   *
   * \param src : point à copier
   */

  Point(const Point & src);

  ~Point();

  /*!
   *  \brief recupere la valeur de l'absisse du Point.
   *
   *  \return  l'absisse du Point
   */

  inline int x() const { return m_x; }

  /*!
   *  \brief  Fonction recuperant le valeur de l'ordonée.
   *
   *  \return  Retourne l'ordonée du Point.
   */

  inline int y() const { return m_y; }

  /*!
   *  \brief  Fonction permettant la modification de la valeur de l'absisse x.
   *
   *  \param x l'absisse du point
   */

 inline int &x() { return m_x;}

 /*!
  *  \brief  Fonction permettant la modification de la valeur de l'ordonnée y.
  *
  *  \param y  l'ordonée du point.
  */

 inline int &y() {return m_y;}

 /*!
  *  \brief  permet la modification des valeurs du point.
  *
  * \param x  l'absisse du point
  * \param y  l'ordonée du point
  */

 void set(const int x, const int y);

private:
  int m_x; /*!< Abscisse du Point*/
  int m_y; /*!< Ordonnée du Point*/
};

/*!
 *  \brief   Surchage de l'operateur ==
 *
 * Test si les coordonées du point sont identiques
 *
 * \param l Premier point à comparer
 * \param r Second point à comparer
 */

bool operator==(const Point &l, const Point &r);

/*!
 *  \brief   Surchage de l'operateur +.
 *
 * Additionnes les coordonées de deux points entre eux
 *
 * \param l Premier point à Additionner
 * \param r Second point à Additionner
 */

Point operator+(const Point &l, const Point &r);

/*!
 *  \brief   Surchage de l'operateur +.
 *
 * Additionnes des valeurs aux coordonées d'un point
 *
 * \param l Premier point à Additionner
 * \param number valeur à Additionner
 */

Point operator+(const Point &p, const int number);

/*!
 *  \brief  Surchage de l'operateur -
 *
* Soustraits les coordonées de deux points entre eux
 *
 * \param l Point diminuende
 * \param r Point diminuteur
 */

Point operator-(const Point &l, const Point &r);

/*!
 *  \brief  Surchage de l'operateur -
 *
 * Soustraits des valeurs aux coordonée d'un point
 *
 * \param l Point diminuende
 * \param r valeur diminuteur
 */

Point operator-(const Point &p, const int number);

/*!
 *  \brief  Surchage de l'operateur <<
 *
 * Operateur d'injection
 *
 * \param os Flux d'injection
 * \param r Point injecté dans os
 */

std::ostream &operator<<(std::ostream &os, const Point &p);

/*!
 *  \brief  Surchage de l'operateur <
 *
 * Test si les coordonnées d'un premier point sont inferieur à un autre
 *
 * \param l Point comparé
 * \param r Point comparant
 */

bool operator<(const Point &l, const Point &r);


#endif
