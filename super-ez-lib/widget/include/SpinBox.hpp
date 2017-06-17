#ifndef SPINBOX_HPP
#define SPINBOX_HPP

#include "Widget.hpp"
#include "Layout.hpp"
#include "LineEdit.hpp"

/*!
 * \class Label
 * \brief Afficher du texte
 * \ingroup widget
 */

class SpinBox : public Widget
{
public:
  explicit SpinBox(GraphicsItem *parent = nullptr);

  inline int value() const { return m_value; }
  void setValue(int value);

  inline int minimumValue() const { return m_minimumValue; }
  void setMinimumValue(const int minimumValue);

  inline int maximumValue() const { return m_maximumValue; }
  void setMaximumValue(const int maximumValue);

  inline int step() const { return m_step; }
  inline void setStep(const int step) { m_step = step; }

  inline bool isInfinite() const { return m_isInfinite; }
  void setInfinite(const bool isInfinite);

  std::vector<std::string> labels() const { return m_labels; }
  void setLabels(const std::vector<std::string> &labels);

  size_t minimumWidth() const;
  size_t minimumHeight() const;

  /*!
   * \name Signaux
   */
  ///@{
  inline co_t valueChanged(const slot_t &subscriber) { return m_valueChanged.connect(subscriber); }
  inline co_t minimumValueChanged(const slot_t &subscriber) { return m_minimumValueChanged.connect(subscriber); }
  inline co_t maximumValueChanged(const slot_t &subscriber) { return m_maximumValueChanged.connect(subscriber); }
  ///@}

private:
  void updateLineEditText();

private:
  int m_value, m_minimumValue, m_maximumValue, m_step;
  bool m_isInfinite;
  std::vector<std::string> m_labels;
  std::shared_ptr<Layout> m_layout;
  std::shared_ptr<LineEdit> m_lineEdit;

  signal_t m_valueChanged, m_minimumValueChanged, m_maximumValueChanged;
};

#endif
