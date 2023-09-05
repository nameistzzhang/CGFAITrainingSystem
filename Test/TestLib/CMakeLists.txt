cmake_minimum_required(VERSION 3.15)

project(TestLib)

add_library(TestLib STATIC
    Src/add.cpp
    Src/minus.cpp
)