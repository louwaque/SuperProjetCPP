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

GraphicsItem::Ptr GraphicsFactory::circle()
{
  auto item = GraphicsItem::make<GraphicsCircle>();

  auto pt1 = GraphicsItem::make<GraphicsPoint>(item);
  pt1->position().join(item->position());

  auto pt2 = GraphicsItem::make<GraphicsPoint>(item);
  pt2->position().join(item->radiusPt());

  return item;
}

GraphicsItem::Ptr GraphicsFactory::ellipse()
{

}

GraphicsItem::Ptr GraphicsFactory::line()
{

}

GraphicsItem::Ptr GraphicsFactory::polygon()
{

}

GraphicsItem::Ptr GraphicsFactory::rectangle()
{

}

GraphicsItem::Ptr GraphicsFactory::square()
{

}

GraphicsItem::Ptr GraphicsFactory::text()
{

}

GraphicsItem::Ptr GraphicsFactory::triangle()
{

}
