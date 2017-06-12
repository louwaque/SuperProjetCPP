#ifndef GRAPHICSFACTORY_HPP
#define GRAPHICSFACTORY_HPP

#include <Layout.hpp>

class GraphicsFactory
{
public:
  GraphicsFactory() = delete;

  static GraphicsItem::Ptr circle(std::shared_ptr<Layout> layout);
  static GraphicsItem::Ptr ellipse(std::shared_ptr<Layout> layout);
  static GraphicsItem::Ptr line(std::shared_ptr<Layout> layout);
  static GraphicsItem::Ptr polygon(std::shared_ptr<Layout> layout);
  static GraphicsItem::Ptr rectangle(std::shared_ptr<Layout> layout);
  static GraphicsItem::Ptr square(std::shared_ptr<Layout> layout);
  static GraphicsItem::Ptr text(std::shared_ptr<Layout> layout);
  static GraphicsItem::Ptr triangle(std::shared_ptr<Layout> layout);
  static GraphicsItem::Ptr image(std::shared_ptr<Layout> layout);
};

#endif
