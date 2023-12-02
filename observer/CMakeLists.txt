cmake_minimum_required(VERSION 3.13.4)
project("Gtest")

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp
)

target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})

enable_testing()
add_test(add ${PROJECT_NAME})