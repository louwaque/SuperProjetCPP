#define BOOST_TEST_MODULE POINT
#include <boost/test/unit_test.hpp>
#include "../include/Point.hpp"

BOOST_AUTO_TEST_CASE(constructor)
{
  Point p1, p2(10, 20), p3(p2);
  BOOST_REQUIRE_EQUAL(p1.x(), 0);
  BOOST_REQUIRE_EQUAL(p1.y(), 0);
  BOOST_REQUIRE_EQUAL(p2.x(), 10);
  BOOST_REQUIRE_EQUAL(p2.y(), 20);
  BOOST_REQUIRE_EQUAL(p3.x(), 10);
  BOOST_REQUIRE_EQUAL(p3.y(), 20);
}

BOOST_AUTO_TEST_CASE(setRelativeter)
{
  Point p;

  p.setRelativeX(10);
  BOOST_REQUIRE_EQUAL(p.x(), 10);
  BOOST_REQUIRE_EQUAL(p.y(), 0);

  p.setRelativeX(0);
  p.setRelativeY(20);
  BOOST_REQUIRE_EQUAL(p.x(), 0);
  BOOST_REQUIRE_EQUAL(p.y(), 20);

  p.setRelative(30, 30);
  BOOST_REQUIRE_EQUAL(p.x(), 30);
  BOOST_REQUIRE_EQUAL(p.y(), 30);
}

BOOST_AUTO_TEST_CASE(group)
{
  Point p1(10, 10), p2(20, 20), p3(30, 30);

  p2.join(p1);
  p3.join(p1);
  BOOST_REQUIRE_EQUAL(p1.relative(), Point(10, 10));
  BOOST_REQUIRE_EQUAL(p1.relative(), p2.relative());
  BOOST_REQUIRE_EQUAL(p1.relative(), p3.relative());

  p1.setRelative(40, 40);
  BOOST_REQUIRE_EQUAL(p1.relative(), Point(40, 40));
  BOOST_REQUIRE_EQUAL(p1.relative(), p2.relative());
  BOOST_REQUIRE_EQUAL(p1.relative(), p3.relative());

  p2.setRelative(50, 50);
  BOOST_REQUIRE_EQUAL(p1.relative(), Point(50, 50));
  BOOST_REQUIRE_EQUAL(p1.relative(), p2.relative());
  BOOST_REQUIRE_EQUAL(p1.relative(), p3.relative());

  p3.setRelative(60, 60);
  BOOST_REQUIRE_EQUAL(p1.relative(), Point(60, 60));
  BOOST_REQUIRE_EQUAL(p1.relative(), p2.relative());
  BOOST_REQUIRE_EQUAL(p1.relative(), p3.relative());

  p2.beAlone();
  p2.setRelative(10, 10);
  p1.setRelative(0, 0);
  BOOST_REQUIRE_EQUAL(p1.relative(), Point(0, 0));
  BOOST_REQUIRE_EQUAL(p2.relative(), Point(10, 10));
  BOOST_REQUIRE_EQUAL(p1.relative(), p3.relative());

  p3.beAlone();
  p1.setRelative(-10, -10);
  p3.setRelative(30, 30);
  BOOST_REQUIRE_EQUAL(p1.relative(), Point(-10, -10));
  BOOST_REQUIRE_EQUAL(p2.relative(), Point(10, 10));
  BOOST_REQUIRE_EQUAL(p3.relative(), Point(30, 30));

  p2.join(p1);
  p3.join(p2);
  p1.setRelative(0, 0);
  BOOST_REQUIRE_EQUAL(p1.relative(), Point(0, 0));
  BOOST_REQUIRE_EQUAL(p2.relative(), p1.relative());
  BOOST_REQUIRE_EQUAL(p3.relative(), p1.relative());

  p3.setRelative(30, 30);
  BOOST_REQUIRE_EQUAL(p1.relative(), Point(30, 30));
  BOOST_REQUIRE_EQUAL(p2.relative(), p1.relative());
  BOOST_REQUIRE_EQUAL(p3.relative(), p1.relative());

  p1.beAlone();
  p2.beAlone();
  p3.beAlone();
  p1.setRelative(0, 0);
  p2.setRelative(1, 1);
  p3.setRelative(2, 2);
  BOOST_REQUIRE_EQUAL(p1.relative(), Point(0, 0));
  BOOST_REQUIRE_EQUAL(p2.relative(), Point(1, 1));
  BOOST_REQUIRE_EQUAL(p3.relative(), Point(2, 2));
}

BOOST_AUTO_TEST_CASE(absolute)
{
  Point p1, p2, p3;

  p2.setOrigin(&p1);
  BOOST_REQUIRE_EQUAL(p1.relative(), Point(0, 0));
  BOOST_REQUIRE_EQUAL(p2.relative(), Point(0, 0));
  BOOST_REQUIRE_EQUAL(p1.origin(), Point(0, 0));
  BOOST_REQUIRE_EQUAL(p2.origin(), p1);
  BOOST_REQUIRE_EQUAL(p1, Point(0, 0));
  BOOST_REQUIRE_EQUAL(p2, Point(0, 0));

  p2.setRelative(10, 10);
  BOOST_REQUIRE_EQUAL(p1.relative(), Point(0, 0));
  BOOST_REQUIRE_EQUAL(p2.relative(), Point(10, 10));
  BOOST_REQUIRE_EQUAL(p1.origin(), Point(0, 0));
  BOOST_REQUIRE_EQUAL(p2.origin(), p1);
  BOOST_REQUIRE_EQUAL(p1, Point(0, 0));
  BOOST_REQUIRE_EQUAL(p2, Point(10, 10));

  p1.setRelative(10, 10);
  BOOST_REQUIRE_EQUAL(p1.relative(), Point(10, 10));
  BOOST_REQUIRE_EQUAL(p2.relative(), Point(10, 10));
  BOOST_REQUIRE_EQUAL(p1.origin(), Point(0, 0));
  BOOST_REQUIRE_EQUAL(p2.origin(), p1);
  BOOST_REQUIRE_EQUAL(p1, Point(10, 10));
  BOOST_REQUIRE_EQUAL(p2, Point(20, 20));

  p3.setRelative(0, 0);
  p3.setOrigin(&p2);
  BOOST_REQUIRE_EQUAL(p1.relative(), Point(10, 10));
  BOOST_REQUIRE_EQUAL(p2.relative(), Point(10, 10));
  BOOST_REQUIRE_EQUAL(p3.relative(), Point(0, 0));
  BOOST_REQUIRE_EQUAL(p1.origin(), Point(0, 0));
  BOOST_REQUIRE_EQUAL(p2.origin(), p1);
  BOOST_REQUIRE_EQUAL(p3.origin(), p2);
  BOOST_REQUIRE_EQUAL(p1, Point(10, 10));
  BOOST_REQUIRE_EQUAL(p2, Point(20, 20));
  BOOST_REQUIRE_EQUAL(p3, Point(20, 20));

  p3.setRelative(10, 10);
  BOOST_REQUIRE_EQUAL(p1.relative(), Point(10, 10));
  BOOST_REQUIRE_EQUAL(p2.relative(), Point(10, 10));
  BOOST_REQUIRE_EQUAL(p3.relative(), Point(10, 10));
  BOOST_REQUIRE_EQUAL(p1.origin(), Point(0, 0));
  BOOST_REQUIRE_EQUAL(p2.origin(), p1);
  BOOST_REQUIRE_EQUAL(p3.origin(), p2);
  BOOST_REQUIRE_EQUAL(p1, Point(10, 10));
  BOOST_REQUIRE_EQUAL(p2, Point(20, 20));
  BOOST_REQUIRE_EQUAL(p3, Point(30, 30));

  p2.setOrigin();
  BOOST_REQUIRE_EQUAL(p1.relative(), Point(10, 10));
  BOOST_REQUIRE_EQUAL(p2.relative(), Point(10, 10));
  BOOST_REQUIRE_EQUAL(p3.relative(), Point(10, 10));
  BOOST_REQUIRE_EQUAL(p1.origin(), Point(0, 0));
  BOOST_REQUIRE_EQUAL(p2.origin(), Point(0, 0));
  BOOST_REQUIRE_EQUAL(p3.origin(), p2);
  BOOST_REQUIRE_EQUAL(p1, Point(10, 10));
  BOOST_REQUIRE_EQUAL(p2, Point(10, 10));
  BOOST_REQUIRE_EQUAL(p3, Point(20, 20));

  p3.setOrigin();
  BOOST_REQUIRE_EQUAL(p1.relative(), Point(10, 10));
  BOOST_REQUIRE_EQUAL(p2.relative(), Point(10, 10));
  BOOST_REQUIRE_EQUAL(p3.relative(), Point(10, 10));
  BOOST_REQUIRE_EQUAL(p1.origin(), Point(0, 0));
  BOOST_REQUIRE_EQUAL(p2.origin(), Point(0, 0));
  BOOST_REQUIRE_EQUAL(p3.origin(), Point(0, 0));
  BOOST_REQUIRE_EQUAL(p1, Point(10, 10));
  BOOST_REQUIRE_EQUAL(p2, Point(10, 10));
  BOOST_REQUIRE_EQUAL(p3, Point(10, 10));

  p2.setOrigin(&p1);
  BOOST_REQUIRE_EQUAL(p1.origin(), Point(0, 0));
  BOOST_REQUIRE_EQUAL(p2.origin(), p1);
  BOOST_REQUIRE_EQUAL(p3.origin(), Point(0, 0));

  p3.setOrigin(&p2);
  BOOST_REQUIRE_EQUAL(p1.origin(), Point(0, 0));
  BOOST_REQUIRE_EQUAL(p2.origin(), p1);
  BOOST_REQUIRE_EQUAL(p3.origin(), p2);

  p1.set(0, 0);
  p2.set(0, 0);
  p3.set(0, 0);
  BOOST_REQUIRE_EQUAL(p1.relative(), Point(0, 0));
  BOOST_REQUIRE_EQUAL(p2.relative(), Point(0, 0));
  BOOST_REQUIRE_EQUAL(p3.relative(), Point(0, 0));
  BOOST_REQUIRE_EQUAL(p1.origin(), Point(0, 0));
  BOOST_REQUIRE_EQUAL(p2.origin(), p1);
  BOOST_REQUIRE_EQUAL(p3.origin(), p2);
  BOOST_REQUIRE_EQUAL(p1, Point(0, 0));
  BOOST_REQUIRE_EQUAL(p2, Point(0, 0));
  BOOST_REQUIRE_EQUAL(p3, Point(0, 0));

  p1.set(10, 10);
  p2.set(20, 20);
  p3.set(30, 30);
  BOOST_REQUIRE_EQUAL(p1.relative(), Point(10, 10));
  BOOST_REQUIRE_EQUAL(p2.relative(), Point(10, 10));
  BOOST_REQUIRE_EQUAL(p3.relative(), Point(10, 10));
  BOOST_REQUIRE_EQUAL(p1.origin(), Point(0, 0));
  BOOST_REQUIRE_EQUAL(p2.origin(), p1);
  BOOST_REQUIRE_EQUAL(p3.origin(), p2);
  BOOST_REQUIRE_EQUAL(p1, Point(10, 10));
  BOOST_REQUIRE_EQUAL(p2, Point(20, 20));
  BOOST_REQUIRE_EQUAL(p3, Point(30, 30));

  p1.set(0, 0);
  BOOST_REQUIRE_EQUAL(p1.relative(), Point(0, 0));
  BOOST_REQUIRE_EQUAL(p2.relative(), Point(10, 10));
  BOOST_REQUIRE_EQUAL(p3.relative(), Point(10, 10));
  BOOST_REQUIRE_EQUAL(p1, Point(0, 0));
  BOOST_REQUIRE_EQUAL(p2, Point(10, 10));
  BOOST_REQUIRE_EQUAL(p3, Point(20, 20));

  p3.set(0, 0);
  BOOST_REQUIRE_EQUAL(p1.relative(), Point(0, 0));
  BOOST_REQUIRE_EQUAL(p2.relative(), Point(10, 10));
  BOOST_REQUIRE_EQUAL(p3.relative(), Point(-10, -10));
  BOOST_REQUIRE_EQUAL(p1, Point(0, 0));
  BOOST_REQUIRE_EQUAL(p2, Point(10, 10));
  BOOST_REQUIRE_EQUAL(p3, Point(0, 0));
}

BOOST_AUTO_TEST_CASE(group_and_absolute)
{
  Point p1, p2, p3;

  p1.setRelative(10, 10);
  p2.setOrigin(&p1);
  p2.setRelative(10, 10);
  p3.join(p2);
  p2.setOrigin(&p1);
  BOOST_REQUIRE_EQUAL(p1.relative(), Point(10, 10));
  BOOST_REQUIRE_EQUAL(p2.relative(), Point(10, 10));
  BOOST_REQUIRE_EQUAL(p3.relative(), Point(10, 10));
  BOOST_REQUIRE_EQUAL(p1.origin(), Point(0, 0));
  BOOST_REQUIRE_EQUAL(p2.origin(), p1);
  BOOST_REQUIRE_EQUAL(p3.origin(), p1);
  BOOST_REQUIRE_EQUAL(p1, Point(10, 10));
  BOOST_REQUIRE_EQUAL(p2, Point(20, 20));
  BOOST_REQUIRE_EQUAL(p3, p2);

  p2.setRelative(20, 20);
  BOOST_REQUIRE_EQUAL(p1.relative(), Point(10, 10));
  BOOST_REQUIRE_EQUAL(p2.relative(), Point(20, 20));
  BOOST_REQUIRE_EQUAL(p3.relative(), Point(20, 20));
  BOOST_REQUIRE_EQUAL(p1.origin(), Point(0, 0));
  BOOST_REQUIRE_EQUAL(p2.origin(), p1);
  BOOST_REQUIRE_EQUAL(p3.origin(), p1);
  BOOST_REQUIRE_EQUAL(p1, Point(10, 10));
  BOOST_REQUIRE_EQUAL(p2, Point(30, 30));
  BOOST_REQUIRE_EQUAL(p3, p2);

  p2.set(0, 0);
  BOOST_REQUIRE_EQUAL(p1.relative(), Point(10, 10));
  BOOST_REQUIRE_EQUAL(p2.relative(), Point(-10, -10));
  BOOST_REQUIRE_EQUAL(p3.relative(), Point(-10, -10));
  BOOST_REQUIRE_EQUAL(p1.origin(), Point(0, 0));
  BOOST_REQUIRE_EQUAL(p2.origin(), p1);
  BOOST_REQUIRE_EQUAL(p3.origin(), p1);
  BOOST_REQUIRE_EQUAL(p1, Point(10, 10));
  BOOST_REQUIRE_EQUAL(p2, Point(0, 0));
  BOOST_REQUIRE_EQUAL(p3, p2);

  p3.setRelative(10, 10);
  BOOST_REQUIRE_EQUAL(p1.relative(), Point(10, 10));
  BOOST_REQUIRE_EQUAL(p2.relative(), Point(10, 10));
  BOOST_REQUIRE_EQUAL(p3.relative(), Point(10, 10));
  BOOST_REQUIRE_EQUAL(p1.origin(), Point(0, 0));
  BOOST_REQUIRE_EQUAL(p2.origin(), p1);
  BOOST_REQUIRE_EQUAL(p3.origin(), p1);
  BOOST_REQUIRE_EQUAL(p1, Point(10, 10));
  BOOST_REQUIRE_EQUAL(p2, Point(20, 20));
  BOOST_REQUIRE_EQUAL(p3, p2);

  p3.set(-10, -10);
  BOOST_REQUIRE_EQUAL(p1.relative(), Point(10, 10));
  BOOST_REQUIRE_EQUAL(p2.relative(), Point(-20, -20));
  BOOST_REQUIRE_EQUAL(p3.relative(), Point(-20, -20));
  BOOST_REQUIRE_EQUAL(p1.origin(), Point(0, 0));
  BOOST_REQUIRE_EQUAL(p2.origin(), p1);
  BOOST_REQUIRE_EQUAL(p3.origin(), p1);
  BOOST_REQUIRE_EQUAL(p1, Point(10, 10));
  BOOST_REQUIRE_EQUAL(p2, Point(-10, -10));
  BOOST_REQUIRE_EQUAL(p3, p2);

  Point p4(20, 0);
  p3.setOrigin(&p4);
  BOOST_REQUIRE_EQUAL(p1.relative(), Point(10, 10));
  BOOST_REQUIRE_EQUAL(p2.relative(), Point(-20, -20));
  BOOST_REQUIRE_EQUAL(p3.relative(), Point(-20, -20));
  BOOST_REQUIRE_EQUAL(p4.relative(), Point(20, 0));
  BOOST_REQUIRE_EQUAL(p1.origin(), Point(0, 0));
  BOOST_REQUIRE_EQUAL(p2.origin(), p4);
  BOOST_REQUIRE_EQUAL(p3.origin(), p4);
  BOOST_REQUIRE_EQUAL(p1, Point(10, 10));
  BOOST_REQUIRE_EQUAL(p2, Point(0, -20));
  BOOST_REQUIRE_EQUAL(p3, p2);
  BOOST_REQUIRE_EQUAL(p4, Point(20, 0));
}
