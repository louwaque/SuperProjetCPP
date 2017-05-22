#include "../include/MainWindow.hpp"
#include "../include/GraphicsPoint.hpp"
#include "../include/GraphicsText.hpp"
#include "../include/GraphicsLine.hpp"
#include "../include/GraphicsTriangle.hpp"
#include "../include/GraphicsRectangle.hpp"
#include "../include/GraphicsPolygon.hpp"
#include "../include/GraphicsCircle.hpp"
#include "../include/GraphicsEllipse.hpp"

MainWindow::MainWindow()
: Window(400, 400, "SuperProjetCPP"), m_scene(), currentItem(nullptr)
{
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

void MainWindow::drawEvent()
{
  m_scene.draw(&canvas());
}

void MainWindow::mousePressEvent(const Point &mousePos, const MouseButton button)
{
  for (GraphicsItem *item : m_scene.children(GraphicsItem::PointType)) {
    if (item->isOver(mousePos))
      currentItem = item;
  }
}

void MainWindow::mouseReleaseEvent(const Point &mousePos, const MouseButton button)
{
  currentItem = nullptr;
}

void MainWindow::mouseMoveEvent(const Point &mousePos, const MouseButton button)
{
  if (currentItem) {
    currentItem->setAbsolute(mousePos);
    drawRequest();
  }
}
