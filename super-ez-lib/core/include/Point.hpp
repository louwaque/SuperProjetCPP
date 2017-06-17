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
#include <vector>
#include <memory>

#include "GroupPoints.hpp"
class GroupPoints;

/*!
 * \class Point
 * \ingroup core
 * \brief Représente un point avec une abscisse, une ordonnée et une origine.
 *
 * Un point peut avoir un autre point comme origine.
 * Ainsi ses coordonnées x et y sont relatives par rapport à l'origine.
 * Les méthodes relatives permettent de faire abstraction de l'origine.
 *
 * Un point peut rejoindre un autre point ce qui forme un groupe de points.
 * Ainsi tous les points de groupe partagent les mêmes coordonnées.
 * Un groupe de points peut avoir un point comme origine.
 *
 * Un Corrector est une fonction qui corrige la position du point.
 *
 * Un point possède deux listes de Corrector.
 * La première est figée à la construction et ne peux plus être modifié.
 * La deuxième est variable.
 * Quand un point doit changer de coordonnée, tous les Corrector
 * (du point et des points de son groupe) sont appliqués sur les nouvelles coordonnées.
 */

class Point
{
public:

  /*!
   * \brief Une fonction qui corrige les coordonnées du Point
   */

  typedef std::function<Point(const Point&)> Corrector;

  /*!
   * \brief Une liste de Corrector
   */

  typedef std::vector<Corrector> CorrectorList;

  /*!
   * \brief Construit un point avec les coordonnées nulles.
   *
   * \param origin Origine du point
   */

  Point(const Point *origin = nullptr);

  /*!
   * \brief Construit un point à l'aide d'une abscisse et d'une ordonnée
   *
   * \param x Abscisse
   * \param y Ordonnée
   * \param origin Origine du point
   */

  Point(int x, int y, const Point *origin = nullptr);

  /*!
   * \brief Construit un point avec une liste de Corrector fixée
   *
   * Les Corrector ne pouront plus être modifié par la suite.
   *
   * \param fixed Lise de Corrector
   * \param origin Origine du point
   */

  Point(const CorrectorList &fixed, const Point *origin = nullptr);

  /*!
   * \brief Constructeur par copie
   *
   * Si le point copié appartient à un groupe alors la copie rejoindra ce groupe
   *
   * \param src Point à copier
   */

  Point(const Point &src);

  /*!
   * \brief Destructeur
   *
   * Quitte le groupe avec beAlone() avant d'être détruit
   */

  ~Point();

  /*!
   * \brief Opérateur d'affectation
   *
   * Si le point copié appartient à un groupe alors la copie rejoindra ce groupe
   * La liste des Corrector figés n'est pas modifiée.
   *
   * \param src Point à copier
   */

  Point &operator=(const Point &src);

  /*!
   * \brief Donne l'origine du point
   *
   * Renvoie l'origine du point ou du groupe auquel il appartient.
   */

  Point origin() const;

  /*!
   * \brief Modifie l'origine du point
   *
   * Modifie l'origine du point ou du groupe auquel il appartient.
   */

  void setOrigin(const Point *origin = nullptr);

  /*!
   * \brief Donne les coordonnées du point indépendamment de son origine
   */

  inline Point relative() const { return Point(m_x, m_y); }

  /*!
   * \brief Donne l'abscisse du point indépendamment de son origine
   */

  inline int relativeX() const { return m_x; }

  /*!
   * \brief Donne l'ordonnée du point indépendamment de son origine
   */

  inline int relativeY() const { return m_y; }

  /*!
   * \brief Modifie les coordonnées du point indépendamment de son origine
   */

  void setRelative(const Point &point);

  /*!
   * \brief Modifie l'abscisse du point indépendamment de son origine
   */

  inline void setRelativeX(const int x) { setRelative({x, relativeY()}); }

  /*!
   * \brief Modifie l'ordonnée du point indépendamment de son origine
   */

  inline void setRelativeY(const int y) { setRelative({relativeX(), y}); }

  /*!
   * \brief Modifie les coordonnées du point indépendamment de son origine
   */

  inline void setRelative(const int x, const int y) { setRelative({x, y}); }

  /*!
   *  \brief Donne l'abscisse du point par rapport à son origine
   */

  int x() const;

  /*!
   *  \brief Modifie l'abscisse du point par rapport à son origine
   */

  inline void setX(const int x) { set(x, y()); }

  /*!
   *  \brief Donne l'ordonnée du point par rapport à son origine
   */

  int y() const;

  /*!
   *  \brief Modifie l'ordonnée du point par rapport à son origine
   */

  inline void setY(const int y) { set(x(), y); }

  /*!
  *  \brief Modifie les coordonnées du point par rapport à son origine.
  *
  * \param x Abscisse
  * \param y Ordonnée
  */

  void set(const int x, const int y);

  /*!
  *  \brief Modifie les coordonnées du point par rapport à son origine.
  */

  inline void set(const Point &point) { set(point.x(), point.y()); }

  /*!
  *  \brief Rejoint le groupe d'un point
  *
  * Quand un point rejoint un autre point ils créent un groupe de points.
  * Si un point rejoint un autre point qui appartient déjà à un groupe alors le premier point est ajouté à ce groupe.
  * Le point qui rejoint reçoit les coordonnées du point qu'il rejoint.
  *
  * Un groupe de points partage les mêmes coordonnées et un même Point d'origine.
  *
  * Si lors de la création du groupe les deux points ont la même origine alors le groupe aura cette origine.
  *
  * \param point Point à rejoindre
  */

  void join(Point &point);

  /*!
  *  \brief Quitte le groupe auquel le point appartient
  */

  void beAlone();

  /*!
  *  \brief Indique si le point n'appartient pas à un groupe.
  */

  inline bool isAlone() const { return m_group == nullptr; }

  inline CorrectorList correctors() const { return m_correctorsVariable; }
  inline CorrectorList &correctors() { return m_correctorsVariable; }

private:
  const Point *m_origin; /*!< Origine du Point*/
  int m_x; /*!< Abscisse du Point*/
  int m_y; /*!< Ordonnée du Point*/

  std::shared_ptr<GroupPoints> m_group;

  const CorrectorList m_correctorsFixed;
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
