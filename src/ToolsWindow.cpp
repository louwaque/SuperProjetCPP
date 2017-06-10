#include "../include/ToolsWindow.hpp"
#include "../include/GraphicsFactory.hpp"
#include <Label.hpp>
#include <Button.hpp>

ToolsWindow::ToolsWindow(GraphicsItem *parent)
: Widget(parent),
  m_layout(nullptr)
{
  m_layout = make<Layout>(Layout::Vertical, this);
  m_layout->setSpacing(5);

  auto label = make<Label>("Créer une forme");
  label->setAlign(Label::LabelAlign::Center);
  m_layout->push_back(label);

  auto circleButton = make<Button>("Cercle");
  m_layout->push_back(circleButton);
  circleButton->clicked([this](){
    GraphicsFactory::circle()->setParent(this->parent());
  });

  auto ellipseButton = make<Button>("Ellipse");
  m_layout->push_back(ellipseButton);
  ellipseButton->clicked([this](){
    GraphicsFactory::ellipse()->setParent(this->parent());
  });

  auto lineButton = make<Button>("Ligne");
  m_layout->push_back(lineButton);
  lineButton->clicked([this](){
    GraphicsFactory::line()->setParent(this->parent());
  });

  auto polygonButton = make<Button>("Polygone");
  m_layout->push_back(polygonButton);
  polygonButton->clicked([this](){
    GraphicsFactory::polygon()->setParent(this->parent());
  });

  auto rectangleButton = make<Button>("Rectangle");
  m_layout->push_back(rectangleButton);
  rectangleButton->clicked([this](){
    GraphicsFactory::rectangle()->setParent(this->parent());
  });

  auto squareButton = make<Button>("Carré");
  m_layout->push_back(squareButton);
  squareButton->clicked([this](){
    GraphicsFactory::square()->setParent(this->parent());
  });

  auto textButton = make<Button>("Texte");
  m_layout->push_back(textButton);
  textButton->clicked([this](){
    GraphicsFactory::text()->setParent(this->parent());
  });

  auto triangleButton = make<Button>("Triangle");
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
