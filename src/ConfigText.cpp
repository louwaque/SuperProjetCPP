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
  m_lineEditText->accepted([this]() {
    auto target = std::dynamic_pointer_cast<GraphicsText>(m_target);
    if (target)
      target->setText(m_lineEditText->text());
  });
}

void ConfigText::loadData()
{
  ConfigItem::loadData();
  auto target = std::dynamic_pointer_cast<GraphicsText>(m_target);
  if (target)
    m_lineEditText->setText(target->text());
}
