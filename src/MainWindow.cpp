#include "../include/MainWindow.hpp"
#include "../include/GraphicsPoint.hpp"
#include "../include/GraphicsText.hpp"
#include "../include/GraphicsLine.hpp"
#include "../include/GraphicsTriangle.hpp"
#include "../include/GraphicsRectangle.hpp"
#include "../include/GraphicsPolygon.hpp"
#include "../include/GraphicsCircle.hpp"
#include "../include/GraphicsEllipse.hpp"
#include "../include/GraphicsSquare.hpp"
#include "../include/GraphicsBlinkAnimation.hpp"
#include "../include/GraphicsItem.hpp"
#include <LineEdit.hpp>
#include <Button.hpp>
#include <iostream>


MainWindow::MainWindow()
: Window(400, 400, "SuperProjetCPP"), m_scene(), currentItem(nullptr)
{

  GraphicsPoint *point = new GraphicsPoint(&m_scene);
  point->setAbsolute({50, 50});
  point->setColor(Color(Color::Blue));
  GraphicsText *text = new GraphicsText("Je suis super fort !!!", point);
  text->setAnchor({0, 10});
  text->setColor(Color(Color::Green));
  text->setFont(Font::w12h24);
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
  rectangle->setAbsolute(text->absolute());
  rectangle->bottomRight()->setAnchor({text->font().width()*text->text().size(), text->font().height()});

  GraphicsPolygon *polygon = new GraphicsPolygon(&m_scene);
  polygon->setFill(true);
  polygon->setAbsolute({200, 100});
  polygon->setNbPoints(10);
  polygon->setNbPoints(5);

  GraphicsCircle *circle = new GraphicsCircle(&m_scene);
  circle->setAbsolute({100, 300});
  circle->radius()->setAnchor({50, 50});

  new GraphicsBlinkAnimation(Color(Color::Blue), circle);

  GraphicsEllipse *ellipse = new GraphicsEllipse(&m_scene);
  ellipse->setAbsolute({200, 300});
  ellipse->radius()->setAnchor({100, 50});

  GraphicsSquare *square = new GraphicsSquare(&m_scene);
  square->setThick(5);
  square->setAbsolute({500, 100});
  square->bottomRight()->setAnchor({80, 50});

  GraphicsBlinkAnimation *blink = new GraphicsBlinkAnimation(square);
  blink->setBlinkFrequency(500);

  LineEdit *lineEdit = new LineEdit(&m_scene);
  lineEdit->setAbsolute({100, 500});

  Button *button = new Button("Ajouter une forme",&m_scene);
  button->setAbsolute({50,150});
  button->clicked_left([this](){
    std::cout << "SA MARCHE A GAUCHE" << std::endl;
    GraphicsRectangle *b_rectangle = new GraphicsRectangle(&m_scene);
    b_rectangle->setAbsolute({200,150});
    b_rectangle->setHeight(50);
    b_rectangle->setWidth(70);
  });
  button->clicked_right([this](){
    std::cout << "SA MARCHE A DROITE" << std::endl;
    GraphicsCircle *b_circle = new GraphicsCircle(&m_scene);
    b_circle->setAbsolute({300,250});
    b_circle->radius()->setAnchor({50, 50});
  });

  Button *button_agrandir = new Button("Agrandir le rectangle",&m_scene);
  button_agrandir->setAbsolute({100,175});
  button_agrandir->clicked_left([this](){
    if(m_scene.focusItem().GraphicsTypes="RectangleType"){
      m_scene.focusItem()->setWidth(50);
    }
  });
}

void MainWindow::drawEvent()
{
  m_scene.draw(&canvas());
}

void MainWindow::mousePressEvent(const Point &mousePos, const MouseEvent::MouseButton button)
{
    // for (GraphicsItem *item : m_scene.children(GraphicsItem::PointType)) {
    // if (item->isOver(mousePos))
    //   currentItem = item;
    //}
}

void MainWindow::mouseReleaseEvent(const Point &mousePos, const MouseEvent::MouseButton button)
{
  // currentItem = nullptr;
}

void MainWindow::mouseMoveEvent(const Point &mousePos, const MouseEvent::MouseButton button)
{
  // if (currentItem) {
  //   currentItem->setAbsolute(mousePos);
  //   drawRequest();
  // }
}

void MainWindow::updateEvent(const unsigned int time)
{
  m_scene.update(time);
  drawRequest();
}

void MainWindow::handleEvent(const Event &event)
{
  m_scene.handleEvent(event);
  drawRequest();
}
