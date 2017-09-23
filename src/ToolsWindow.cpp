#include "../include/ToolsWindow.hpp"
#include "../include/GraphicsFactory.hpp"
#include <Label.hpp>
#include <Button.hpp>

ToolsWindow::ToolsWindow(const std::shared_ptr<Layout> &layoutConfig, GraphicsItem *parent)
: Widget(parent),
  m_layout(nullptr),
  m_layoutConfig(layoutConfig)
{
  m_layout = make<Layout>(this);
  m_layout->setSpacing(5);

  auto m_layoutTool = make<Layout>(Layout::Horizontal);
  m_layoutTool->setSpacing(5);
  m_layout->push_back(m_layoutTool);

  auto label = make<Label>("Créer une forme : ");
  label->setAlign(Label::LabelAlign::Center);
  m_layoutTool->push_back(label);

  auto circleButton = make<Button>("Cercle");
  m_layoutTool->push_back(circleButton);
  circleButton->clicked([this](){
    configItem(GraphicsFactory::circle(m_layoutConfig));
  });

  auto ellipseButton = make<Button>("Ellipse");
  m_layoutTool->push_back(ellipseButton);
  ellipseButton->clicked([this](){
    configItem(GraphicsFactory::ellipse(m_layoutConfig));
  });

  auto lineButton = make<Button>("Ligne");
  m_layoutTool->push_back(lineButton);
  lineButton->clicked([this](){
    configItem(GraphicsFactory::line(m_layoutConfig));
  });

  auto polygonButton = make<Button>("Polygone");
  m_layoutTool->push_back(polygonButton);
  polygonButton->clicked([this](){
    configItem(GraphicsFactory::polygon(m_layoutConfig));
  });

  auto rectangleButton = make<Button>("Rectangle");
  m_layoutTool->push_back(rectangleButton);
  rectangleButton->clicked([this](){
    configItem(GraphicsFactory::rectangle(m_layoutConfig));
  });

  auto squareButton = make<Button>("Carré");
  m_layoutTool->push_back(squareButton);
  squareButton->clicked([this](){
    configItem(GraphicsFactory::square(m_layoutConfig));
  });

  auto textButton = make<Button>("Texte");
  m_layoutTool->push_back(textButton);
  textButton->clicked([this](){
    configItem(GraphicsFactory::text(m_layoutConfig));
  });

  auto triangleButton = make<Button>("Triangle");
  m_layoutTool->push_back(triangleButton);
  triangleButton->clicked([this](){
    configItem(GraphicsFactory::triangle(m_layoutConfig));
  });

  auto imageButton = make<Button>("Image");
  m_layoutTool->push_back(imageButton);
  imageButton->clicked([this](){
    configItem(GraphicsFactory::image(m_layoutConfig));
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

void ToolsWindow::meDraw(Canvas* canvas)
{
  if (canvas)
    m_spawnPoint.set(canvas->width()/2.0, canvas->height()/2.0);
}

void ToolsWindow::configItem(GraphicsItem::Ptr item)
{
  item->setParent(this->parent());
  item->position().set(m_spawnPoint);
}
