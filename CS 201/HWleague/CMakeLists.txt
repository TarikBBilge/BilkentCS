cmake_minimum_required(VERSION 3.21)
project(HWleague)

set(CMAKE_CXX_STANDARD 98)

add_executable(HWleague main.cpp LeagueManagementSystem.h LeagueManagementSystem.cpp Team.h Team.cpp Player.h Player.cpp)
