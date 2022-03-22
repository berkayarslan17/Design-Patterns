cmake_minimum_required(VERSION 3.13.4)

project(factory CXX)

add_executable(${PROJECT_NAME} src/factory.cpp)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)