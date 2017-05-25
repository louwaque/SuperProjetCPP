#define BOOST_TEST_MODULE COLOR
#include <boost/test/unit_test.hpp>

#include "../include/Color.hpp"

BOOST_AUTO_TEST_CASE(red)
{
  uint8_t value = 10;
  Color c(value, 0, 0);
  BOOST_CHECK(c.red() == value);
  BOOST_CHECK(c.green() != value);
  BOOST_CHECK(c.blue() != value);
}

BOOST_AUTO_TEST_CASE(setRed)
{
  uint8_t value = 10;
  Color c(uint8_t(0), 0, 0);
  c.setRed(value);
  BOOST_CHECK(c.red() == value);
  BOOST_CHECK(c.green() != value);
  BOOST_CHECK(c.blue() != value);
}
