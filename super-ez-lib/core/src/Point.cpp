#include "../include/Point.hpp"
#include <boost/uuid/uuid_generators.hpp>

Point::GroupsPoints Point::m_groups;

Point::Point()
  : m_x(0),
    m_y(0),
    m_groupId(boost::uuids::nil_uuid()),
    m_parent(nullptr)
{}

Point::Point(int x, int y)
  : m_x(x),
    m_y(y),
    m_groupId(boost::uuids::nil_uuid()),
    m_parent(nullptr)
{}

Point::Point(const CorrectorList &fixed)
: m_x(0),
  m_y(0),
  m_groupId(boost::uuids::nil_uuid()),
  m_correctorsFixed(fixed),
  m_parent(nullptr)
{}

Point::Point(const Point &src)
: m_x(src.m_x),
  m_y(src.m_y),
  m_groupId(boost::uuids::nil_uuid()),
  m_correctorsFixed(src.m_correctorsFixed),
  m_correctorsVariable(src.m_correctorsVariable),
  m_parent(src.m_parent)
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

Point Point::absolute() const
{
  if (m_parent)
    return m_parent->absolute() + *this;
  else
    return *this;
}

void Point::setAbsolute(const Point &point)
{
  if (m_parent)
    set(point - m_parent->absolute());
  else
    set(point);
}

void Point::setAbsolute(const int x, const int y)
{
  setAbsolute({x, y});
}

void Point::set(const int x, const int y)
{
  Point newP(x, y);
  if (!m_groupId.is_nil()) {

    // for (Point &p : m_groups[m_groupId]) {
    //   for (auto c : p.m_correctorsFixed)
    //     if (c)
    //       newP = c(newP);
    //   for (auto c : p.m_correctorsVariable)
    //     if (c)
    //       newP = c(newP);
    // }

    m_x = newP.m_x;
    m_y = newP.m_y;

    // std::cerr << "Moi: " << this << '\n';
    // std::cerr << "Point à mettre : " << newP << '\n';
    for (Point &p : m_groups[m_groupId]) {
      // std::cerr << "Boucle pour: " << p << " " << &p<< '\n';
      if (&p != this) {
        Point ownP(absolute());
        if (p.m_joinType == Absolute && p.m_parent) {
          ownP = ownP - p.m_parent->absolute();
        }
        // std::cerr << "Point mis: " << ownP << '\n';
        p.m_x = ownP.m_x;
        p.m_y = ownP.m_y;
      }
      // std::cerr << "fin" << '\n' << '\n';
    }
    // std::cerr << "\n" << '\n';
  } else {
    // for (auto c : m_correctorsFixed)
    //   if (c)
    //     newP = c(newP);
    // for (auto c : m_correctorsVariable)
    //   if (c)
    //     newP = c(newP);

    m_x = newP.m_x;
    m_y = newP.m_y;
  }
}

void Point::join(Point &point, const JoinType type)
{
  beAlone();
  m_joinType = type;
  point.m_joinType = type;

  if (point.m_groupId.is_nil()) {
    point.m_groupId = boost::uuids::random_generator()();
    m_groups[point.m_groupId].push_back(point);
  }

  m_groupId = point.m_groupId;
  m_groups[m_groupId].push_back(*this);

  *this = point.absolute();
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
