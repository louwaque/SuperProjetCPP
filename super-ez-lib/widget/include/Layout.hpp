#ifndef LAYOUT_HPP
#define LAYOUT_HPP

#include "Widget.hpp"

/*!
 * \class Layout
 * \brief Organiser les widgets
 * \ingroup widget
 */

//FIXME quand un enfant change de parent il faut l'enlever
class Layout : public Widget
{
public:
  enum Orientation {
    Horizontal,
    Vertical
  };

  typedef std::vector<std::shared_ptr<Widget>> Widgets;

  explicit Layout(GraphicsItem *parent = nullptr);
  Layout(const Orientation orientation, GraphicsItem *parent = nullptr);

  inline Orientation orientation() const { return m_orientation; }
  inline void setOrientation(const Orientation orientation) { m_orientation = orientation; organize(); }

  inline size_t spacing() const { return m_spacing; }
  inline void setSpacing(const size_t spacing) { m_spacing = spacing; organize(); }

  void push_back(std::shared_ptr<Widget> widget);
  void push_back(const std::string &label, std::shared_ptr<Widget> widget);
  std::shared_ptr<Widget> pop_back();
  inline size_t size() const { return m_widgets.size(); }
  void erase(const std::shared_ptr<Widget> &widget);
  void clear();

  std::shared_ptr<Widget> operator[](const size_t index) { return m_widgets[index]; }

  inline size_t minimumWidth() const { return m_minimumWidth; }
  inline size_t minimumHeight() const { return m_minimumHeight; }

private:
  void organize();

private:
  Orientation m_orientation;
  size_t m_spacing;

  Widgets m_widgets;

  size_t m_minimumWidth;
  size_t m_minimumHeight;
};

#endif
