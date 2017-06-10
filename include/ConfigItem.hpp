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

  GraphicsItem *target() const { return m_target; }
  void setTarget(GraphicsItem *target = nullptr);

  size_t minimumWidth() const;
  size_t minimumHeight() const;

protected:
  virtual void loadData();

protected:
  GraphicsItem *m_target;

  Layout *m_layout;

private:
  SpinBox *m_spinBoxPosX, *m_spinBoxPosY, *m_spinBoxZ, *m_spinBoxThick;
  LineEdit *m_lineEditColor;
};

#endif
