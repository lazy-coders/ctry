cmake_minimum_required(VERSION 2.8)
project(ctry_tests)
include_directories(../include/)

add_executable(test01 test01.c)
target_link_libraries(test01 ctry)
