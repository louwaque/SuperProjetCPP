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
: Window(400, 400, "SuperProjetCPP"),
  m_scene(nullptr),
  currentItem(nullptr)
{
  m_scene = GraphicsItem::make<GraphicsItem>();

  auto point = GraphicsItem::make<GraphicsPoint>(m_scene.get());
  point->position().set(5, 5);
  point->setColor(Color(Color::Blue));

  auto text = GraphicsItem::make<GraphicsText>("Je suis super fort !!!", point.get());
  text->position().setRelative(0, 10);
  text->setColor(Color(Color::Green));
  text->setFont(Font::w12h24);

  auto text1 = GraphicsItem::make<GraphicsText>("EZDraw c'est rigolo ^^", point.get());
  text1->position().setRelative(10, 30);
  text1->setColor(Color(Color::Green));

  {
    auto rectangle = GraphicsItem::make<GraphicsRectangle>(m_scene.get());
    rectangle->position().set(50, 50);
    rectangle->topLeft().setRelative(-20, -20);
    rectangle->bottomRight().setRelative(20, 20);
    rectangle->setHeight(100);
    rectangle->setWidth(300);

    auto rp1 = GraphicsItem::make<GraphicsPoint>(rectangle.get());
    rp1->position().join(rectangle->position());

    auto rp2 = GraphicsItem::make<GraphicsPoint>(rectangle.get());
    rp2->position().join(rectangle->topLeft());

    auto rp3 = GraphicsItem::make<GraphicsPoint>(rectangle.get());
    rp3->position().join(rectangle->bottomRight());
  }

  {
    auto triangle = GraphicsItem::make<GraphicsTriangle>(m_scene.get());
    triangle->position().set(200, 200);
    triangle->first().setRelative(0, -10);
    triangle->second().setRelative(-5, 10);
    triangle->third().setRelative(5, 10);

    auto p1 = GraphicsItem::make<GraphicsPoint>(triangle.get());
    p1->position().join(triangle->position());

    auto p2 = GraphicsItem::make<GraphicsPoint>(triangle.get());
    p2->position().join(triangle->first());

    auto p3 = GraphicsItem::make<GraphicsPoint>(triangle.get());
    p3->position().join(triangle->second());

    auto p4 = GraphicsItem::make<GraphicsPoint>(triangle.get());
    p4->position().join(triangle->third());
  }
/*
  GraphicsPolygon *polygon = new GraphicsPolygon(&m_scene);
  polygon->setFill(true);
  polygon->position().set(200, 100);
  polygon->setNbPoints(10);
  polygon->setNbPoints(5);

  {
    GraphicsCircle *circle = new GraphicsCircle(&m_scene);
    circle->position().set(100, 300);
    circle->radiusPt().setRelative(50, 50);

    GraphicsPoint *p1 = new GraphicsPoint(circle);
    p1->position().join(circle->position());

    GraphicsPoint *p2 = new GraphicsPoint(circle);
    p2->position().join(circle->radiusPt());

    new GraphicsBlinkAnimation(Color(Color::Blue), circle);
  }

  {
    GraphicsEllipse *ellipse = new GraphicsEllipse(&m_scene);
    ellipse->position().set(200, 300);
    ellipse->radius().setRelative(100, 50);

    GraphicsBlinkAnimation *blink = new GraphicsBlinkAnimation(ellipse);
    blink->setBlinkFrequency(500);
  }

  {
    GraphicsSquare *square = new GraphicsSquare(&m_scene);
    square->setThick(5);
    square->position().set(500, 100);
    square->topLeft().setRelative(-10, -10);
    square->bottomRight().setRelative(10, 10);

    GraphicsPoint *p1 = new GraphicsPoint(square);
    p1->position().join(square->position());

    GraphicsPoint *p2 = new GraphicsPoint(square);
    p2->position().join(square->topLeft());

    GraphicsPoint *p3 = new GraphicsPoint(square);
    p3->position().join(square->bottomRight());
  }

  LineEdit *lineEdit = new LineEdit(&m_scene);
  lineEdit->position().set(100, 500);

  Button *button = new Button("Ajouter une forme", &m_scene);
  button->position().set(50,150);
  button->clicked([this](){
    GraphicsRectangle *b_rectangle = new GraphicsRectangle(&m_scene);
    b_rectangle->position().set(200,150);
    b_rectangle->setHeight(50);
    b_rectangle->setWidth(70);
  });

  Button *button_agrandir = new Button("Grossir le trait", &m_scene);
  button_agrandir->position().set(100,175);
  button_agrandir->clicked([this](){
    if (GraphicsItem::focusItem()) {
      GraphicsItem::focusItem()->setThick(5);
    }
  });*/
}

void MainWindow::drawEvent()
{
  m_scene->draw(&canvas());
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
  m_scene->update(time);
  drawRequest();
}

void MainWindow::handleEvent(const Event &event)
{
  m_scene->handleEvent(event);
  drawRequest();
}
