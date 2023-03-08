cmake_minimum_required(VERSION 3.8)

project(canproto)
add_library(${PROJECT_NAME} STATIC can_proto.c)
add_library(sample STATIC sample.c)
target_link_libraries(sample PUBLIC canproto)
add_executable(test test_main.cpp)
target_link_libraries(test PUBLIC sample gtest)
