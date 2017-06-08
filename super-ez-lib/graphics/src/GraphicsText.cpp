#include "../include/GraphicsText.hpp"

GraphicsText::GraphicsText(GraphicsItem *parent)
: GraphicsItem(parent),
  m_text(""),
  m_font(),
  m_align(EZAlign::TL)
{}

GraphicsText::GraphicsText(const std::string &text, GraphicsItem *parent)
: GraphicsText(parent)
{
  m_text = text;
}

void GraphicsText::meDraw(Canvas *canvas)
{
  if (canvas) {
    canvas->setFont(m_font);
    canvas->drawText(m_align, position(), m_text);
  }
}

bool GraphicsText::meIsOver(const Point &absoluteP)
{
  //FIXME compliqué mais faisable; dépend de align
  return false;
}
