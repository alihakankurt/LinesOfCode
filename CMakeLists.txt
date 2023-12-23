cmake_minimum_required(VERSION 3.20)

project(loc VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(loc src/main.cc src/counter.cc)

target_include_directories(loc PRIVATE include)
