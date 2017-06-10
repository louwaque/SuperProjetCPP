#ifndef GRAPHICSFACTORY_HPP
#define GRAPHICSFACTORY_HPP

#include <GraphicsItem.hpp>

class GraphicsFactory
{
public:
  static GraphicsItem *circle();
  static GraphicsItem *ellipse();
  static GraphicsItem *line();
  static GraphicsItem *polygon();
  static GraphicsItem *rectangle();
  static GraphicsItem *square();
  static GraphicsItem *text();
  static GraphicsItem *triangle();

private:
  GraphicsFactory();
};

#endif
