cmake_minimum_required(VERSION 3.0.0)
project(List VERSION 0.1.0)
add_executable(List List.h example.cpp)

set_target_properties(List PROPERTIES LINKER_LANGUAGE CXX)