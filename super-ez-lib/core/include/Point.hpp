#ifndef POINT_HPP
#define POINT_HPP

/*!
 * \file Point.hpp
 * \brief Classe point
 * \author Loïc Escales, Leo Sudreau
 * \version 0.1
 * \date 22 mai 2017
 */
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <iostream>
#include <map>
#include <vector>
#include <functional>

/*!
 * \class Point
 * \brief Représente un point (x, y)
 *
 * Représente un point avec une abscisse et une ordonnée
 */

class Point
{
public:
  typedef boost::uuids::uuid Id;
  typedef std::map<Id, std::vector<std::reference_wrapper<Point>>> GroupsPoints;
  typedef std::function<Point(const Point&)> Corrector;
  typedef std::vector<Corrector> CorrectorList;

  enum JoinType {
    Relative,
    Absolute
  };

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

  Point(const CorrectorList &fixed);

  /*!
   * \brief Constructeur par copie
   *
   * Constructeur par copie de la classe Point
   *
   * \param src : point à copier
   */

  Point(const Point &src);

  ~Point();

  Point &operator=(const Point &src);

  //quand le parent est modifié, la position absolu de l'objet est recalculer pour GARDER la même qu'avant
  void setParent(const Point *parent) {
    Point old = absolute();
    m_parent = parent;
    setAbsolute(old); }

  Point absolute() const;
  void setAbsolute(const Point &point);
  void setAbsolute(const int x, const int y);

  /*!
   *  \brief recupere la valeur de l'absisse du Point.
   *
   *  \return  l'absisse du Point
   */

  inline int x() const { return m_x; }

  inline void setX(const int x) { set(x, m_y); }

  /*!
   *  \brief  Fonction recuperant le valeur de l'ordonée.
   *
   *  \return  Retourne l'ordonée du Point.
   */

  inline int y() const { return m_y; }

  inline void setY(const int y) { set(m_x, y); }

  /*!
  *  \brief  permet la modification des valeurs du point.
  *
  * \param x  l'absisse du point
  * \param y  l'ordonée du point
  */

  void set(const int x, const int y);

  inline void set(const Point &point) { set(point.m_x, point.m_y); }

  void join(Point &point, const JoinType type = Absolute);
  void beAlone();

  inline CorrectorList correctors() const { return m_correctorsVariable; }
  inline CorrectorList &correctors() { return m_correctorsVariable; }

private:
  const Point *m_parent;
  int m_x; /*!< Abscisse du Point*/
  int m_y; /*!< Ordonnée du Point*/

  static GroupsPoints m_groups; //FIXME rm static
  Id m_groupId;
  JoinType m_joinType;

  CorrectorList m_correctorsFixed;
  CorrectorList m_correctorsVariable;
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
