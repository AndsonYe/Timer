#include <stdio.h>
#include <unistd.h>
#include "Timer.h"

//function time span to be measured
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
    my_timer.lap("foo");
    sleep(1);
    my_timer.lap("sleep");
    return 0;
}
