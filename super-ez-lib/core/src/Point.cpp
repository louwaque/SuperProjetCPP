#include "../include/Point.hpp"

Point::Point(const Point *origin)
  : m_origin(origin),
    m_x(0),
    m_y(0)
{}

Point::Point(int x, int y, const Point *origin)
  : m_origin(origin),
    m_x(x),
    m_y(y)
{}

Point::Point(const CorrectorList &fixed, const Point *origin)
: m_origin(origin),
  m_x(0),
  m_y(0),
  m_correctorsFixed(fixed)
{}

Point::Point(const Point &src)
: m_origin(src.m_origin),
  m_x(src.m_x),
  m_y(src.m_y),
  m_group(src.m_group),
  m_correctorsFixed(src.m_correctorsFixed),
  m_correctorsVariable(src.m_correctorsVariable)
{
  if (m_group)
    m_group->points().push_back(*this);
}

Point::~Point()
{
  beAlone();
}

Point &Point::operator=(const Point &src)
{
  beAlone();

  m_origin = src.m_origin;
  m_x = src.m_x;
  m_y = src.m_y;
  m_group = src.m_group;
  m_correctorsVariable = src.m_correctorsVariable;

  if (m_group)
    m_group->points().push_back(*this);

  return *this;
}

Point Point::origin() const
{
  if (isAlone()) {
    if (m_origin)
      return *m_origin;
    else
      return Point(0, 0);
  } else {
    return m_group->origin();
  }
}

void Point::setOrigin(const Point *origin)
{
  if (isAlone())
    m_origin = origin;
  else
    m_group->setOrigin(origin);
}

void Point::setRelative(const Point &point)
{
  set(origin() + point);
}

int Point::x() const
{
  if ((isAlone() && m_origin) || !isAlone())
    return origin().x() + m_x;
  else
    return m_x;
}

int Point::y() const
{
  if ((isAlone() && m_origin) || !isAlone())
    return origin().y() + m_y;
  else
    return m_y;
}

void Point::set(const int x, const int y)
{
  Point newP(x, y);

  if (isAlone()) {
    for (auto c : m_correctorsFixed)
      if (c)
        newP = c(newP);
    for (auto c : m_correctorsVariable)
      if (c)
        newP = c(newP);

    newP = newP - origin();
    m_x = newP.x();
    m_y = newP.y();
  } else {
    for (Point &p : m_group->points()) {
      for (auto c : p.m_correctorsFixed)
        if (c)
          newP = c(newP);
      for (auto c : p.m_correctorsVariable)
        if (c)
          newP = c(newP);
    }
    newP = newP - m_group->origin();
    for (Point &p : m_group->points()) {
      p.m_x = newP.x();
      p.m_y = newP.y();
    }
  }
}

void Point::join(Point &point)
{
  beAlone();

  if (point.isAlone()) {
    point.m_group = std::make_shared<GroupPoints>();
    point.m_group->points().push_back(point);

    if (m_origin == point.m_origin)
      point.m_group->setOrigin(m_origin);
  }

  m_group = point.m_group;
  m_group->points().push_back(*this);

  set(point);
}

void Point::beAlone()
{
  if (isAlone())
    return;

  auto &group = m_group->points();
  for (size_t i = 0; i < group.size(); ++i)
    if (&(group[i].get()) == this)
      group.erase(group.begin()+i);

  Point oldMe(x(), y());
  m_group.reset();
  set(oldMe);
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
