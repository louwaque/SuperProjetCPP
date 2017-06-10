#ifndef CONFIGITEM_HPP
#define CONFIGITEM_HPP

/*!
 * \file ConfigItem.hpp
 * \brief Classe ConfigItem
 * \author Loïc Escales, Leo Sudreau
 * \version 0.1
 * \date 10 juin 2017
 */

#include <Layout.hpp>
#include <Label.hpp>
#include <LineEdit.hpp>
#include <SpinBox.hpp>

/*!
 * \class ConfigItem
 * \brief IHM pour modifier un GraphicsItem
 */

class ConfigItem : public Widget
{
public:
  ConfigItem(GraphicsItem *parent = nullptr);

  Ptr target() const { return m_target; }
  void setTarget(const Ptr &target = nullptr);

  size_t minimumWidth() const;
  size_t minimumHeight() const;

protected:
  void meUpdate(const unsigned int time);
  virtual void loadData();

protected:
  Ptr m_target;
  std::shared_ptr<Layout> m_layout;

private:
  unsigned int m_elapsedTime;
  std::shared_ptr<SpinBox> m_spinBoxPosX, m_spinBoxPosY, m_spinBoxZ, m_spinBoxThick, m_spinBoxFill;
  std::shared_ptr<LineEdit> m_lineEditColor;
};

#endif
