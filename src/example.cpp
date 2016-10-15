#include <stdio.h>
#if defined (linux) || defined(__unix__) || defined(__linux__)
#include <unistd.h>
#define SLEEP(x) sleep(x)
#elif defined (_WIN32)
#include <Windows.h>
#define SLEEP(x) Sleep(x * 1000)
#endif
#include "Timer.h"

//function of which time span is going to be measured
void foo()
{
    int i = 0;
    while(i < 999999)
    {
        ++i;
    }
}

int main()
{
    Timer my_timer("main");
    //need to start the timer before measuring the function
    my_timer.start();
    foo();
    float foo_elapse = my_timer.get_lap();
    printf("the time takes for running foo is %.4f milliseconds\n", foo_elapse);
    //sleep for one second
    SLEEP(1);
    //if you only need to print the duration, use lap() and print() instead of get_lap() and get_total()
    my_timer.lap("sleep");
    my_timer.print();
    return 0;
}
