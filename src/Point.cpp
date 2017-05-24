#include "../include/Point.hpp"

Point::Point()
  : m_x(0), m_y(0){}

Point::Point(int x, int y)
  : m_x(x), m_y(y){}

Point::Point( const Point & src)
:Point(src.m_x,src.m_y){}

Point::~Point(){};

void Point::set(const int x, const int y) {
  m_x = x;
  m_y = y;
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
