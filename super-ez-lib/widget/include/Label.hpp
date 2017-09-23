#ifndef LABEL_HPP
#define LABEL_HPP

#include "Widget.hpp"
#include <GraphicsText.hpp>

/*!
 * \class Label
 * \brief Afficher du texte
 * \ingroup widget
 */

class Label : public Widget
{
public:
  enum class LabelAlign {
    Left,
    Right,
    Center
  };

  explicit Label(GraphicsItem *parent = nullptr);
  Label(const std::string &text, GraphicsItem *parent = nullptr);

  inline std::string text() const { return m_text->text(); }
  void setText(const std::string &text);

  inline Font font() const { return m_text->font(); }
  void setFont(const Font &font);

  inline LabelAlign align() const { return m_align; }
  inline void setAlign(const LabelAlign align) { m_align = align; alignText(); }

  size_t minimumWidth() const;
  size_t minimumHeight() const;

  /*!
   * \name Signaux
   */
  ///@{
  inline co_t textChanged(const slot_t &subscriber) { return m_textChanged.connect(subscriber); }
  inline co_t fontChanged(const slot_t &subscriber) { return m_fontChanged.connect(subscriber); }
  ///@}

private:
  void alignText();

private:
  std::shared_ptr<GraphicsText> m_text;
  size_t m_textSize;
  LabelAlign m_align;

  signal_t m_textChanged;
  signal_t m_fontChanged;
};

#endif
