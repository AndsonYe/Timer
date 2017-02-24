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

#elif defined (linux) || defined(__unix__) || defined(__linux__)
#include <time.h>
typedef timespec TIME_UNIT;
#define get_frequency(frequency)
#define clock_now(time_stamp) clock_gettime(CLOCK_MONOTONIC, time_stamp)
#define millisec_gap(begin, end, frequency) ((end.tv_sec - begin.tv_sec) * 1000 + (end.tv_nsec - begin.tv_nsec) / 1000000.0 )
#endif

using std::string;

enum time_unit_type
{
    millisecond = 1,
    second = 1000,
    minute = 60000,
    hour = 3600000,
    day = 86400000
};

class Timer
{
public:
    Timer(string name="default");

    void start();

    void stop();

    void reset();

    /**
    * @brief Computes milliseconds elapsed since start or last lap
    */
    double get_lap(time_unit_type unit_type = millisecond);

    /**
    * @brief Computes milliseconds elapsed since start
    */

    double get_total(time_unit_type unit_type = millisecond);

    void lap(string name);

    void print();

    TIME_UNIT get_current_timestamp();

    double get_time_gap(const TIME_UNIT &begin, const TIME_UNIT &end, time_unit_type unit_type = millisecond);
private:
    TIME_UNIT           start_time_;
    TIME_UNIT           end_time_;
    TIME_UNIT           last_lap_time_;
    TIME_UNIT           frequency_;
    string              name_;
    bool                running_;
};

#endif
