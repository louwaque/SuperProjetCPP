#include "../include/ConfigPolygon.hpp"
#include <MouseEvent.hpp>
#include <GraphicsPolygon.hpp>
#include <GraphicsPoint.hpp>

ConfigPolygon::ConfigPolygon(GraphicsItem *parent)
: ConfigItem(parent)
{
  auto title = make<Label>("Polygone");
  title->setAlign(Label::LabelAlign::Center);
  m_layout->push_back(title);

  m_spinBoxNbPoints = make<SpinBox>();
  m_spinBoxNbPoints->setMinimumValue(1);
  m_spinBoxNbPoints->setMaximumValue(200);
  m_layout->push_back("Nombre de sommets: ", m_spinBoxNbPoints);
  m_spinBoxNbPoints->valueChanged(boost::bind(&ConfigPolygon::updatePoints, this));

  m_spinBoxMakeOnClick = make<SpinBox>();
  m_spinBoxMakeOnClick->setLabels({"Désactivé", "Activé"});
  m_layout->push_back("Créer un point au clic: ", m_spinBoxMakeOnClick);
}

void ConfigPolygon::loadData()
{
  ConfigItem::loadData();
  auto target = std::dynamic_pointer_cast<GraphicsPolygon>(m_target);
  if (target)
    m_spinBoxNbPoints->setValue(target->nbPoints());
}

void ConfigPolygon::meHandleEvent(const Event &event)
{
  if (event.type() == Event::MouseType) {
    const MouseEvent &mouse = dynamic_cast<const MouseEvent&>(event);
    if (mouse.state() == MouseEvent::ButtonReleased &&
        m_spinBoxMakeOnClick->value() &&
        !isOver(mouse.position()))
      newPoint()->position().set(mouse.position());
  }
}

void ConfigPolygon::updatePoints()
{
  auto target = std::dynamic_pointer_cast<GraphicsPolygon>(m_target);
  if (target) {
    const size_t nb = m_spinBoxNbPoints->value();

    if (nb > 0 && nb != target->nbPoints()) {
      while (nb > target->nbPoints())
        newPoint();

      while (target->nbPoints() > nb)
        popPoint();
    }
  }
}

GraphicsItem::Ptr ConfigPolygon::newPoint()
{
  auto target = std::dynamic_pointer_cast<GraphicsPolygon>(m_target);
  if (target) {
    Point &p = target->newPoint();
    auto gp = make<GraphicsPoint>(target.get());
    gp->position().join(p);
    m_points.push_back(gp);
    return gp;
  } else {
    throw std::runtime_error("ConfigPolygon::newPoint null target");
  }
}

void ConfigPolygon::popPoint()
{
  auto target = std::dynamic_pointer_cast<GraphicsPolygon>(m_target);
  if (target) {
    target->popPoint();
    auto gp = m_points.back();
    gp->setParent();
    m_points.pop_back();
  } else {
    throw std::runtime_error("ConfigPolygon::popPoint null target");
  }
}
