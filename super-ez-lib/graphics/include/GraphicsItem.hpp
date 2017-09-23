#ifndef GRAPHICSITEM_HPP
#define GRAPHICSITEM_HPP

/*!
 * \file GraphicsItem.hpp
 * \brief Classe GraphicsItem
 * \author Loïc Escales, Leo Sudreau
 * \version 0.1
 * \date 22 mai 2017
 */

#include <vector>
#include <memory>
#include <Color.hpp>
#include <Canvas.hpp>
#include <Event.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/core/noncopyable.hpp>

/**
 * \defgroup graphics Graphics
 * \brief Classes pour dessiner
 */

/*!
 * \class GraphicsItem
 * \brief Classe de base
 * \ingroup graphics
 *
 * La classe GraphicsItem est la base de tout les éléments graphiques.
 *
 * Une relation parent/enfant peut être créé entre deux GraphicsItem.
 * Les enfants sont stockés dans des shared_ptr, ce qui signifie que la vie des enfants ne dépend pas toujours de celle du parent.
 *
 * Il est très fortement conseillé d’utiliser la fonction make pour créer des GraphicsItem.
 */

class GraphicsItem : public std::enable_shared_from_this<GraphicsItem>, private boost::noncopyable
{
public:
  typedef boost::uuids::uuid Id;
  typedef std::shared_ptr<GraphicsItem> Ptr;
  typedef std::vector<GraphicsItem*> GraphicsItemList;

  enum SearchTypes {
    DirectChildren,
    ChildrenRecursively
  };

  explicit GraphicsItem(GraphicsItem *parent = nullptr);
  virtual ~GraphicsItem();

  inline Id id() const { return m_id; }
  inline Id parentId() const { return m_parent ? m_parent->id() : boost::uuids::nil_generator()(); }
  inline GraphicsItem *parent() const { return m_parent; }

  void setParent(GraphicsItem *parent = nullptr);

  template<typename... Types>
  GraphicsItemList children(const SearchTypes option = ChildrenRecursively) const;

  inline Point position() const { return m_position; }
  inline Point &position() { return m_position; }

  Color color() const {
    return m_color;
  }

  int z() const {
    return m_z;
  }

  void setZ(const int z);

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

  bool isEnable() const {
    return m_isEnable;
  }

  void setEnable(const bool isEnable = true) {
    m_isEnable = isEnable;
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

  Ptr ptr();

  template<class T, class... Args>
  static std::shared_ptr<T> make(Args&&... args);

  inline void deleteLater() { m_deleteLater = true; }

protected:
  virtual void meDraw(Canvas *canvas) {}
  virtual void meUpdate(const unsigned int time) {}
  virtual void meHandleEvent(const Event &event) {}
  virtual bool meIsOver(const Point &absoluteP) { return m_position == absoluteP; }

private:
  void sortChildren();

  template<typename Type>
  bool testTypes(const GraphicsItem * variable) const;

  template<typename Type, typename Type2, typename... Types>
  bool testTypes(const GraphicsItem * variable) const;

private:
  Id m_id;
  GraphicsItem *m_parent;
  std::vector<Ptr> m_children;
  static GraphicsItem *m_focusItem;
  Point m_position;
  int m_z;
  Color m_color;
  unsigned int m_thick;
  bool m_isFill;
  bool m_isEnable;
  bool m_isVisible;
  bool m_deleteLater;
};

template<typename... Types>
GraphicsItem::GraphicsItemList GraphicsItem::children(const SearchTypes option) const
{
  GraphicsItemList list;
  for (const auto &ptr : m_children) {
    if (ptr) {
      if (option == ChildrenRecursively) {
        GraphicsItemList sublist = ptr->children<Types...>(option);
        list.insert(list.end(), sublist.begin(), sublist.end());
      }
      if (testTypes<Types...>(ptr.get()))
        list.push_back(ptr.get());
    }
  }
  return list;
}

template<typename Type>
bool GraphicsItem::testTypes(const GraphicsItem * variable) const
{
  return dynamic_cast<const Type*>(variable) != nullptr;
}

template<typename Type, typename Type2, typename... Types>
bool GraphicsItem::testTypes(const GraphicsItem * variable) const
{
  return testTypes<Type>(variable) || testTypes<Type2>(variable) || testTypes<Types...>(variable);
}

template<class T, class... Args>
std::shared_ptr<T> GraphicsItem::make(Args&&... args)
{
  T * p = new T(std::forward<Args>(args)...);
  return std::dynamic_pointer_cast<T>(p->ptr());
}

bool operator==(const GraphicsItem &l, const GraphicsItem &r);
bool operator!=(const GraphicsItem &l, const GraphicsItem &r);

#endif
