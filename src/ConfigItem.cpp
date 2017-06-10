#include "../include/ConfigItem.hpp"

ConfigItem::ConfigItem(GraphicsItem *parent)
: Widget(parent),
  m_target(nullptr)
{
  m_layout = make<Layout>(Layout::Vertical, this);
  m_layout->setSpacing(5);

  auto title = make<Label>("GraphicsItem");
  title->setAlign(Label::LabelAlign::Center);
  m_layout->push_back(title);

  m_spinBoxPosX = make<SpinBox>();
  m_layout->push_back("X: ", m_spinBoxPosX);
  m_spinBoxPosX->valueChanged([this]() {
    if (m_target)
      m_target->position().setX(m_spinBoxPosX->value());
  });

  m_spinBoxPosY = make<SpinBox>();
  m_layout->push_back("Y: ", m_spinBoxPosY);
  m_spinBoxPosY->valueChanged([this]() {
    if (m_target)
      m_target->position().setY(m_spinBoxPosY->value());
  });

  m_spinBoxZ = make<SpinBox>();
  m_layout->push_back("Z: ", m_spinBoxZ);
  m_spinBoxZ->valueChanged([this]() {
    if (m_target)
      m_target->setZ(m_spinBoxZ->value());
  });

  m_spinBoxThick = make<SpinBox>();
  m_layout->push_back("Épaisseur: ", m_spinBoxThick);
  m_spinBoxThick->valueChanged([this]() {
    if (m_target)
      m_target->setThick(m_spinBoxThick->value());
  });

  m_spinBoxFill = make<SpinBox>();
  m_spinBoxFill->setInfinite(false);
  m_spinBoxFill->setMaximumValue(1);
  m_layout->push_back("Remplir: ", m_spinBoxFill);
  m_spinBoxFill->valueChanged([this]() {
    if (m_target)
      m_target->setFill(m_spinBoxFill->value());
  });

  m_lineEditColor = make<LineEdit>();
  m_layout->push_back("Couleur: ", m_lineEditColor);
  m_lineEditColor->textChanged([this]() {
    //FIXME il faut le faire !
  });

  widthChanged([this]() {
    m_layout->setWidth(width());
  });
  heightChanged([this]() {
    m_layout->setHeight(height());
  });

  m_layout->minimumWidthChanged([this]() {
    m_minimumWidthChanged();
  });
  m_layout->minimumHeightChanged([this]() {
    m_minimumHeightChanged();
  });
}

void ConfigItem::setTarget(const Ptr &target)
{
  m_target = target;
  loadData();
}

size_t ConfigItem::minimumWidth() const
{
  return m_layout->minimumWidth();
}

size_t ConfigItem::minimumHeight() const
{
  return m_layout->minimumHeight();
}

void ConfigItem::meUpdate(const unsigned int time)
{
  loadData();
}

void ConfigItem::loadData()
{
  if (m_target) {
    m_spinBoxPosX->setValue(m_target->position().x());
    m_spinBoxPosY->setValue(m_target->position().y());
    m_spinBoxZ->setValue(m_target->z());
    m_spinBoxThick->setValue(m_target->thick());
    m_spinBoxFill->setValue(m_target->isFill());
    m_lineEditColor->setText(m_target->color().hexaStr());
  }
}
