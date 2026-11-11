cmake_minimum_required(VERSION 3.10)

project(cpp-app-template)

if(NOT CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_VERSION VERSION_LESS 14)
    message(FATAL_ERROR "GCC 14+ required, found ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}. "
                        "Configure with -DCMAKE_CXX_COMPILER=g++-14 (or use ./build.sh).")
endif()

set(CMAKE_CXX_STANDARD 23)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Dependencies
include(Depencencies.cmake)

# Projects
add_subdirectory(Core)
add_subdirectory(App)