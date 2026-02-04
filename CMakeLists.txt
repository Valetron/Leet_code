cmake_minimum_required(VERSION 3.10)
project(Leet_code LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
find_package(GTest REQUIRED)

file(GLOB SOURCES "*.cpp")
file(GLOB_RECURSE UTILS_HEADERS "utils/*.hpp")
file(GLOB_RECURSE UTILS_SOURCES "utils/*.cpp")

foreach(test_file ${SOURCES})
    get_filename_component(test_target_name ${test_file} NAME_WE)
    message(STATUS "Res - ${test_target_name}")

    add_executable(${test_target_name} ${test_file} ${UTILS_HEADERS} ${UTILS_SOURCES})
    target_link_libraries(${test_target_name} GTest::gtest_main)
    target_include_directories(${test_target_name} PUBLIC "utils/")

    add_test(NAME ${test_target_name} COMMAND ${test_target_name})

        # add_custom_command(
        #      TARGET ${test_target_name}
        #      COMMENT "Run \"${test_target_name}\""
        #      POST_BUILD
        #      COMMAND ${test_target_name})

endforeach()
