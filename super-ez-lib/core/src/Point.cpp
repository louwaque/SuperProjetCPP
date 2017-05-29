#include "../include/Point.hpp"
#include <boost/uuid/uuid_generators.hpp>
#include <boost/bind.hpp>

Point::GroupsPoints Point::m_groups;

Point::Point()
  : m_x(0),
    m_y(0),
    m_groupId(boost::uuids::nil_uuid()),
    m_origin(nullptr),
    m_joinType(Absolute)
{
}

Point::Point(int x, int y)
  : m_x(x),
    m_y(y),
    m_groupId(boost::uuids::nil_uuid()),
    m_origin(nullptr),
    m_joinType(Absolute)
{
}

Point::Point(const CorrectorList &fixed)
: m_x(0),
  m_y(0),
  m_groupId(boost::uuids::nil_uuid()),
  m_correctorsFixed(fixed),
  m_origin(nullptr),
  m_joinType(Absolute)
{
}

Point::Point(const Point &src)
: m_x(src.m_x),
  m_y(src.m_y),
  m_groupId(boost::uuids::nil_uuid()),
  m_correctorsFixed(src.m_correctorsFixed),
  m_correctorsVariable(src.m_correctorsVariable),
  m_origin(nullptr),
  m_joinType(src.m_joinType)
{
  if (src.m_origin)
    m_origin = new Point({m_origin->m_x, m_origin->m_y});
  //FIXME les deux sont dans le même groupe ? je ne pense pas
}

Point::~Point()
{
  beAlone();
  delete m_origin;
}

Point &Point::operator=(const Point &src)
{
  set(src.m_x, src.m_y);
  return *this;
}

Point Point::absolute() const
{
  if (m_origin)
    return m_origin->absolute() + *this;
  else
    return *this;
}

void Point::setAbsolute(const Point &point)
{
  if (m_origin)
    set(point - m_origin->absolute());
  else
    set(point);
}

void Point::setAbsolute(const int x, const int y)
{
  setAbsolute({x, y});
}

void Point::set(const int x, const int y)
{
  if (m_x != x || m_y != y) {
    m_x = x;
    m_y = y;
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

void Point::friendChanged(const Point &point)
{
  if (m_joinType == Absolute)
    setAbsolute(point);
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
