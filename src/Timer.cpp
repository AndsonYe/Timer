#include <assert.h>
#include "Timer.h"

Timer::Timer(string name):
    running_(false)
{
    name_ = name;
    get_frequency(&frequency_);
}

void Timer::start()
{
    running_ = true;
    clock_now(&start_time_);
    last_lap_time_ = start_time_;
}

void Timer::stop()
{
    assert(running_ == true);
    clock_now(&end_time_);
    running_ = false;
}

void Timer::lap(string name)
{
    assert(running_ == true);
    TIME_UNIT lap_time;
    clock_now(&lap_time);
    printf("%s timer %s lap takes time: %.4fms\n", name_.c_str(), name.c_str(),
        millisec_gap(last_lap_time_, lap_time, frequency_));
    last_lap_time_ = lap_time;
}

void Timer::reset()
{
    assert(running_ == true);
    clock_now(&start_time_);
    last_lap_time_ = start_time_;
}

void Timer::print()
{
    if (running_)
        stop();
    printf("%s timer totally elpased time: %.4fms\n", name_.c_str(),
            millisec_gap(start_time_, end_time_, frequency_));
}

