#define BOOST_TEST_MODULE SERIALIZATION
#include <boost/test/unit_test.hpp>

#include <boost/serialization/vector.hpp>
#include <boost/serialization/shared_ptr.hpp>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include "../include/Color.hpp"
#include "../include/Font.hpp"
#include "../include/Point.hpp"
#include "../include/GroupPoints.hpp"

#include <sstream>

BOOST_AUTO_TEST_CASE(COLOR)
{
  Color color1(uint8_t(10), uint8_t(20), uint8_t(30)), color2;

  std::stringstream stream;
  boost::archive::text_oarchive oArchive(stream);
  oArchive << color1;

  boost::archive::text_iarchive iArchive(stream);
  iArchive >> color2;

  BOOST_REQUIRE_EQUAL(color1.hexa(), color2.hexa());
}

BOOST_AUTO_TEST_CASE(FONT)
{
  Font font1(Font::w10h20), font2;

  std::stringstream stream;
  boost::archive::text_oarchive oArchive(stream);
  oArchive << font1;

  boost::archive::text_iarchive iArchive(stream);
  iArchive >> font2;

  BOOST_REQUIRE_EQUAL(font1, font2);
}

// BOOST_AUTO_TEST_CASE(POINT)
// {
//   Point p1(10, 20), p2(-39, 440), p3(880, -83), p4, p5, p6;
//
//   p2.setOrigin(&p1);
//   p3.join(p2);
//
//   std::stringstream stream;
//   boost::archive::text_oarchive oArchive(stream);
//   oArchive << p1 << p2 << p3;
//
//   boost::archive::text_iarchive iArchive(stream);
//   iArchive >> p4 >> p5 >> p6;
//
//   BOOST_REQUIRE_EQUAL(p1, p4);
//   BOOST_REQUIRE_EQUAL(p2, p5);
//   BOOST_REQUIRE_EQUAL(p3, p6);
// }
