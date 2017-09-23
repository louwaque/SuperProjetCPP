#ifndef UTF8HELPER_HPP
#define UTF8HELPER_HPP

/*!
 * \file UTF8Helper.hpp
 * \brief Fonctions pour les chaines de caractères codées en UTF-8
 * \author Loïc Escales, Leo Sudreau
 * \version 0.1
 * \date 23 septembre 2017
 */

#include <string>

namespace UTF8Helper {

  size_t size(const std::string &str);

  std::string substr(const std::string &str, std::string::size_type pos = 0, std::string::size_type count = std::string::npos);

  void insert(std::string &str, std::string::size_type index, const std::string& toInsert);

  void erase(std::string &str, std::string::size_type index = 0, std::string::size_type count = std::string::npos);
}

#endif
