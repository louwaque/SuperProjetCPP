#include "../include/ConfigImage.hpp"
#include <GraphicsImage.hpp>

ConfigImage::ConfigImage(GraphicsItem *parent)
: ConfigItem(parent)
{
  auto title = make<Label>("Image");
  title->setAlign(Label::LabelAlign::Center);
  m_layout->push_back(title);

  m_lineEditFileName = make<LineEdit>();
  m_layout->push_back(m_lineEditFileName);
  m_lineEditFileName->accepted([this]() {
    auto target = std::dynamic_pointer_cast<GraphicsImage>(m_target);
    if (target)
      target->image().setFileName(m_lineEditFileName->text());
  });

  m_spinBoxOpacity = make<SpinBox>();
  m_spinBoxOpacity->setMinimumValue(0);
  m_spinBoxOpacity->setMaximumValue(255);
  m_layout->push_back("Opacité: ", m_spinBoxOpacity);
  m_spinBoxOpacity->valueChanged([this]() {
    auto target = std::dynamic_pointer_cast<GraphicsImage>(m_target);
    if (target)
      target->image().setOpacity(m_spinBoxOpacity->value());
  });
}

void ConfigImage::loadData()
{
  ConfigItem::loadData();
  auto target = std::dynamic_pointer_cast<GraphicsImage>(m_target);
  if (target) {
    m_spinBoxOpacity->setValue(target->image().opacity());
  }
}
