#include "../include/ToolsWindow.hpp"
#include <Label.hpp>
#include <Button.hpp>
#include <LineEdit.hpp>

#include <GraphicsText.hpp>
#include <GraphicsLine.hpp>
#include <GraphicsTriangle.hpp>
#include <GraphicsRectangle.hpp>
#include <GraphicsPolygon.hpp>

ToolsWindow::ToolsWindow(GraphicsItem *parent)
: Widget(parent),
  m_layout(nullptr)
{
  m_layout = new Layout(Layout::Vertical, this);
  m_layout->setSpacing(5);

  Label *label = new Label("Outils");
  label->setAlign(Label::LabelAlign::Center);
  m_layout->push_back(label);

  m_layout->push_back(new LineEdit);

  Button *textButton = new Button("Texte");
  m_layout->push_back(textButton);
  textButton->clicked([this](){
    new GraphicsText("Du texte !", this->parent());
  });

  Button *lineButton = new Button("Ligne");
  m_layout->push_back(lineButton);
  lineButton->clicked([this](){
    new GraphicsLine(this->parent());
  });

  Button *rectangleButton = new Button("Un Rectangle");
  m_layout->push_back(rectangleButton);
  rectangleButton->clicked([this](){
    new GraphicsRectangle(this->parent());
  });

  widthChanged([this](){
    m_layout->setWidth(width());
  });
  heightChanged([this](){
    m_layout->setHeight(height());
  });
}
