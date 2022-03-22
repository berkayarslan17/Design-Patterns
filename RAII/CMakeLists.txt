cmake_minimum_required(VERSION 3.13.4)

project(RAII CXX)

add_executable(${PROJECT_NAME} src/memory_allocation.cpp)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)