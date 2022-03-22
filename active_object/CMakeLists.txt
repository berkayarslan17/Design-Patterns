cmake_minimum_required(VERSION 3.13.4)

project(active_object CXX)

add_executable(${PROJECT_NAME} src/main.cpp)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)