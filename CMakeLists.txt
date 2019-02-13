cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 11)
project(timer_example)

include_directories(./include)
file(GLOB SOURCES ./src/*.cpp)

add_executable(example ${SOURCES})
