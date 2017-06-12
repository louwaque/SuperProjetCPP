#include "../include/ToolsWindow.hpp"
#include "../include/GraphicsFactory.hpp"
#include <Label.hpp>
#include <Button.hpp>

ToolsWindow::ToolsWindow(GraphicsItem *parent)
: Widget(parent),
  m_layout(nullptr)
{
  m_layout = make<Layout>(this);
  m_layout->setSpacing(5);

  auto m_layoutTool = make<Layout>(Layout::Horizontal);
  m_layoutTool->setSpacing(5);
  m_layout->push_back(m_layoutTool);

  m_layoutConfig = make<Layout>(Layout::Vertical);
  m_layoutConfig->setSpacing(5);
  m_layout->push_back(m_layoutConfig);

  auto label = make<Label>("Créer une forme : ");
  label->setAlign(Label::LabelAlign::Center);
  m_layoutTool->push_back(label);

  auto circleButton = make<Button>("Cercle");
  m_layoutTool->push_back(circleButton);
  circleButton->clicked([this](){
    GraphicsFactory::circle(m_layoutConfig)->setParent(this->parent());
  });

  auto ellipseButton = make<Button>("Ellipse");
  m_layoutTool->push_back(ellipseButton);
  ellipseButton->clicked([this](){
    GraphicsFactory::ellipse(m_layoutConfig)->setParent(this->parent());
  });

  auto lineButton = make<Button>("Ligne");
  m_layoutTool->push_back(lineButton);
  lineButton->clicked([this](){
    GraphicsFactory::line(m_layoutConfig)->setParent(this->parent());
  });

  auto polygonButton = make<Button>("Polygone");
  m_layoutTool->push_back(polygonButton);
  polygonButton->clicked([this](){
    GraphicsFactory::polygon(m_layoutConfig)->setParent(this->parent());
  });

  auto rectangleButton = make<Button>("Rectangle");
  m_layoutTool->push_back(rectangleButton);
  rectangleButton->clicked([this](){
    GraphicsFactory::rectangle(m_layoutConfig)->setParent(this->parent());
  });

  auto squareButton = make<Button>("Carré");
  m_layoutTool->push_back(squareButton);
  squareButton->clicked([this](){
    GraphicsFactory::square(m_layoutConfig)->setParent(this->parent());
  });

  auto textButton = make<Button>("Texte");
  m_layoutTool->push_back(textButton);
  textButton->clicked([this](){
    GraphicsFactory::text(m_layoutConfig)->setParent(this->parent());
  });

  auto triangleButton = make<Button>("Triangle");
  m_layoutTool->push_back(triangleButton);
  triangleButton->clicked([this](){
    GraphicsFactory::triangle(m_layoutConfig)->setParent(this->parent());
  });

  auto imageButton = make<Button>("Image");
  m_layoutTool->push_back(imageButton);
  imageButton->clicked([this](){
    GraphicsFactory::image(m_layoutConfig)->setParent(this->parent());
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
