cmake_minimum_required(VERSION 3.21)
project(HW1)

set(CMAKE_CXX_STANDARD 98)

add_executable(HW1 ParkingSystem.cpp ParkingSystem.h main.cpp Lot.cpp Lot.h Car.cpp Car.h)
