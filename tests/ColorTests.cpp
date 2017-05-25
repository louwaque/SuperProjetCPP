#define BOOST_TEST_MODULE COLOR
#include <boost/test/unit_test.hpp>

#include "../include/Color.hpp"
#include <iostream>

BOOST_AUTO_TEST_CASE(red)
{
  uint8_t value = 255;
  Color c(value, 0, 0);
  BOOST_REQUIRE_EQUAL(c.red(), value);
  BOOST_REQUIRE_NE(c.green(), value);
  BOOST_REQUIRE_NE(c.blue(), value);
}

BOOST_AUTO_TEST_CASE(setRed)
{
  uint8_t value = 10;
  Color c(uint8_t(0), 0, 0);
  c.setRed(value);
  BOOST_REQUIRE_EQUAL(c.red(), value);
  BOOST_REQUIRE_NE(c.green(), value);
  BOOST_REQUIRE_NE(c.blue(), value);
}

BOOST_AUTO_TEST_CASE(green)
{
  uint8_t value = 255;
  Color c(0, value, 0);
  BOOST_REQUIRE_NE(c.red(), value);
  BOOST_REQUIRE_EQUAL(c.green(), value);
  BOOST_REQUIRE_NE(c.blue(), value);
}

BOOST_AUTO_TEST_CASE(setGreen)
{
  uint8_t value = 10;
  Color c(uint8_t(0), 0, 0);
  c.setGreen(value);
  BOOST_REQUIRE_NE(c.red(), value);
  BOOST_REQUIRE_EQUAL(c.green(), value);
  BOOST_REQUIRE_NE(c.blue(), value);
}

BOOST_AUTO_TEST_CASE(blue)
{
  uint8_t value = 255;
  Color c(0, 0, value);
  BOOST_REQUIRE_NE(c.red(), value);
  BOOST_REQUIRE_NE(c.green(), value);
  BOOST_REQUIRE_EQUAL(c.blue(), value);
}

BOOST_AUTO_TEST_CASE(setBlue)
{
  uint8_t value = 10;
  Color c(uint8_t(0), 0, 0);
  c.setBlue(value);
  BOOST_REQUIRE_NE(c.red(), value);
  BOOST_REQUIRE_NE(c.green(), value);
  BOOST_REQUIRE_EQUAL(c.blue(), value);
}
