#define BOOST_TEST_MODULE Timer
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <OGDT/math.h>
#include <OGDT/Timer.h>
#include <cstdio>

using namespace OGDT;

bool in_range (float lower, float x, float upper)
{
    return x >= lower && x <= upper;
}

BOOST_AUTO_TEST_CASE (timer_unstarted_times)
{
    // Unstarted timer must report 0 times.
    Timer t;
    double elapsed = t.getTime ();
    float dt = t.getDelta ();
    BOOST_REQUIRE (elapsed == 0.0);
    BOOST_REQUIRE (dt == 0.0f);
}

BOOST_AUTO_TEST_CASE (timer_reset_times)
{
    // Reset timer must report 0 times.
    Timer t;
    t.reset ();
    double elapsed = t.getTime ();
    float dt = t.getDelta ();
    BOOST_REQUIRE (elapsed == 0.0);
    BOOST_REQUIRE (dt == 0.0f);
}

BOOST_AUTO_TEST_CASE (timer_start_resume)
{

    // Stop/resume test.
    Timer t;
    t.start();
    timer_sleep (0.150f);
    t.stop();
    double e1 = t.getTime ();
    timer_sleep (0.150f);
    double e2 = t.getTime ();
    BOOST_REQUIRE (e1 == e2);
}

BOOST_AUTO_TEST_CASE (timer_tick)
{
    // The following test is inherently system dependent.
    // It just checks that the timer is not plain wrong,
    // and shouldn't be taken as the ultimate precision test.
    Timer t;
    t.start ();
    t.tick ();
    timer_sleep (1.0f);
    t.tick ();
    float dt = t.getDelta ();
    printf ("dt = %f\n", dt);
    BOOST_REQUIRE (in_range (1.0f, dt, 1.1f));
}
