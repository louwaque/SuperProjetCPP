#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

class Point {
public:
  Point(int x = 0, int y = 0);

  inline int x() const { return m_x; }

  inline int y() const { return m_y; }

  int &x() {
    return m_x;
  }

  int &y() {
    return m_y;
  }

  void set(const int x, const int y) {
    m_x = x;
    m_y = y;
  }

private:
  int m_x, m_y;
};

bool operator==(const Point &l, const Point &r);
Point operator+(const Point &l, const Point &r);
Point operator+(const Point &p, const int number);
Point operator-(const Point &l, const Point &r);
Point operator-(const Point &p, const int number);
std::ostream &operator<<(std::ostream &os, const Point &p);
bool operator<(const Point &l, const Point &r);

#endif
