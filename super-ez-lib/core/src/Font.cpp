#include "../include/Font.hpp"

Font::Font(const AvailableFont font)
{
  set(font);
}

void Font::set(const AvailableFont font)
{
  switch (font) {
    default:
    case w6h13:
      m_id = 0;
      m_width = 6;
      m_height = 13;
      break;
    case w8h16:
      m_id = 1;
      m_width = 8;
      m_height = 16;
      break;
    case w10h20:
      m_id = 2;
      m_width = 10;
      m_height = 20;
      break;
    case w12h24:
      m_id = 3;
      m_width = 12;
      m_height = 24;
      break;
  }
}

bool operator==(const Font &l, const Font &r)
{
  return l.id() == r.id();
}

bool operator!=(const Font &l, const Font &r)
{
  return l.id() != r.id();
}

bool operator<(const Font &l, const Font &r)
{
  return l.height() < r.height();
}

bool operator>(const Font &l, const Font &r)
{
  return l.height() > r.height();
}

std::ostream &operator<<(std::ostream &os, const Font &font)
{
  return os << "id " << font.id() << " height " << font.height() << " width " << font.width();
}
