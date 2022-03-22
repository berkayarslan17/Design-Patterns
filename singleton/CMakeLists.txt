cmake_minimum_required(VERSION 3.13.4)

project(singleton CXX)

add_executable(${PROJECT_NAME} src/singleton.cpp)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)