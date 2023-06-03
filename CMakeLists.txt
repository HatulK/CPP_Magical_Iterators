cmake_minimum_required(VERSION 3.25)
project(CPP_Magical_Iterators)

set(CMAKE_CXX_STANDARD 17)

add_executable(CPP_Magical_Iterators Demo.cpp doctest.h TestCounter.cpp sources/MagicalContainer.cpp sources/MagicalContainer.hpp Test.cpp)
