#include "../include/UTF8Helper.hpp"
#include <boost/locale.hpp>
#include <iostream>

namespace ba = boost::locale::boundary;

boost::locale::generator gen;

size_t UTF8Helper::size(const std::string &str)
{
  size_t size = 0;
  ba::ssegment_index map(ba::character, str.begin(), str.end(), gen(""));
  for(auto it = map.begin(), end = map.end(); it != end; ++it)
    ++size;

  return size;
}

std::string UTF8Helper::substr(const std::string &str, std::string::size_type pos, std::string::size_type count)
{
  if (count == std::string::npos)
    count = size(str) - pos;

  std::string sub;
  ba::ssegment_index map(ba::character, str.begin(), str.end(), gen(""));
  auto it = map.begin();

  for (size_t i = 0; i < pos; ++i)
    ++it;

  for(size_t i = 0; i < count; ++i, ++it)
    sub += *it;

  return sub;
}

void UTF8Helper::insert(std::string &str, std::string::size_type index, const std::string& toInsert)
{
  std::string tmp;
  tmp += substr(str, 0, index);
  tmp += toInsert;
  tmp += substr(str, index);
  str = tmp;
}

void UTF8Helper::erase(std::string &str, std::string::size_type index, std::string::size_type count)
{
  std::string tmp;
  tmp += substr(str, 0, index);
  tmp += substr(str, index + count);
  str = tmp;
}
