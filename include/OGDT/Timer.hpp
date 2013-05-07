#pragma once

namespace C
{
#include <OGDT/Timer.h>
}

namespace OGDT
{

/*
Class: Timer
A high resolution timer.
*/
class Timer
{
    C::Timer timer;

public:

    /*
    Constructor: Timer
    Construct a new timer.

    The timer is initialised by making a call to reset(). Since time
    calculations are measured from the instant the timer is reset (base time),
    you probably want to make a manual call to reset() at the start of
    your application, otherwise the application will be measuring times
    from the instant the timer's constructor is called, which can be error prone.

    A call to start() must be made prior to any time calculations, as the
    timer is initialised as stopped.
    */
    Timer () {
        C::timer_init (&timer);
    }

    /*
    Function: tick
    Update the timer's values.

    This function updates the timer's running time and caches the time
    elapsed since the last tick or since the start if this is the first
    tick after the last call to start().

    This function has no effect on a stopped ticker.
    */
    void tick () {
        C::timer_tick (&timer);
    }

    /*
    Function: start
    Start the timer.

    This function starts the timer for the first time or resumes it
    after a call to stop().

    Note that this function does not reset the timer's base time;
    it's only a mechanism to resume a stopped timer.
    */
    void start () {
        C::timer_start (&timer);
    }

    /*
    Function: stop
    Stop the timer.

    This function essentially freezes time; any values dependent on
    the timer will behave as if time had not passed since the moment
    the timer was stopped.

    To resume the timer call start().
    */
    void stop () {
        C::timer_stop (&timer);
    }

    /*
    Function: reset
    Reset the timer.

    This function resets all of the timer's values such as running and
    stop times and sets the timer to stopped. The total running time is
    then measured from the instant the timer is reset, making the timer
    behave as a newly constructed one.

    A call to start() must be made prior to any further time calculations.
    */
    void reset () {
        C::timer_reset (&timer);
    }

    /*
    Function: getTime
    Get the total running time.

    The amount of time the timer has been stopped for is not taken
    into account.
    */
    double getTime () const {
        return C::timer_get_time (&timer);
    }

    /*
    Function: getDelta
    Get the time elapsed since the last tick, or since the start if
    this is the first tick.
    */
    float getDelta () const {
        return C::timer_get_delta (&timer);
    }

    /*
    Function: isRunning
    Return true if the timer is running (not stopped), false otherwise.
    */
    bool isRunning() const {
        return C::timer_is_running (&timer);
    }
};

/*
Function: timer_sleep
Put the caller thread to sleep for the given number of seconds.
*/
inline void timer_sleep (float seconds)
{
    C::timer_sleep (seconds);
}

} // namespace OGDT
