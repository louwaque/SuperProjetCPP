#include "../include/ConfigImage.hpp"
#include <GraphicsImage.hpp>

ConfigImage::ConfigImage(GraphicsItem *parent)
: ConfigItem(parent)
{
  auto title = make<Label>("Image");
  title->setAlign(Label::LabelAlign::Center);
  m_layout->push_back(title);

  m_lineEditFileName = make<LineEdit>();
  m_layout->push_back("Charger: ", m_lineEditFileName);
  m_lineEditFileName->accepted([this]() {
    auto target = std::dynamic_pointer_cast<GraphicsImage>(m_target);
    if (target && m_lineEditFileName->text() != "Impossible de charger l'image.") {
      try {
        target->image().setFileName(m_lineEditFileName->text());
      } catch (const std::runtime_error &error) {
        m_lineEditFileName->setText("Impossible de charger l'image.");
        std::cerr << error.what() << std::endl;
      }
    }
  });

  m_lineEditFill = make<LineEdit>();
  m_layout->push_back("Remplir: ", m_lineEditFill);
  m_lineEditFill->accepted([this]() {
    if (m_lineEditFill->text() != "") {
      auto target = std::dynamic_pointer_cast<GraphicsImage>(m_target);
      if (target)
        target->image().fill(m_lineEditFill->text(), 255);
      m_lineEditFill->setText("");
    }
  });

  m_spinBoxScale = make<SpinBox>();
  m_spinBoxScale->setMinimumValue(1);
  m_spinBoxScale->setValue(100);
  m_layout->push_back("Zoomer: ", m_spinBoxScale);
  m_spinBoxScale->valueChanged([this]() {
    if (m_spinBoxScale->value() != 100) {
      auto target = std::dynamic_pointer_cast<GraphicsImage>(m_target);
      if (target)
        target->image() = target->image().scale(m_spinBoxScale->value()/100.0);
      m_spinBoxScale->setValue(100);
    }
  });

  m_spinBoxAlpha = make<SpinBox>();
  m_spinBoxAlpha->setLabels({"Désactivé", "Activé"});
  m_layout->push_back("Alpha: ", m_spinBoxAlpha);
  m_spinBoxAlpha->valueChanged([this]() {
    auto target = std::dynamic_pointer_cast<GraphicsImage>(m_target);
    if (target)
      target->image().setAlpha(m_spinBoxAlpha->value());
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

  m_buttonVerticalSymmetry = make<Button>("Miroir vertical");
  m_layout->push_back(m_buttonVerticalSymmetry);
  m_buttonVerticalSymmetry->clicked([this]() {
    auto target = std::dynamic_pointer_cast<GraphicsImage>(m_target);
    if (target)
      target->image() = target->image().verticalSymmetry();
  });

  m_buttonHorizontalSymmetry = make<Button>("Miroir horizontal");
  m_layout->push_back(m_buttonHorizontalSymmetry);
  m_buttonHorizontalSymmetry->clicked([this]() {
    auto target = std::dynamic_pointer_cast<GraphicsImage>(m_target);
    if (target)
      target->image() = target->image().horizontalSymmetry();
  });
}

void ConfigImage::loadData()
{
  ConfigItem::loadData();
  auto target = std::dynamic_pointer_cast<GraphicsImage>(m_target);
  if (target) {
    m_spinBoxAlpha->setValue(target->image().hasAlpha());
    m_spinBoxOpacity->setValue(target->image().opacity());
  }
}
