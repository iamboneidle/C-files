cmake_minimum_required(VERSION 3.24)
project(NikitasHW2)

set(CMAKE_CXX_STANDARD 20)

add_executable(NikitasHW2 QuadTree.h Plane.h Node.h Box.h Circle.h main.cpp Circle.cpp Plane.cpp Box.cpp Node.cpp QuadTree.cpp)
