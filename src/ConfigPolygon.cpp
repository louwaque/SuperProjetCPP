#include "../include/ConfigPolygon.hpp"
#include <GraphicsPolygon.hpp>
#include <GraphicsPoint.hpp>

ConfigPolygon::ConfigPolygon(GraphicsItem *parent)
: ConfigItem(parent)
{
  auto title = make<Label>("Polygone");
  title->setAlign(Label::LabelAlign::Center);
  m_layout->push_back(title);

  m_spinBoxNbPoints = make<SpinBox>();
  m_layout->push_back("Nombre de sommets: ", m_spinBoxNbPoints);
  m_spinBoxNbPoints->valueChanged([this]() {
    auto target = std::dynamic_pointer_cast<GraphicsPolygon>(m_target);
    if (target)
      target->setNbPoints(m_spinBoxNbPoints->value());
    //FIXME il faut attacher les GraphicsPoint
  });
}

void ConfigPolygon::loadData()
{
  ConfigItem::loadData();
  auto target = std::dynamic_pointer_cast<GraphicsPolygon>(m_target);
  if (target)
    m_spinBoxNbPoints->setValue(target->nbPoints());
}
