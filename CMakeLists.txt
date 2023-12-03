cmake_minimum_required(VERSION 3.27)
project(aoc2023)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g3")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -O2")

add_executable(aoc2023 src/main.cpp src/file.cpp src/bench.cpp src/day1.cpp)
target_include_directories(aoc2023 PRIVATE include)