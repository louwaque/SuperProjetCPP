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
  item->radiusPt().setRelative(50, 50);

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
  item->radius().setRelative(100, 100);

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
  item->second().setRelative(100, 100);

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
  item->bottomRight().setRelative(100, 100);

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
  item->bottomRight().setRelative(100, 100);

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
  item->setText("texte demo");

  auto pt1 = GraphicsItem::make<GraphicsPoint>(item.get());
  pt1->position().join(item->position());

  GraphicsItem::make<Toy<ConfigText>>(item, pt1, layout, item.get());

  return item;
}

GraphicsItem::Ptr GraphicsFactory::triangle(std::shared_ptr<Layout> layout)
{
  auto item = GraphicsItem::make<GraphicsTriangle>();
  item->second().setRelative(-100, 100);
  item->third().setRelative(100, 100);

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
  item->image() = Image::rainbow(200, 100);

  auto pt1 = GraphicsItem::make<GraphicsPoint>(item.get());
  pt1->position().join(item->position());

  GraphicsItem::make<Toy<ConfigImage>>(item, pt1, layout, item.get());

  return item;
}
