#include "../include/SpinBox.hpp"
#include "../include/LineEdit.hpp"
#include "../include/Button.hpp"

SpinBox::SpinBox(const Id &parent)
: Widget(parent),
  m_value(0),
  m_minimumValue(0),
  m_maximumValue(100),
  m_step(1),
  m_isInfinite(true),
  m_layout(nullptr)
{
  m_layout = make<Layout>(this);

  auto minusButton = make<Button>("-");
  m_layout->push_back(minusButton);
  minusButton->clicked([this]() {
    setValue(m_value - m_step);
  });

  auto lineEdit = make<LineEdit>();
  lineEdit->setZ(-1);
  lineEdit->setText(std::to_string(m_value));
  m_layout->push_back(lineEdit);
  lineEdit->accepted([this, lineEdit]() {
    try {
      setValue(std::stoi(lineEdit->text()));
    } catch (std::invalid_argument &err) {
      lineEdit->setText(std::to_string(m_value));
    }
  });

  auto plusButton = make<Button>("+");
  m_layout->push_back(plusButton);
  plusButton->clicked([this]() {
    setValue(m_value + m_step);
  });

  valueChanged([this, lineEdit]() {
    lineEdit->setText(std::to_string(m_value));
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

SpinBox::SpinBox(const Ptr &parent)
: SpinBox()
{
  setParent(parent);
}

SpinBox::SpinBox(const GraphicsItem *parent)
: SpinBox()
{
  setParent(parent);
}

void SpinBox::setValue(int value)
{
  if (value != m_value) {
    if (!m_isInfinite) {
      if (value < m_minimumValue)
        value = m_minimumValue;

      if (value > m_maximumValue)
        value = m_maximumValue;
    }

    m_value = value;
    m_valueChanged();
  }
}

void SpinBox::setMinimumValue(const int minimumValue)
{
  setInfinite(false);
  if (minimumValue != m_minimumValue) {
    m_minimumValue = minimumValue;
    setValue(m_value);
    m_minimumValueChanged();
  }
}

void SpinBox::setMaximumValue(const int maximumValue)
{
  setInfinite(false);
  if (maximumValue != m_maximumValue) {
    m_maximumValue = maximumValue;
    setValue(m_value);
    m_maximumValueChanged();
  }
}

void SpinBox::setInfinite(const bool isInfinite)
{
  m_isInfinite = isInfinite;
  setValue(m_value);
}

size_t SpinBox::minimumWidth() const
{
  return m_layout->minimumWidth();
}

size_t SpinBox::minimumHeight() const
{
  return m_layout->minimumHeight();
}
