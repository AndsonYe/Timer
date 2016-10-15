# Timer
A simple cross-platform tool for calculating elapsed time in C++ program.

## Why this?
You may also find that using `clock()` to calculate the time elapsed is not accurate, like the code bellow

```cpp
time_t start = clock();
//do something here
time_t end = clock();
float millisecs_elapsed = (end - start) / (float) CLOCKS_PER_SEC;
```
That's because `clock()` only return the approximate processor time used by the process and the `millisecs_elapsed` may not be equal to the amount of wall-clock time between `end` and `start`

To get the accurate time duration, we need to access the system API. So here comes a Timer for both Linux and Windows.

#### Timer is tested on
* Windows 7
* Windows 10
* Ubuntu 14.04 LTS / Trusty


## Use Timer

Just add the TImer.h and Timer.cpp into your project. For how to use, check the [example.cpp](https://github.com/AndsonYe/Timer/blob/master/src/example.cpp).

### Build Example

Make sure `cmake` is installed.

For Linux:

    mkdir build
    cd build
    cmake ..
    make

For Windows, you can also use `cmake` to generate a Visual Studio project or just create a VS project and add every file then run build.
