cmake_minimum_required(VERSION 2.6)
project(timer_example)

include_directories(./include)
file(GLOB SOURCES ./src/*.cpp)

add_executable(example ${SOURCES})
