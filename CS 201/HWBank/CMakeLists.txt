cmake_minimum_required(VERSION 3.21)
project(HWBank)

set(CMAKE_CXX_STANDARD 98)

add_executable(HWBank main.cpp BankingSystem.h BankingSystem.cpp Branch.cpp Branch.h Account.cpp Account.h Customer.cpp Customer.h)
