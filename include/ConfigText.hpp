#ifndef CONFIGTEXT_HPP
#define CONFIGTEXT_HPP

/*!
 * \file ConfigText.hpp
 * \brief Classe ConfigText
 * \author Loïc Escales, Leo Sudreau
 * \version 0.1
 * \date 10 juin 2017
 */

#include "ConfigItem.hpp"

/*!
 * \class ConfigText
 * \brief IHM pour modifier un GraphicsText
 */

class ConfigText : public ConfigItem
{
public:
  ConfigText(GraphicsItem *parent = nullptr);

protected:
  void loadData();

private:
  std::shared_ptr<LineEdit> m_lineEditText;
  std::shared_ptr<SpinBox> m_spinBoxSize;
};

#endif
