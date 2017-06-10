#ifndef GRAPHICSPOLYGON_HPP
#define GRAPHICSPOLYGON_HPP

#include "GraphicsShape.hpp"

/*!
 * \class GraphicsPolygon
 * \brief Un polygone
 * \ingroup graphics
 */

class GraphicsPolygon : public GraphicsShape
{
public:

  explicit GraphicsPolygon(const Id &parent = boost::uuids::nil_generator()());
  explicit GraphicsPolygon(const Ptr &parent);
  explicit GraphicsPolygon(const GraphicsItem *parent);


  Point &newPoint();
  void popPoint();

  inline size_t nbPoints() const { return m_points.size(); }
  void setNbPoints(const size_t nb);

  GraphicsTypes type() const {
    return PolygonType;
  }
};

#endif
