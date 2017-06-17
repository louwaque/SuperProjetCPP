#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <cmath>
#include <boost/signals2/signal.hpp>
#include <boost/bind.hpp>
#include <GraphicsRectangle.hpp>

/**
 * \defgroup widget Widget
 * \brief Classes pour créer des IHM
 */

/*!
 * \class Widget
 * \brief Classe de base
 * \ingroup widget
 */

class Widget : public GraphicsItem
{
public:
  typedef boost::signals2::signal<void ()>  signal_t;
  typedef signal_t::slot_type slot_t;
  typedef boost::signals2::connection co_t;

  explicit Widget(GraphicsItem *parent = nullptr);

  inline size_t width() const { return std::max(m_width, minimumWidth()); }

  void setWidth(const size_t width);

  inline size_t height() const { return std::max(m_height, minimumHeight()); }

  void setHeight(const size_t height);

  virtual size_t minimumWidth() const { return 0; }

  virtual size_t minimumHeight() const { return 0; }

  /*!
   * \name Signaux
   */
  ///@{
  inline co_t widthChanged(const slot_t &subscriber) { return m_widthChanged.connect(subscriber); }
  inline co_t heightChanged(const slot_t &subscriber) { return m_heightChanged.connect(subscriber); }
  inline co_t minimumWidthChanged(const slot_t &subscriber) { return m_minimumWidthChanged.connect(subscriber); }
  inline co_t minimumHeightChanged(const slot_t &subscriber) { return m_minimumHeightChanged.connect(subscriber); }
  ///@}

protected:
  bool meIsOver(const Point &absoluteP);

protected:
  signal_t m_minimumWidthChanged;
  signal_t m_minimumHeightChanged;

private:
  size_t m_width;
  size_t m_height;

  //FIXME ajouter margin et padding ?

  signal_t m_widthChanged;
  signal_t m_heightChanged;
};

#endif
