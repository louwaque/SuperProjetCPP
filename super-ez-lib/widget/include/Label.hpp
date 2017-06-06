#ifndef LABEL_HPP
#define LABEL_HPP

#include "Widget.hpp"
#include <GraphicsText.hpp>

class Label : public Widget
{
public:
  explicit Label(GraphicsItem *parent = nullptr);
  Label(const std::string &text, GraphicsItem *parent = nullptr);

  inline std::string text() const { return m_text->text(); }
  void setText(const std::string &text);

  size_t minimumWidth() const;
  size_t minimumHeight() const;

  inline co_t textChanged(const slot_t &subscriber) { return m_textChanged.connect(subscriber); }

private:
  GraphicsText *m_text;

  signal_t m_textChanged;
};

#endif
