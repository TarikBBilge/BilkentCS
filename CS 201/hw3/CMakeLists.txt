cmake_minimum_required(VERSION 3.21)
project(hw3)

set(CMAKE_CXX_STANDARD 98)

add_executable(hw3 main.cpp RegistrationSystem.cpp RegistrationSystem.h StudentNode.cpp StudentNode.h CourseNode.cpp CourseNode.h)
