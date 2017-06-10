#ifndef TOY_HPP
#define TOY_HPP

#include <GraphicsItem.hpp>
#include <MouseEvent.hpp>
#include <Layout.hpp>

template<typename ConfigHelper>
class Toy : public GraphicsItem
{
public:
  Toy(Ptr target, std::shared_ptr<Layout> layout, const Ptr parent = nullptr);

protected:
  void meHandleEvent(const Event &event);

private:
  Ptr m_target;
  std::shared_ptr<Layout> m_layout;
  bool m_alreadyOpen;
};

template<typename ConfigHelper>
Toy<ConfigHelper>::Toy(Ptr target, std::shared_ptr<Layout> layout, const Ptr parent)
: GraphicsItem(parent),
  m_target(target),
  m_layout(layout),
  m_alreadyOpen(false)
{}

template<typename ConfigHelper>
void Toy<ConfigHelper>::meHandleEvent(const Event &event)
{
  if (m_target && m_layout && event.type() == Event::MouseType) {
    const MouseEvent &mouse = dynamic_cast<const MouseEvent&>(event);
    if (mouse.state() != MouseEvent::MouseMoved) {
      if (m_target->hasFocus()) {
        if (!m_alreadyOpen) {
          m_layout->clear();
          auto config = make<ConfigHelper>();
          config->setTarget(m_target);
          m_layout->push_back(config);
          m_alreadyOpen = true;
          std::cerr << "OPEN" << '\n';
        }
      }
      // if (m_alreadyOpen && !m_layout->isOver(mouse.position())) {
      //   m_layout->clear();
      //   m_alreadyOpen = false;
      //   std::cerr << "CLOSE" << '\n';
      // }
      std::cerr << '\n';
      std::cerr << "m_alreadyOpen " << m_alreadyOpen << '\n';
      std::cerr << "layout->isOver " << m_layout->isOver(mouse.position()) << '\n';
    }
  }
}

#endif
