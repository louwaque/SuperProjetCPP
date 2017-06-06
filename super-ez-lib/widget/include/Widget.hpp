#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <boost/signals2/signal.hpp>
#include <boost/bind.hpp>
#include <GraphicsItem.hpp>

class Widget : public GraphicsItem
{
public:
  typedef boost::signals2::signal<void ()>  signal_t;
  typedef signal_t::slot_type slot_t;
  typedef boost::signals2::connection co_t;

  explicit Widget(GraphicsItem *parent = nullptr);
};

#endif
