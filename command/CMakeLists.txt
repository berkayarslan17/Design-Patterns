cmake_minimum_required(VERSION 3.13.4)

project(command_pattern CXX)

INCLUDE_DIRECTORIES(src)
add_executable(${PROJECT_NAME} 
                src/main.cpp
                src/cmd.cpp)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)