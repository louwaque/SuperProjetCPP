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
  explicit Label(const Id &parent = boost::uuids::nil_generator()());
  explicit Label(const Ptr &parent);
  explicit Label(const GraphicsItem *parent);

  Label(const std::string &text, const Id &parent = boost::uuids::nil_generator()());
  Label(const std::string &text, const Ptr &parent);
  Label(const std::string &text, const GraphicsItem *parent);

  inline std::string text() const { return m_text->text(); }
  void setText(const std::string &text);

  size_t minimumWidth() const;
  size_t minimumHeight() const;

  /*!
   * \name Signaux
   */
  ///@{
  inline co_t textChanged(const slot_t &subscriber) { return m_textChanged.connect(subscriber); }
  ///@}

private:
  void alignText();

private:
  std::shared_ptr<GraphicsText> m_text;

  signal_t m_textChanged;
};

#endif
