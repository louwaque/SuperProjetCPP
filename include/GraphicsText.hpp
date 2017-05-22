#ifndef GRAPHICSTEXT_HPP
#define GRAPHICSTEXT_HPP

#include "GraphicsItem.hpp"

class GraphicsText : public GraphicsItem
{
public:
  explicit GraphicsText(GraphicsItem *parent = nullptr);
  explicit GraphicsText(const std::string &text, GraphicsItem *parent = nullptr);

  std::string text() const {
    return m_text;
  }

  void setText(const std::string &text = "") {
    m_text = text;
  }

  EZAlign align() const {
    return m_align;
  }

  void setAlign(const EZAlign align = EZAlign::TL) {
    m_align = align;
  }

  GraphicsTypes type() const {
    return TextType;
  }

protected:
  void meDraw(Canvas *canvas);
  bool meIsOver(const Point &absoluteP);

private:
  std::string m_text;
  //FIXME : Je veux mettre à la poubelle EZDraw
  EZAlign m_align;
};

#endif
