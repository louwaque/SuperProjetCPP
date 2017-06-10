#include "../include/GraphicsFactory.hpp"

#include <GraphicsCircle.hpp>
#include <GraphicsEllipse.hpp>
#include <GraphicsPoint.hpp>
#include <GraphicsLine.hpp>
#include <GraphicsPolygon.hpp>
#include <GraphicsRectangle.hpp>
#include <GraphicsSquare.hpp>
#include <GraphicsText.hpp>
#include <GraphicsTriangle.hpp>

GraphicsItem *GraphicsFactory::circle()
{
  auto * item = new GraphicsCircle(nullptr);

  auto pt1 = new GraphicsPoint(item);
  pt1->position().join(item->position());

  auto pt2 = new GraphicsPoint(item);
  pt2->position().join(item->radiusPt());

  return item;
}

GraphicsItem *GraphicsFactory::ellipse()
{

}

GraphicsItem *GraphicsFactory::line()
{

}

GraphicsItem *GraphicsFactory::polygon()
{

}

GraphicsItem *GraphicsFactory::rectangle()
{

}

GraphicsItem *GraphicsFactory::square()
{

}

GraphicsItem *GraphicsFactory::text()
{

}

GraphicsItem *GraphicsFactory::triangle()
{

}
