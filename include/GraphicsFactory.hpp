#ifndef GRAPHICSFACTORY_HPP
#define GRAPHICSFACTORY_HPP

#include <GraphicsItem.hpp>

class GraphicsFactory
{
public:
  static GraphicsItem::Ptr circle();
  static GraphicsItem::Ptr ellipse();
  static GraphicsItem::Ptr line();
  static GraphicsItem::Ptr polygon();
  static GraphicsItem::Ptr rectangle();
  static GraphicsItem::Ptr square();
  static GraphicsItem::Ptr text();
  static GraphicsItem::Ptr triangle();

private:
  GraphicsFactory();
};

#endif
