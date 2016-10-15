#pragma once
#ifndef _TIMER_H_
#define _TIMER_H_

#include <string>
#include <stdio.h>

#if defined (_WIN32)
#include <Windows.h>
typedef LARGE_INTEGER TIME_UNIT;
#define get_frequency(frequency) QueryPerformanceFrequency(frequency)
#define clock_now(time_stamp) QueryPerformanceCounter(time_stamp)
#define millisec_gap(begin, end, frequency) ((end.QuadPart - begin.QuadPart) * 1000.0 / frequency.QuadPart)
#elif defined (linux)
#include <time.h>
typedef timespec TIME_UNIT;
#define get_frequency(frequency)
#define clock_now(time_stamp) clock_gettime(CLOCK_MONOTONIC, time_stamp)
#define millisec_gap(begin, end, frequency) ((end.tv_sec - begin.tv_sec) * 1000 + (end.tv_nsec - begin.tv_nsec) / 1000000.0 )
#endif

using std::string;

class Timer
{
public:
    //Timer();
    Timer(string name="default");
    void start();
    void stop();
    void lap(string name);
    void reset();
    //void resume();
    void print();
private:
    TIME_UNIT           start_time_;
    TIME_UNIT           end_time_;
    TIME_UNIT           last_lap_time_;
    TIME_UNIT           frequency_;
    string              name_;
    bool                running_;
};

#endif
