cmake_minimum_required(VERSION 3.8)
project(Mastermind)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Mastermind.cpp Mastermind.h)
add_executable(Mastermind ${SOURCE_FILES})