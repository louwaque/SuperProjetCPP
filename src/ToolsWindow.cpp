#include "../include/ToolsWindow.hpp"
#include "../include/GraphicsFactory.hpp"
#include <Label.hpp>
#include <Button.hpp>

ToolsWindow::ToolsWindow(GraphicsItem *parent)
: Widget(parent),
  m_layout(nullptr)
{
  m_layout = new Layout(Layout::Vertical, this);
  m_layout->setSpacing(5);

  Label *label = new Label("Créer une forme");
  label->setAlign(Label::LabelAlign::Center);
  m_layout->push_back(label);

  Button *circleButton = new Button("Cercle");
  m_layout->push_back(circleButton);
  circleButton->clicked([this](){
    GraphicsFactory::circle()->setParent(this->parent());
  });

  Button *ellipseButton = new Button("Ellipse");
  m_layout->push_back(ellipseButton);
  ellipseButton->clicked([this](){
    GraphicsFactory::ellipse()->setParent(this->parent());
  });

  Button *lineButton = new Button("Ligne");
  m_layout->push_back(lineButton);
  lineButton->clicked([this](){
    GraphicsFactory::line()->setParent(this->parent());
  });

  Button *polygonButton = new Button("Polygone");
  m_layout->push_back(polygonButton);
  polygonButton->clicked([this](){
    GraphicsFactory::polygon()->setParent(this->parent());
  });

  Button *rectangleButton = new Button("Rectangle");
  m_layout->push_back(rectangleButton);
  rectangleButton->clicked([this](){
    GraphicsFactory::rectangle()->setParent(this->parent());
  });

  Button *squareButton = new Button("Carré");
  m_layout->push_back(squareButton);
  squareButton->clicked([this](){
    GraphicsFactory::square()->setParent(this->parent());
  });

  Button *textButton = new Button("Texte");
  m_layout->push_back(textButton);
  textButton->clicked([this](){
    GraphicsFactory::text()->setParent(this->parent());
  });

  Button *triangleButton = new Button("Triangle");
  m_layout->push_back(triangleButton);
  triangleButton->clicked([this](){
    GraphicsFactory::triangle()->setParent(this->parent());
  });

  widthChanged([this](){
    m_layout->setWidth(width());
  });
  heightChanged([this](){
    m_layout->setHeight(height());
  });

  m_layout->minimumWidthChanged([this]() {
    m_minimumWidthChanged();
  });
  m_layout->minimumHeightChanged([this]() {
    m_minimumHeightChanged();
  });
}

size_t ToolsWindow::minimumWidth() const
{
  return m_layout->minimumWidth();
}

size_t ToolsWindow::minimumHeight() const
{
  return m_layout->minimumHeight();
}
