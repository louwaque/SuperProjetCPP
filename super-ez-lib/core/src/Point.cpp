#include "../include/Point.hpp"
#include <boost/uuid/uuid_generators.hpp>

Point::GroupsPoints Point::m_groups;

Point::Point(const Point *origin)
  : m_origin(origin),
    m_x(0),
    m_y(0),
    m_groupId(boost::uuids::nil_uuid())
{}

Point::Point(int x, int y)
  : m_origin(nullptr),
    m_x(x),
    m_y(y),
    m_groupId(boost::uuids::nil_uuid())
{}

Point::Point(const CorrectorList &fixed)
: m_origin(nullptr),
  m_x(0),
  m_y(0),
  m_groupId(boost::uuids::nil_uuid()),
  m_correctorsFixed(fixed)
{}

Point::Point(const Point &src)
: m_origin(src.m_origin),
  m_x(src.m_x),
  m_y(src.m_y),
  m_groupId(boost::uuids::nil_uuid()),
  m_correctorsFixed(src.m_correctorsFixed),
  m_correctorsVariable(src.m_correctorsVariable)
{
  //FIXME les deux sont dans le même groupe ? je ne pense pas
}

Point::~Point()
{
  beAlone();
}

Point &Point::operator=(const Point &src)
{
  m_origin = src.m_origin;
  m_x = src.m_x;
  m_y = src.m_y;
  m_groupId = boost::uuids::nil_uuid();
  m_correctorsFixed = src.m_correctorsFixed;
  m_correctorsVariable = src.m_correctorsVariable;

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
    return m_groups[m_groupId].origin();
  }
}

void Point::setOrigin(const Point *origin)
{
  if (isAlone())
    m_origin = origin;
  else
    m_groups[m_groupId].setOrigin(origin);
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
    // for (auto c : m_correctorsFixed)
    //   if (c)
    //     newP = c(newP);
    // for (auto c : m_correctorsVariable)
    //   if (c)
    //     newP = c(newP);
    m_x = newP.x() - origin().x();
    m_y = newP.y() - origin().y();
  } else {
    // for (Point &p : m_groups[m_groupId]) {
    //   for (auto c : p.m_correctorsFixed)
    //     if (c)
    //       newP = c(newP);
    //   for (auto c : p.m_correctorsVariable)
    //     if (c)
    //       newP = c(newP);
    // }
    GroupPoints &gp = m_groups[m_groupId];
    for (Point &p : gp.points()) {
      p.m_x = newP.x() - p.origin().x();
      p.m_y = newP.y() - p.origin().y();
    }
  }
}

void Point::join(Point &point)
{
  beAlone();

  if (point.isAlone()) {
    point.m_groupId = boost::uuids::random_generator()();
    m_groups[point.m_groupId].points().push_back(point);
  }

  m_groupId = point.m_groupId;
  m_groups[m_groupId].points().push_back(*this);

  set(point);
}

void Point::beAlone()
{
  if (isAlone())
    return;

  auto &group = m_groups[m_groupId].points();
  for (size_t i = 0; i < group.size(); ++i)
    if (&(group[i].get()) == this)
      group.erase(group.begin()+i);

  if (group.empty())
    m_groups.erase(m_groupId);

  Point oldMe(x(), y());
  m_groupId = boost::uuids::nil_uuid();
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
