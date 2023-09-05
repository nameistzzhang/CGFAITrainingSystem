cmake_minimum_required(VERSION 3.15)

project(TestMain)

add_executable(TestMain main.cpp
Lib/add.h
Lib/minus.h)

target_link_libraries(TestMain ${CMAKE_SOURCE_DIR}/Lib/TestLib.lib)