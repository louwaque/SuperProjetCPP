#ifndef FONT_HPP
#define FONT_HPP

#include <iostream>

/*!
 * \class Font
 * \ingroup core
 * \brief Représente une police d'écriture
 */

class Font
{
public:
  enum AvailableFont {
    w6h13,
    w8h16,
    w10h20,
    w12h24
  };

  Font(const AvailableFont font = w6h13);

  void set(const AvailableFont font);

  inline uint id() const { return m_id; }
  inline size_t width() const { return m_width; }
  inline size_t height() const { return m_height; }

  template<class Archive>
  void serialize(Archive& ar, const unsigned int version){
    ar & m_id;
  }

private:
  uint m_id;
  size_t m_width;
  size_t m_height;
};

bool operator==(const Font &l, const Font &r);
bool operator!=(const Font &l, const Font &r);
bool operator<(const Font &l, const Font &r);
bool operator>(const Font &l, const Font &r);
std::ostream &operator<<(std::ostream &os, const Font &font);

#endif
