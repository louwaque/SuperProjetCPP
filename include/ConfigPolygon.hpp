#ifndef CONFIGPOLYGON_HPP
#define CONFIGPOLYGON_HPP

/*!
 * \file ConfigPolygon.hpp
 * \brief Classe ConfigPolygon
 * \author Loïc Escales, Leo Sudreau
 * \version 0.1
 * \date 10 juin 2017
 */

#include "ConfigItem.hpp"

/*!
 * \class ConfigPolygon
 * \brief IHM pour modifier un GraphicsPolygon
 */

class ConfigPolygon : public ConfigItem
{
public:
  ConfigPolygon(GraphicsItem *parent = nullptr);

protected:
  void loadData();
  void meHandleEvent(const Event &event);

private:
  void updatePoints();
  Ptr newPoint();
  void popPoint();

private:
  std::vector<Ptr> m_points;
  std::shared_ptr<SpinBox> m_spinBoxNbPoints, m_spinBoxMakeOnClick;
};

#endif
