cmake_minimum_required(VERSION 3.13.4)

project(RAII CXX)

add_executable(${PROJECT_NAME} src/locks.cpp)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(RAII PRIVATE Threads::Threads)