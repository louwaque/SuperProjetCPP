#include "../include/SpinBox.hpp"
#include "../include/Button.hpp"

SpinBox::SpinBox(GraphicsItem *parent)
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

  m_lineEdit = make<LineEdit>();
  m_lineEdit->setZ(-1);
  m_layout->push_back(m_lineEdit);
  m_lineEdit->accepted([this]() {
    try {
      setValue(std::stoi(m_lineEdit->text()));
    } catch (std::invalid_argument &err) {
      updateLineEditText();
    }
  });

  auto plusButton = make<Button>("+");
  m_layout->push_back(plusButton);
  plusButton->clicked([this]() {
    setValue(m_value + m_step);
  });

  valueChanged(boost::bind(&SpinBox::updateLineEditText, this));

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

  m_valueChanged();
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

void SpinBox::setLabels(const std::vector<std::string> &labels)
{
  m_labels = labels;
  m_lineEdit->setEditable(m_labels.empty());
  if (!m_labels.empty()) {
    setMinimumValue(0);
    setMaximumValue(m_labels.size() - 1);
  }
  m_valueChanged();
}

size_t SpinBox::minimumWidth() const
{
  return m_layout->minimumWidth();
}

size_t SpinBox::minimumHeight() const
{
  return m_layout->minimumHeight();
}

void SpinBox::updateLineEditText()
{
  if (0 <= m_value && m_value < m_labels.size())
    m_lineEdit->setText(m_labels[m_value]);
  else
    m_lineEdit->setText(std::to_string(m_value));
}
