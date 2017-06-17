#include "../include/Layout.hpp"
#include "../include/Label.hpp"

Layout::Layout(GraphicsItem *parent)
: Widget(parent),
  m_orientation(Horizontal),
  m_spacing(0),
  m_widgets(),
  m_minimumWidth(0),
  m_minimumHeight(0)
{
  widthChanged(boost::bind(&Layout::organize, this));
  heightChanged(boost::bind(&Layout::organize, this));
}

Layout::Layout(const Orientation orientation, GraphicsItem *parent)
: Layout(parent)
{
  setOrientation(orientation);
}

void Layout::push_back(std::shared_ptr<Widget> widget)
{
  if (widget) {
    m_widgets.push_back(widget);
    widget->setParent(this);
    //FIXME il faut réfléchir
    //widget->minimumWidthChanged(boost::bind(&Layout::organize, this));
    //widget->minimumHeightChanged(boost::bind(&Layout::organize, this));
    organize();
  }
}

void  Layout::push_back(const std::string &label, std::shared_ptr<Widget> widget)
{
  auto layout = make<Layout>(Horizontal);
  layout->push_back(std::dynamic_pointer_cast<Widget>(make<Label>(label)));
  layout->push_back(widget);
  push_back(layout);
}

std::shared_ptr<Widget> Layout::pop_back()
{
  auto widget = m_widgets.back();
  widget->setParent(nullptr);
  m_widgets.pop_back();
  organize();
  return widget;
}

void Layout::erase(const std::shared_ptr<Widget> &widget)
{
  m_widgets.erase(std::remove(m_widgets.begin(), m_widgets.end(), widget), m_widgets.end());
  organize();
}

void Layout::clear()
{
  for (auto widget : m_widgets)
    widget->setParent(nullptr);
  m_widgets.clear();
  organize();
}

void Layout::organize()
{
  size_t oldMW = m_minimumWidth, oldMH = m_minimumHeight;
  m_minimumWidth = 0;
  m_minimumHeight = 0;
  if (m_orientation == Horizontal) {
    for (auto widget : m_widgets) {
      m_minimumWidth += widget->minimumWidth();
      m_minimumHeight = std::max(m_minimumHeight, widget->minimumHeight());
    }
  } else if (m_orientation == Vertical) {
    for (auto widget : m_widgets) {
      m_minimumWidth = std::max(m_minimumWidth, widget->minimumWidth());
      m_minimumHeight += widget->minimumHeight();
    }
  }

  if (m_minimumWidth != oldMW)
    m_minimumWidthChanged();
  if (m_minimumHeight != oldMH)
    m_minimumHeightChanged();

  if (!m_widgets.empty()) {
    int x(0), y(0), w(0), h(0);

    for (auto widget : m_widgets) {
      widget->position().setRelative(x, y);

      if (m_orientation == Horizontal) {
        widget->setWidth(widget->minimumWidth()
          + (width() - minimumWidth())/m_widgets.size());
        widget->setHeight(height());
        x += m_spacing + widget->width();
      } else if (m_orientation == Vertical) {
        widget->setWidth(width());
        widget->setHeight(widget->minimumHeight()
          + (height() - minimumHeight())/m_widgets.size());
        y += m_spacing + widget->height();
      }
    }
  }
}
