#pragma once

#include <OGDT/OGDT.h>

#ifdef WIN32
    #ifdef _MSC_VER
        typedef __int64 timeReading;
    #else
        typedef __UINT64_TYPE__ timeReading;
    #endif
#else
    typedef double timeReading;
#endif

/*
Class: Timer
A high resolution timer.
*/
class DECLDIR Timer
{    
    timeReading baseTime;
    timeReading pausedTime;
    timeReading stopTime;
    timeReading prevTime;
    timeReading curTime;
    float deltaTime;
    char stopped;
    
public:
    
    Timer ();
    
    /*
    Function: tick
    Update the timer's values.
    */
    void tick ();

    /*
    Function: start
    Start the timer.
    */
    void start ();

    /*
    Function: stop
    Stop the timer.
    */
    void stop ();
    
    /*
    Function: reset
    Reset the timer.
    */
    void reset ();
    
    /*
    Function: getTime
    Get the running time.
    */
    float getTime () const;
    
    /*
    Function: getDelta
    Get the time elapsed since the last tick.
    */
    float getDelta () const { return deltaTime; }
    
    /*
    Function: isRunning
    Return true if the timer is running (not stopped), false otherwise.
    */
    bool isRunning() const { return !stopped; }
};

/*
Function: timer_sleep
Put the caller thread to sleep for the given number of seconds.
*/
void timer_sleep (float seconds);
