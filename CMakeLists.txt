cmake_minimum_required(VERSION 3.16..3.24)
project(googletest_lessons
        LANGUAGES CXX)

        set(CMAKE_CXX_STANDARD 17)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")


include(cmake/UpdateSubmodules.cmake)
include(CTest)

add_subdirectory(src)
include_directories(include)


if(BUILD_TESTING)
        add_subdirectory(external)
        add_subdirectory(tests)
endif()

