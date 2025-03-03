cmake_minimum_required(VERSION 3.10)
project(Leet_code LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
find_package(GTest REQUIRED)

file(GLOB SOURCES "template.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} GTest::gtest_main)

enable_testing()

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

add_custom_command(
     TARGET ${PROJECT_NAME}
     COMMENT "Run tests"
     POST_BUILD
     COMMAND ${PROJECT_NAME}
)
