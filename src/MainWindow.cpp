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
#include <LineEdit.hpp>

MainWindow::MainWindow()
: Window(400, 400, "SuperProjetCPP"), m_scene(), currentItem(nullptr)
{/*
  GraphicsPoint *point = new GraphicsPoint(&m_scene);
  point->setAbsolute({50, 50});
  point->setColor(Color(Color::Blue));
  GraphicsText *text = new GraphicsText("Je suis super fort !!!", point);
  text->setRelative({0, 10});
  text->setColor(Color(Color::Green));
  text->setFont(Font::w12h24);
  GraphicsText *text1 = new GraphicsText("EZDraw c'est rigolo ^^", point);
  text1->setRelative({10, 20});
  text1->setColor(Color(Color::Green));

  GraphicsPoint *point2 = new GraphicsPoint(&m_scene);
  point2->setAbsolute({100, 50});
  point2->setColor(Color(Color::Yellow));
  GraphicsText *text2 = new GraphicsText("Bonjour les gens !!!!", point2);
  text2->setColor(Color(Color::Red));

  GraphicsLine *line = new GraphicsLine(&m_scene);
  line->setAbsolute({50, 100});
  line->second()->setRelative({80, 20});

  GraphicsTriangle *triangle = new GraphicsTriangle(&m_scene);
  triangle->setFill(true);
  triangle->setAbsolute({200, 20});
  triangle->second()->setRelative(Point(-30, 30));
  triangle->third()->setRelative(Point(30, 30));
*/
  GraphicsRectangle *rectangle = new GraphicsRectangle(&m_scene);
  rectangle->position().set(50, 50);
  rectangle->topLeft().set(-20, -20);
  rectangle->bottomRight().set(20, 20);
  //rectangle->setAbsolute(text->absolute());
  //rectangle->bottomRight().set(text->font().width()*text->text().size(), text->font().height());

  // GraphicsPoint *rp1 = new GraphicsPoint(rectangle); fait tout exploser, un point lié à lui même ?
  // GraphicsPoint *rp1 = new GraphicsPoint(&m_scene); // mieux mais bizare !
  // rp1->position().join(rectangle->position());
  GraphicsPoint *rp1 = new GraphicsPoint(rectangle);
  rp1->position().setOriginDynamic(m_scene.position()); //evite l'explosion ?
  rp1->position().join(rectangle->position());
  rp1->position().setAbsolute(100, 100);
  //rectangle->position().setOriginDynamic(rp1->position());
  //
  //GraphicsPoint *rp2 = new GraphicsPoint(&m_scene); //marche
  GraphicsPoint *rp2 = new GraphicsPoint(rectangle); //marche aussi
  rp2->position().setOriginDynamic(m_scene.position()); // mais pourquoi je dois refaire l'origine ??? ça vient de set parent???
  rp2->position().join(rectangle->topLeft());

  // GraphicsPoint *rp3 = new GraphicsPoint(rectangle); normalement je voudrais ça...
  // rp3->position().join(rectangle->bottomRight());
  // mais c'est ça qui marche !!!
  GraphicsPoint *rp3 = new GraphicsPoint(rectangle);
  rp3->position().setOriginDynamic(m_scene.position()); // mais pourquoi je dois refaire l'origine ??? ça vient de set parent???
  rp3->position().join(rectangle->bottomRight());

  std::cerr << rectangle->position() << " " << rectangle->position().absolute() << '\n';
  std::cerr << rectangle->topLeft() << " " << rectangle->topLeft().absolute() << '\n';
  std::cerr << rectangle->bottomRight() << " " << rectangle->bottomRight().absolute() << '\n';
/*
  GraphicsRectangle *r2 = new GraphicsRectangle(&m_scene);
  r2->relative().set(50, 10);
  r2->topLeft().set(-20, -20);
  r2->bottomRight().set(20, 20);
  r2->topLeft().join(rectangle->bottomRight());*/
/*
  GraphicsPolygon *polygon = new GraphicsPolygon(&m_scene);
  polygon->setFill(true);
  polygon->setAbsolute({200, 100});
  polygon->setNbPoints(10);
  polygon->setNbPoints(5);

  GraphicsCircle *circle = new GraphicsCircle(&m_scene);
  circle->setAbsolute({100, 300});
  circle->radius()->setRelative({50, 50});

  new GraphicsBlinkAnimation(Color(Color::Blue), circle);

  GraphicsEllipse *ellipse = new GraphicsEllipse(&m_scene);
  ellipse->setAbsolute({200, 300});
  ellipse->radius()->setRelative({100, 50});

  GraphicsSquare *square = new GraphicsSquare(&m_scene);
  square->setThick(5);
  square->setAbsolute({500, 100});
  square->bottomRight().set(80, 50);

  GraphicsPoint *sp1 = new GraphicsPoint(&m_scene);
  sp1->relative().join(square->relative());

  GraphicsPoint *sp2 = new GraphicsPoint(square);
  sp2->relative().join(square->bottomRight());

  GraphicsBlinkAnimation *blink = new GraphicsBlinkAnimation(square);
  blink->setBlinkFrequency(500);

  LineEdit *lineEdit = new LineEdit(&m_scene);
  lineEdit->setAbsolute({100, 500});*/
}

void MainWindow::drawEvent()
{
  m_scene.draw(&canvas());
}

void MainWindow::mousePressEvent(const Point &mousePos, const MouseEvent::MouseButton button)
{
  // for (GraphicsItem *item : m_scene.children(GraphicsItem::PointType)) {
  //   if (item->isOver(mousePos))
  //     currentItem = item;
  // }
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
