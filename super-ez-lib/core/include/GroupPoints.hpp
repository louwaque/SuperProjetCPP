#ifndef GROUPPOINTS_HPP
#define GROUPPOINTS_HPP

#include "Point.hpp"
class Point;

typedef std::vector<std::reference_wrapper<Point>> Points;

class GroupPoints {
public:
  GroupPoints();

  Point origin() const;
  void setOrigin(const Point *origin = nullptr);
  // inline void setOrigin(const Point &origin) { m_origin = std::make_shared<Point>(origin); }

  inline Points points() const { return m_points; }

private:
  inline Points &points() { return m_points; }

private:
  const Point *m_origin;
  Points m_points;

  friend class Point;
};

#endif
