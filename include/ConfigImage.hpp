#ifndef CONFIGIMAGE_HPP
#define CONFIGIMAGE_HPP

/*!
 * \file ConfigImage.hpp
 * \brief Classe ConfigImage
 * \author Loïc Escales, Leo Sudreau
 * \version 0.1
 * \date 10 juin 2017
 */

#include "ConfigItem.hpp"

/*!
 * \class ConfigImage
 * \brief IHM pour modifier un GraphicsImage
 */

class ConfigImage : public ConfigItem
{
public:
  ConfigImage(GraphicsItem *parent = nullptr);

protected:
  void loadData();

private:
  std::shared_ptr<LineEdit> m_lineEditFileName, m_lineEditFill;
  std::shared_ptr<SpinBox> m_spinBoxAlpha, m_spinBoxOpacity, m_spinBoxScale;
  std::shared_ptr<Button> m_buttonVerticalSymmetry, m_buttonHorizontalSymmetry;
};

#endif
