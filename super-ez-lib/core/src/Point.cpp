#include "../include/Point.hpp"
#include <boost/uuid/uuid_generators.hpp>

Point::GroupsPoints Point::m_groups;

Point::Point()
  : m_x(0),
    m_y(0),
    m_groupId(boost::uuids::nil_uuid())
{}

Point::Point(int x, int y)
  : m_x(x),
    m_y(y),
    m_groupId(boost::uuids::nil_uuid())
{}

Point::Point(const Point &src)
: Point(src.m_x, src.m_y)
{
  //FIXME les deux sont dans le même groupe ? je ne pense pas
}

Point::~Point()
{
  beAlone();
}

Point &Point::operator=(const Point &src)
{
  set(src.m_x, src.m_y);
  return *this;
}

void Point::setX(const int x)
{
  m_x = x;

  if (!m_groupId.is_nil())
    for (Point &p : m_groups[m_groupId])
      if (p.m_x != m_x)
        p.m_x = m_x;
}

void Point::setY(const int y)
{
  m_y = y;

  if (!m_groupId.is_nil())
    for (Point &p : m_groups[m_groupId])
      if (p.m_y != m_y)
        p.m_y = m_y;
}

void Point::set(const int x, const int y) {
  m_x = x;
  m_y = y;

  if (!m_groupId.is_nil()) {
    for (Point &p : m_groups[m_groupId]) {
      if (p.m_x != m_x || p.m_y != m_y) {
        p.m_x = m_x;
        p.m_y = m_y;
      }
    }
  }
}

void Point::join(Point &point)
{
  beAlone();

  if (point.m_groupId.is_nil()) {
    point.m_groupId = boost::uuids::random_generator()();
    m_groups[point.m_groupId].push_back(point);
  }

  m_groupId = point.m_groupId;
  m_groups[m_groupId].push_back(*this);

  set(point.x(), point.y());
}

void Point::beAlone()
{
  if (m_groupId.is_nil())
    return;

  auto &group = m_groups[m_groupId];
  for (size_t i = 0; i < group.size(); ++i)
    if (&(group[i].get()) == this)
      group.erase(group.begin()+i);

  if (group.empty())
    m_groups.erase(m_groupId);

  m_groupId = boost::uuids::nil_uuid();
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
