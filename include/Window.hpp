#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <cmath>
#include <cstdint>
#include <sstream>
#include "../ez-lib/ez-draw++.hpp"

class Window : public EZWindow
{
public:
  Window() : EZWindow(), m_canvas(*this), m_scene(), currentItem(nullptr) {
    GraphicsPoint *point = new GraphicsPoint(&m_scene);
    point->setAbsolute({50, 50});
    point->setColor(Color(Color::Blue));
    GraphicsText *text = new GraphicsText("Je suis super fort !!!", point);
    text->setAnchor({0, 10});
    text->setColor(Color(Color::Yellow));
    GraphicsText *text1 = new GraphicsText("EZDraw c'est rigolo ^^", point);
    text1->setAnchor({10, 20});
    text1->setColor(Color(Color::Green));

    GraphicsPoint *point2 = new GraphicsPoint(&m_scene);
    point2->setAbsolute({100, 50});
    point2->setColor(Color(Color::Yellow));
    GraphicsText *text2 = new GraphicsText("Bonjour les gens !!!!", point2);
    text2->setColor(Color(Color::Red));

    GraphicsLine *line = new GraphicsLine(&m_scene);
    line->setAbsolute({50, 100});
    line->second()->setAnchor({80, 20});

    GraphicsTriangle *triangle = new GraphicsTriangle(&m_scene);
    triangle->setFill(true);
    triangle->setAbsolute({200, 20});
    triangle->second()->setAnchor(Point(-30, 30));
    triangle->third()->setAnchor(Point(30, 30));

    GraphicsRectangle *rectangle = new GraphicsRectangle(&m_scene);
    rectangle->setThick(5);
    rectangle->setAbsolute({100, 100});
    rectangle->bottomRight()->setAnchor({80, 50});

    GraphicsPolygon *polygon = new GraphicsPolygon(&m_scene);
    polygon->setFill(true);
    polygon->setAbsolute({200, 100});
    polygon->setNbPoints(10);
    polygon->setNbPoints(5);

    GraphicsCircle *circle = new GraphicsCircle(&m_scene);
    circle->setAbsolute({100, 300});
    circle->radius()->setAnchor({50, 50});

    GraphicsEllipse *ellipse = new GraphicsEllipse(&m_scene);
    ellipse->setAbsolute({200, 300});
    ellipse->radius()->setAnchor({100, 50});
  }

  void buttonPress(int x, int y, int button) {
    for (GraphicsItem *item : m_scene.children(GraphicsItem::PointType)) {
      if (item->isOver(Point(x, y)))
        currentItem = item;
    }
  }

  void buttonRelease(int x, int y, int button) {
    currentItem = nullptr;
  }

  void motionNotify(int x, int y, int button) {
    if (currentItem) {
      currentItem->setAbsolute(Point(x, y));
    }
    sendExpose();
  }

  void expose() {
    m_scene.draw(&m_canvas);
  }

private:
  Canvas m_canvas;
  GraphicsItem m_scene;
  GraphicsItem *currentItem;
};

#endif
