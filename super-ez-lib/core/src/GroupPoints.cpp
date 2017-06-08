#include "../include/GroupPoints.hpp"

GroupPoints::GroupPoints()
: m_origin(nullptr),
  m_points()
{}

Point GroupPoints::origin() const
{
  return m_origin ? *m_origin : Point(0, 0);
}

void GroupPoints::setOrigin(const Point *origin)
{
  m_origin = origin;
}
