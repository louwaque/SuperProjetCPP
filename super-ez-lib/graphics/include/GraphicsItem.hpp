#ifndef GRAPHICSITEM_HPP
#define GRAPHICSITEM_HPP

#include <vector>
#include <set>
#include <memory>
#include <Color.hpp>
#include <Canvas.hpp>
#include <Event.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/core/noncopyable.hpp>

/**
 * \defgroup graphics Graphics
 * \brief Classes pour dessiner
 */

/*!
 * \class GraphicsItem
 * \brief Classe de base
 * \ingroup graphics
 */

class GraphicsItem : private boost::noncopyable {
public:
  typedef boost::uuids::uuid Id;
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
    EllipseType = 0x20,
    SquareType = 0x22,
    AnimationType = 0x24,
    BlinkAnimationType = 0x26
  };

  enum SearchTypes {
    DirectChildren,
    ChildrenRecursively
  };

  explicit GraphicsItem(GraphicsItem *parent = nullptr);

  virtual ~GraphicsItem();

  inline Id id() const { return m_id; }

  GraphicsItem *parent() const {
    return m_parent;
  }

  void setParent(GraphicsItem *parent);

  virtual GraphicsTypes type() const {
    return ItemType;
  }

  GraphicsItemList children(const GraphicsTypes filter = UndefinedType, const SearchTypes option = ChildrenRecursively) const;

  inline Point position() const { return m_position; }
  inline Point &position() { return m_position; }

  Color color() const {
    return m_color;
  }

  int z() const {
    return m_z;
  }

  void setZ(const int z) {
    m_z = z;
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

  void update(const unsigned int time);

  void handleEvent(const Event &event);

  bool isOver(const Point &p);

  inline static GraphicsItem *focusItem() { return m_focusItem; };
  inline static void setFocusItem(GraphicsItem *item) { m_focusItem = item; }
  inline bool hasFocus() const { return m_focusItem == this; };

protected:
  virtual void meDraw(Canvas *canvas) {}
  virtual void meUpdate(const unsigned int time) {}
  virtual void meHandleEvent(const Event &event) {}
  virtual bool meIsOver(const Point &absoluteP) { return m_position == absoluteP; }

private:
  Id m_id;
  GraphicsItem *m_parent;
  std::vector<std::shared_ptr<GraphicsItem>> m_children;
  static GraphicsItem *m_focusItem;
  Point m_position;
  int m_z;
  Color m_color;
  unsigned int m_thick;
  bool m_isFill;
  bool m_isVisible;
};

bool operator==(const GraphicsItem &l, const GraphicsItem &r);
bool operator!=(const GraphicsItem &l, const GraphicsItem &r);

#endif
