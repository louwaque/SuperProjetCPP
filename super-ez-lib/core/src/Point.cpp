#include "../include/Point.hpp"
#include <boost/uuid/uuid_generators.hpp>
#include <boost/bind.hpp>

Point::GroupsPoints Point::m_groups;

Point::Point()
  : m_x(0),
    m_y(0),
    m_originX(0),
    m_originY(0),
    m_groupId(boost::uuids::nil_uuid()),
    m_joinType(Absolute)
{
}

Point::Point(int x, int y)
  : m_x(x),
    m_y(y),
    m_originX(0),
    m_originY(0),
    m_groupId(boost::uuids::nil_uuid()),
    m_joinType(Absolute)
{
}

Point::Point(const CorrectorList &fixed)
: m_x(0),
  m_y(0),
  m_originX(0),
  m_originY(0),
  m_groupId(boost::uuids::nil_uuid()),
  m_correctorsFixed(fixed),
  m_joinType(Absolute)
{
}

Point::Point(const Point &src)
: m_x(src.m_x),
  m_y(src.m_y),
  m_originX(src.m_originX),
  m_originY(src.m_originY),
  m_groupId(boost::uuids::nil_uuid()),
  m_correctorsFixed(src.m_correctorsFixed),
  m_correctorsVariable(src.m_correctorsVariable),
  m_joinType(src.m_joinType)
{
  // if (src.m_origin)
  //   m_origin = new Point(m_origin->m_x, m_origin->m_y);
  //FIXME les deux sont dans le même groupe ? je ne pense pas
}

Point::~Point()
{
  beAlone();
}

Point &Point::operator=(const Point &src)
{
  m_originX = src.m_originX;
  m_originY = src.m_originY;
  set(src.m_x, src.m_y);
  return *this;
}

Point Point::absolute() const
{
  return Point(m_originX, m_originY) + *this;
}

void Point::setAbsolute(const Point &point)
{
  // std::cerr << "set absolute " << point << '\n';
  set(point - Point(m_originX, m_originY));
}

void Point::setAbsolute(const int x, const int y)
{
  setAbsolute({x, y});
}

void Point::set(const int x, const int y)
{
  // std::cerr << "SET " << this << " from " << *this << " to "<< x << " " << y << '\n';
  if (m_x != x || m_y != y) {
    m_x = x;
    m_y = y;
    // std::cerr << "mon nouveau moi " << *this << '\n';
    m_changed(*this);
  }
    // for (auto c : m_correctorsFixed)
    //   if (c)
    //     newP = c(newP);
    // for (auto c : m_correctorsVariable)
    //   if (c)
    //     newP = c(newP);
}

void Point::join(Point &point)
{
  beAlone();
  // std::cerr << "JOIN " << *this << " " << this <<" join " << point << " "<< &point << '\n';

  co_t hisCo = point.changed(boost::bind(&Point::friendChanged, this, _1));
  co_t myCo = m_changed.connect(boost::bind(&Point::friendChanged, &point, _1));

  point.m_friends.push_back(hisCo);
  point.m_friends.push_back(myCo);
  m_friends.push_back(hisCo);
  m_friends.push_back(myCo);

  *this = point.absolute();
}

void Point::beAlone()
{
  for (auto &c : m_friends)
    c.disconnect();

  m_friends.clear();

  //les co des autres points ?
}

void Point::originChanged(const Point &point)
{
  //point à bien l'origin ?
  Point abs = point.absolute();
  m_originX = abs.m_x;
  m_originY = abs.m_y;
  // std::cerr << "originChanged " << m_originX << " " << m_originY << '\n';
  set(m_x, m_y);
  // std::cerr << "SET DANS ORIGIN " << *this << '\n';
  // std::cerr << "nouvel origin " << m_originX << " " << m_originY  << " absolute " << absolute() << '\n';
}

void Point::friendChanged(const Point &point)
{
  // std::cerr << "BONJOUR " << point << std::endl;
  if (m_joinType == Absolute)
    setAbsolute(point.absolute());
  else
    set(point);
}

bool operator==(const Point &l, const Point &r) {
  return l.x() == r.x() and l.y() == r.y();
}

Point operator+(const Point &l, const Point &r) {
  return Point(l.x()+r.x(), l.y()+r.y());
}

Point operator+(const Point &p, const int number) {
  return Point(p.x()+number, p.y()+number);
}

Point operator-(const Point &l, const Point &r) {
  return Point(l.x()-r.x(), l.y()-r.y());
}

Point operator-(const Point &p, const int number) {
  return Point(p.x()-number, p.y()-number);
}

std::ostream &operator<<(std::ostream &os, const Point &p) {
  return os << p.x() << " " << p.y();
}

bool operator<(const Point &l, const Point &r) {
  return l.x() < r.x() and l.y() < r.y();
}
