cmake_minimum_required(VERSION 3.16)

project(eq)

set(CMAKE_CXX_STANDARD 20)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

find_package(LIBAV REQUIRED)
#include_directories(${LIBAV_INCLUDE_DIR})
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBAV REQUIRED IMPORTED_TARGET
        libavdevice
        libavfilter
        libavformat
        libavcodec
        libswresample
        libswscale
       libavutil)

add_executable(eq main.cpp)
target_link_libraries(eq ${LIBAV_LIBRARIES})
target_link_libraries(eq ${CURSES_LIBRARIES})
#install()
