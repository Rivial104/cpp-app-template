cmake_minimum_required(VERSION 3.28)
project(cpp-app-template VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# Static core library
add_subdirectory(core)

# Application
add_executable(app src/main.cpp)
target_link_libraries(app PRIVATE core::core)

# Tests
option(BUILD_TESTS "Buduj testy" ON)
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
