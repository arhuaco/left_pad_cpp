project(not_kik_left_pad C CXX)
cmake_minimum_required(VERSION 2.8)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(warnings "-Wall -Wextra -Werror")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(warnings "/W4 /WX /EHsc")
endif()
set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} ${warnings}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${warnings}")

project(not_kik_left_pad C CXX)

set(not_kik_left_pad_sources left_pad.cpp)
set(not_kik_left_pad_headers left_pad.h)

add_library(not_kik_left_pad ${not_kik_left_pad_sources} ${not_kik_left_pad_headers})
set_property(TARGET not_kik_left_pad PROPERTY CXX_STANDARD 11)

add_executable(left_pad_example left_pad_example.cpp)
set_property(TARGET left_pad_example PROPERTY CXX_STANDARD 11)
target_link_libraries(left_pad_example not_kik_left_pad)
