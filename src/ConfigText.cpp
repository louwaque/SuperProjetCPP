#include "../include/ConfigText.hpp"
#include <GraphicsText.hpp>

ConfigText::ConfigText(GraphicsItem *parent)
: ConfigItem(parent)
{
  auto title = make<Label>("Texte");
  title->setAlign(Label::LabelAlign::Center);
  m_layout->push_back(title);

  m_lineEditText = make<LineEdit>();
  m_layout->push_back(m_lineEditText);
  m_lineEditText->textChanged([this]() {
    auto target = std::dynamic_pointer_cast<GraphicsText>(m_target);
    if (target)
      target->setText(m_lineEditText->text());
  });

  m_spinBoxSize = make<SpinBox>();
  m_spinBoxSize->setLabels({"l6h13", "l8h16", "l10h20", "l12h24"});
  m_layout->push_back("Police: ", m_spinBoxSize);
  m_spinBoxSize->valueChanged([this]() {
    auto target = std::dynamic_pointer_cast<GraphicsText>(m_target);
    if (target)
      target->setFont(static_cast<Font::AvailableFont>(m_spinBoxSize->value()));
  });
}

void ConfigText::loadData()
{
  ConfigItem::loadData();
  auto target = std::dynamic_pointer_cast<GraphicsText>(m_target);
  if (target) {
    m_lineEditText->setText(target->text());
    m_spinBoxSize->setValue(static_cast<int>(target->font().id()));
  }
}
