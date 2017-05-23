#ifndef GRAPHICSITEM_HPP
#define GRAPHICSITEM_HPP

#include <vector>
#include <memory>
#include "Color.hpp"
#include "Canvas.hpp"

class GraphicsItem {
public:
  typedef std::vector<GraphicsItem*> GraphicsItemList;

  enum GraphicsTypes { //mouse movable type ?
    UndefinedType = 0x0,
    ItemType = 0x1,
    PointType = 0x2,
    TextType = 0x4,
    ShapeType = 0x6,
    LineType = 0x8,
    TriangleType = 0x10,
    RectangleType = 0x12,
    PolygonType = 0x14,
    AnchorType = 0x16,
    CircleType = 0x18,
    EllipseType = 0x20
  };

  enum SearchTypes {
    DirectChildren,
    ChildrenRecursively
  };

  explicit GraphicsItem(GraphicsItem *parent = nullptr);

  virtual ~GraphicsItem();

  GraphicsItem *parent() const {
    return m_parent;
  }

  void setParent(GraphicsItem *parent);

  virtual GraphicsTypes type() const {
    return ItemType;
  }

  GraphicsItemList children(const GraphicsTypes filter = UndefinedType, const SearchTypes option = ChildrenRecursively) const;

  Point anchor() const {
    return m_anchor;
  }

  virtual void setAnchor(const Point &anchor) {
    m_anchor = anchor;
  }

  Point absolute() const;

  virtual void setAbsolute(const Point &pos);

  Color color() const {
    return m_color;
  }

  void setColor(const Color color) {
    m_color = color;
  }

  unsigned int thick() const {
    return m_thick;
  }

  void setThick(unsigned int thick = 1) {
    m_thick = thick;
  }

  bool isFill() const {
    return m_isFill;
  }

  void setFill(const bool fill) {
    m_isFill = fill;
  }

  bool isVisible() const {
    return m_isVisible;
  }

  void setVisible(const bool isVisible = true) {
    m_isVisible = isVisible;
  }

  void draw(Canvas *canvas);

  bool isOver(const Point &p);

protected:
  virtual void meDraw(Canvas *canvas) {}
  virtual bool meIsOver(const Point &absoluteP) { return absolute() == absoluteP; }

private:
  GraphicsItem *m_parent;
  std::vector<std::unique_ptr<GraphicsItem>> m_children;
  Point m_anchor;
  Color m_color;
  unsigned int m_thick;
  bool m_isFill;
  bool m_isVisible;
};

#endif