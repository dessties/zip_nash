﻿# CMakeList.txt : CMake project for ZipNash, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (ZipNash "main.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ZipNash PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
