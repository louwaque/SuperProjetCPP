#include "../include/Point.hpp"

Point::Point()
  : m_x(0),
    m_y(0)
{
}

Point::Point(int x, int y)
  : m_x(x),
    m_y(y)
{
}

Point::Point(const CorrectorList &fixed)
: m_x(0),
  m_y(0),
  m_correctorsFixed(fixed)
{
}

Point::Point(const Point &src)
: m_x(src.m_x),
  m_y(src.m_y),
  m_correctorsFixed(src.m_correctorsFixed),
  m_correctorsVariable(src.m_correctorsVariable)
{
  // if (src.m_origin)
  //   m_origin = new Point(m_origin->m_x, m_origin->m_y);
  //FIXME les deux sont dans le même groupe ? je ne pense pas
}

Point::~Point()
{
}

Point &Point::operator=(const Point &src)
{
  m_x = src.m_x;
  m_y = src.m_y;
  m_correctorsFixed = src.m_correctorsFixed;
  m_correctorsVariable = src.m_correctorsVariable;

  return *this;
}

void Point::set(const Point &point)
{
  // std::cerr << "SET " << this << " from " << *this << " to "<< x << " " << y << '\n';
  Point newP(point);

  for (auto c : m_correctorsFixed)
    if (c)
      newP = c(newP);
  for (auto c : m_correctorsVariable)
    if (c)
      newP = c(newP);

  if (*this != newP) {
    m_x = newP.m_x;
    m_y = newP.m_y;
    // std::cerr << "mon nouveau moi " << *this << '\n';
  }
}

// void Point::merge(std::shared_ptr<Point> first, std::shared_ptr<Point> second)
// {
//   auto ptr = std::make_shared<Point>(*first);
// }
//
// void Point::divide(std::shared_ptr<Point> first, std::shared_ptr<Point> second)
// {
//
// }

bool operator==(const Point &l, const Point &r) {
  return l.x() == r.x() and l.y() == r.y();
}

bool operator!=(const Point &l, const Point &r) {
  return !(l == r);
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
