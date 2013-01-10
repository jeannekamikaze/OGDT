#include <OGDT/Timer.h>
#include <stdlib.h>

#ifdef __APPLE__
    #include <mach/mach_time.h>
#elif WIN32
    #define WIN32_LEAN_AND_MEAN
    #include <Windows.h>
#else // Linux
    #include <time.h>
    const double NSEC_TO_SEC = 1.0f/1000000000.0f;
    const double SEC_TO_NSEC = 1000000000.0f;
#endif


static double secondsPerCount;


static void timer_initialise_subsystem ()
{
#ifdef WIN32
    __int64 countsPerSec;
    QueryPerformanceFrequency((LARGE_INTEGER*)&countsPerSec);
    secondsPerCount = 1.0 / (double)countsPerSec;
#else
    /*struct timespec ts;
    clock_getres(CLOCK_REALTIME, &ts);
    secondsPerCount = (double)ts.tv_sec + ((double)ts.tv_nsec * NSEC_TO_SEC);*/
    secondsPerCount = 1.0f;
#endif
}


void timer_sleep (float seconds)
{
#ifdef WIN32
    Sleep((DWORD)(seconds * 1000));
#else
    struct timespec ts;
    ts.tv_sec  = 0;
    ts.tv_nsec = seconds * SEC_TO_NSEC;
    nanosleep(&ts, NULL);
#endif
}


static timeReading now ()
{
    timeReading t;
    
#ifdef __APPLE__
    t = mach_absolute_time();
#elif WIN32
    QueryPerformanceCounter((LARGE_INTEGER*)&t);
#else
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    t = ts.tv_sec + ((double)ts.tv_nsec * NSEC_TO_SEC);
#endif
    
    return t;
}


Timer::Timer ()
    : baseTime (0), pausedTime (0), stopTime (0), prevTime (0)
    , curTime (0), deltaTime (0), stopped (1)
{
    timer_initialise_subsystem();
}


void Timer::tick ()
{
    if (stopped)
    {
        deltaTime = 0.0;
        return;
    }

    //Get the time on this frame.
    curTime = now();

    //Time delta between the current frame and the previous.
    deltaTime = (float) ((curTime - prevTime) * secondsPerCount);

    //Update for next frame.
    prevTime = curTime;

    // Force nonnegative. The DXSDK's CDXUTTimer mentions that if the
    // processor goes into a power save mode or we get shuffled to
    // another processor, then mDeltaTime can be negative.
    if(deltaTime < 0.0)
    {
        deltaTime = 0.0;
    }
}


void Timer::reset ()
{
    curTime = now();
    baseTime = curTime;
    prevTime = curTime;
    stopTime = 0;
    stopped = 0;
}


void Timer::stop ()
{
    // Don't do anything if we are already stopped.
    if (!stopped)
    {
        // Grab the stop time.
        stopTime = now();

        // Now we are stopped.
        stopped = 1;
    }
}


void Timer::start ()
{
    // Only start if we are stopped.
    if (stopped)
    {
        timeReading startTime = now();

        // Accumulate the paused time.
        pausedTime = pausedTime + startTime - stopTime;

        // Make the previous time valid.
        prevTime = startTime;

        //Now we are running.
        stopTime = 0;
        stopped = 0;
    }
}


float Timer::getTime () const
{
    // If we are stopped, we do not count the time we have been stopped for.
    if (stopped)
    {
        return (float)((stopTime - baseTime) * secondsPerCount);
    }
    // Otherwise return the time elapsed since the start of the game without counting the time we have been paused for.
    else
    {
        return (float)((curTime - baseTime - pausedTime) * secondsPerCount);
    }
}
