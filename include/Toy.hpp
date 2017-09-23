#ifndef TOY_HPP
#define TOY_HPP

#include <GraphicsItem.hpp>
#include <MouseEvent.hpp>
#include <Layout.hpp>

template<typename ConfigHelper>
class Toy : public GraphicsItem
{
public:
  Toy(Ptr target, Ptr anchor, std::shared_ptr<Layout> layout, GraphicsItem *parent = nullptr);

  bool alreadyOpen() const;

protected:
  void meUpdate(const unsigned int time);

private:
  Ptr m_target;
  Ptr m_anchor;
  std::shared_ptr<Layout> m_layout;
  std::shared_ptr<ConfigHelper> m_config;
};

template<typename ConfigHelper>
Toy<ConfigHelper>::Toy(Ptr target, Ptr anchor, std::shared_ptr<Layout> layout, GraphicsItem *parent)
: GraphicsItem(parent),
  m_target(target),
  m_anchor(anchor),
  m_layout(layout),
  m_config(nullptr)
{
  m_config = make<ConfigHelper>();
  m_config->setTarget(m_target);
  m_config->wantClose([this]() {
    m_layout->clear();
  });

  if (m_anchor)
    m_anchor->setColor(Color::Green);
}

template<typename ConfigHelper>
bool Toy<ConfigHelper>::alreadyOpen() const
{
  if (!m_layout || !m_config)
    return false;

  for (int i = 0; i < m_layout->size(); ++i)
    if (*(*m_layout)[i] == *m_config)
      return m_config->parentId() == (*m_layout)[i]->id();

  return false;
}

template<typename ConfigHelper>
void Toy<ConfigHelper>::meUpdate(const unsigned int time)
{
  if (m_layout && m_target && !alreadyOpen() && m_anchor && m_anchor->hasFocus()) {
    m_layout->clear();
    m_layout->push_back(m_config);
  }
}

#endif
