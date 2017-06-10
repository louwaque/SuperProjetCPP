#include "../include/GraphicsText.hpp"

GraphicsText::GraphicsText(const Id &parent)
: GraphicsItem(parent),
  m_text(""),
  m_font(),
  m_align(EZAlign::TL)
{}

GraphicsText::GraphicsText(const Ptr &parent)
: GraphicsText()
{
  setParent(parent);
}

GraphicsText::GraphicsText(const GraphicsItem *parent)
: GraphicsText()
{
  setParent(parent);
}

GraphicsText::GraphicsText(const std::string &text, const Id &parent)
: GraphicsText(parent)
{
  m_text = text;
}

GraphicsText::GraphicsText(const std::string &text, const Ptr &parent)
: GraphicsText(text)
{
  setParent(parent);
}

GraphicsText::GraphicsText(const std::string &text, const GraphicsItem *parent)
: GraphicsText(text)
{
  setParent(parent);
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
