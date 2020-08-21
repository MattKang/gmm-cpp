cmake_minimum_required(VERSION 3.16)
project(gmm)

set(CMAKE_CXX_STANDARD 14)

add_executable(gmm main.cpp gmm.hpp gmm.cpp)