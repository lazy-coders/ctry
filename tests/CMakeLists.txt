cmake_minimum_required(VERSION 2.8)
project(ctry_tests)
include_directories(../include/)

add_executable(test01 test01.c)
target_link_libraries(test01 ctry)

add_executable(test02 test02.c)
target_link_libraries(test02 ctry)

add_executable(test03 test03.c)
target_link_libraries(test03 ctry)

add_executable(test04 test04.c)
target_link_libraries(test04 ctry)
