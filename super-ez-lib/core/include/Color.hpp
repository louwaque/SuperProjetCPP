#ifndef COLOR_HPP
#define COLOR_HPP

/*!
 * \file Color.hpp
 * \brief Classe Color
 * \author Loïc Escales, Leo Sudreau
 * \version 0.1
 * \date 23 mai 2017
 */

#include <cstdint>
#include <string>
#include <ez-lib/ez-draw++.hpp>

/*!
 * \class Color
 * \brief Permet la gestion des coulours des différentes *entitées
 *
 */

class Color {

public:

  /*!
 * \enum Colors
 * \brief Constantes de couleurs
 *
 * Str_err_e est une série de constantes prédéfinie pour les * différentes couleurs possibles
 */

  enum Colors : uint32_t {
    Black = 0x000000,
    White = 0xFFFFFF,
    Grey = 0x969696,
    Red = 0xFF0000,
    Green = 0x00FF00,
    Blue = 0x0000FF,
    Yellow = 0xFFFF00,
    Cyan = 0x00FFFF,
    Mangenta = 0xFF00FF
  };



  //pas super top

  /*!
   * \brief Constructeur par default de la classe Colors.
   *
   * Crée une instance de Colors.
   * La couleur par default est noir
   */

  explicit Color(const Colors color = Black);

  /*!
   * \brief Constructeur de Color avec des couleurs en parametres
   *
   * Crée une instance de Colors celon le principe du RGB
   * Les valeurs sont comprises en 0 et 255.
   * \param red: valeur de la premier couleur primaire, rouge.
   * \param green: valeur de la seconde couleur primaire, vert.
   * \param blue: valeur de la troisieme couleur primaire, bleu.
   * La synthese additivité donnera la couleur final de l'instance Colors.
   */

  Color(const uint8_t red, const uint8_t green, const uint8_t blue);

  /*!
   * \brief Constructeur de Color avec la teinte,la saturation et la valeur en paramètres ( système HVS ).
   *
   * Crée une instance de Colors celon le principe HVS
   * \param hue: valeur de la teinte.
   * \param saturation: valeur de la saturation.
   * \param value: valeur de la valeur.
   *
   */

  Color(const double hue, const double saturation, const double value);


    /*!
     * \brief Constructeur de Color avec une teinte de gris en parametres
     *
     * Crée une instance de Colors celon une valeur de gris
     * \param grey: valeur de la teinte
     *
     */

  explicit Color(const ulong grey);

  /*!
   *  \brief Recupere la valeur de la premier couleur ( systeme RGB ).
   *
   *  \return valeur de la couleur rouge.
   */

  inline uint8_t red() const { return (m_color & Red) >> 16; }

  /*!
   *  \brief Modifie la valeur de la premier couleur ( systeme RGB ).
   *
   *  \param red: valeur de la couleur rouge.
   */

  void setRed(const uint8_t red);

  /*!
   *  \brief Recupere la valeur de la deuxieme couleur ( systeme RGB ).
   *
   *  \return valeur de la couleur vert.
   */

  inline uint8_t green() const { return (m_color & Green) >>8; }

  /*!
   *  \brief Modifie la valeur de la seconde couleur ( systeme RGB ).
   *
   *  \param red: valeur de la couleur vert.
   */

  void setGreen(const uint8_t green);

  /*!
   *  \brief Recupere la valeur de la troisieme couleur ( systeme RGB ).
   *
   *  \return valeur de la couleur bleu.
   */

  inline uint8_t blue() const { return m_color & Blue; }

  /*!
   *  \brief Modifie la valeur de la troisieme couleur ( systeme RGB ).
   *
   *  \param red: valeur de la couleur bleu.
   */

  void setBlue(const uint8_t blue);

  /*!
   *  \brief Recupere la valeur de teinte ( systeme HSV ).
   *
   *  \return valeur de la teinte.
   */

  double hue() const;

  /*!
   *  \brief Modifie la valeur de la teinte ( systeme HSV ).
   *
   *  \param hue: valeur de la teinte
   */

  inline void setHue(const double hue) { m_color = EZWindow::getHSV(hue, saturation(), value()); }

  /*!
   *  \brief Recupere la valeur de saturation ( system HSV ).
   *
   *  \return valeur de la saturation.
   */

  double saturation() const;

  /*!
   *  \brief Modifie la valeur de la saturation ( system HSV ).
   *
   *  \param saturation: valeur de la saturation
   */

  inline void setSaturation(const double saturation) { m_color = EZWindow::getHSV(hue(), saturation, value()); }

  /*!
   *  \brief Recupere la valeur de la valeur ( system HSV ).
   *
   *  \return la valeur de la valeur.
   */

  double value() const;

  /*!
   *  \brief Modifie la valeur de la valeur ( system HSV ).
   *
   *  \param saturation: valeur de la valeur.
   */

  inline void setValue(const double value) { m_color = EZWindow::getHSV(hue(), saturation(), value); }

  /*!
   *  \brief Recupere la valeur de la couleur en hexadecimal.
   *
   *  \return la valeur de la couleur.
   */

  inline uint32_t hexa() const { return m_color; }

  /*!
   *  \brief Modifie  la couleur grâce à une valeur en exadecimal.
   *
   *  \param saturation: valeur de la couleur.
   */

  inline void setHexa(const uint32_t hexa) { m_color = hexa; }

  /*!
   *  \brief Recupere la valeur de la couleur en hexadecimal sous forme de chaine de caractere.
   *
   *  \return chaine de caractere contenant la valeur de la couleur.
   */

  std::string hexaStr() const;

private:

  uint32_t m_color; /*!< La couleur */

};

#endif
