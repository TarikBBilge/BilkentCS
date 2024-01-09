cmake_minimum_required(VERSION 3.21)
project(hw3Movie)

set(CMAKE_CXX_STANDARD 98)

add_executable(hw3Movie main.cpp MovieRentalSystem.h MovieRentalSystem.cpp Movie.cpp Movie.h Subscriber.cpp Subscriber.h)
