#include "../include/GraphicsFactory.hpp"
#include "../include/Toy.hpp"

#include "../include/ConfigItem.hpp"
#include "../include/ConfigPolygon.hpp"
#include "../include/ConfigText.hpp"
#include "../include/ConfigImage.hpp"

#include <GraphicsCircle.hpp>
#include <GraphicsEllipse.hpp>
#include <GraphicsPoint.hpp>
#include <GraphicsLine.hpp>
#include <GraphicsPolygon.hpp>
#include <GraphicsRectangle.hpp>
#include <GraphicsSquare.hpp>
#include <GraphicsText.hpp>
#include <GraphicsTriangle.hpp>
#include <GraphicsImage.hpp>

GraphicsItem::Ptr GraphicsFactory::circle(std::shared_ptr<Layout> layout)
{
  auto item = GraphicsItem::make<GraphicsCircle>();

  auto pt1 = GraphicsItem::make<GraphicsPoint>(item.get());
  pt1->position().join(item->position());

  auto pt2 = GraphicsItem::make<GraphicsPoint>(item.get());
  pt2->position().join(item->radiusPt());

  GraphicsItem::make<Toy<ConfigItem>>(item, pt1, layout, item.get());

  return item;
}

GraphicsItem::Ptr GraphicsFactory::ellipse(std::shared_ptr<Layout> layout)
{
  auto item = GraphicsItem::make<GraphicsEllipse>();

  auto pt1 = GraphicsItem::make<GraphicsPoint>(item.get());
  pt1->position().join(item->position());

  auto pt2 = GraphicsItem::make<GraphicsPoint>(item.get());
  pt2->position().join(item->radius());

  GraphicsItem::make<Toy<ConfigItem>>(item, pt1, layout, item.get());

  return item;
}

GraphicsItem::Ptr GraphicsFactory::line(std::shared_ptr<Layout> layout)
{
  auto item = GraphicsItem::make<GraphicsLine>();

  auto pt1 = GraphicsItem::make<GraphicsPoint>(item.get());
  pt1->position().join(item->position());

  auto pt2 = GraphicsItem::make<GraphicsPoint>(item.get());
  pt2->position().join(item->second());

  GraphicsItem::make<Toy<ConfigItem>>(item, pt1, layout, item.get());

  return item;
}

GraphicsItem::Ptr GraphicsFactory::polygon(std::shared_ptr<Layout> layout)
{
  auto item = GraphicsItem::make<GraphicsPolygon>();

  auto pt1 = GraphicsItem::make<GraphicsPoint>(item.get());
  pt1->position().join(item->position());

  GraphicsItem::make<Toy<ConfigPolygon>>(item, pt1, layout, item.get());

  return item;
}

GraphicsItem::Ptr GraphicsFactory::rectangle(std::shared_ptr<Layout> layout)
{
  auto item = GraphicsItem::make<GraphicsRectangle>();

  auto pt1 = GraphicsItem::make<GraphicsPoint>(item.get());
  pt1->position().join(item->position());

  auto pt2 = GraphicsItem::make<GraphicsPoint>(item.get());
  pt2->position().join(item->bottomRight());

  GraphicsItem::make<Toy<ConfigItem>>(item, pt1, layout, item.get());

  return item;
}

GraphicsItem::Ptr GraphicsFactory::square(std::shared_ptr<Layout> layout)
{
  auto item = GraphicsItem::make<GraphicsSquare>();

  auto pt1 = GraphicsItem::make<GraphicsPoint>(item.get());
  pt1->position().join(item->position());

  auto pt2 = GraphicsItem::make<GraphicsPoint>(item.get());
  pt2->position().join(item->bottomRight());

  GraphicsItem::make<Toy<ConfigItem>>(item, pt1, layout, item.get());

  return item;
}

GraphicsItem::Ptr GraphicsFactory::text(std::shared_ptr<Layout> layout)
{
  auto item = GraphicsItem::make<GraphicsText>();

  auto pt1 = GraphicsItem::make<GraphicsPoint>(item.get());
  pt1->position().join(item->position());

  GraphicsItem::make<Toy<ConfigText>>(item, pt1, layout, item.get());

  return item;
}

GraphicsItem::Ptr GraphicsFactory::triangle(std::shared_ptr<Layout> layout)
{
  auto item = GraphicsItem::make<GraphicsTriangle>();

  auto pt1 = GraphicsItem::make<GraphicsPoint>(item.get());
  pt1->position().join(item->position());

  auto pt2 = GraphicsItem::make<GraphicsPoint>(item.get());
  pt2->position().join(item->second());

  auto pt3 = GraphicsItem::make<GraphicsPoint>(item.get());
  pt3->position().join(item->third());

  GraphicsItem::make<Toy<ConfigItem>>(item, pt1, layout, item.get());

  return item;
}

GraphicsItem::Ptr GraphicsFactory::image(std::shared_ptr<Layout> layout)
{
  auto item = GraphicsItem::make<GraphicsImage>();

  auto pt1 = GraphicsItem::make<GraphicsPoint>(item.get());
  pt1->position().join(item->position());

  GraphicsItem::make<Toy<ConfigImage>>(item, pt1, layout, item.get());

  return item;
}
