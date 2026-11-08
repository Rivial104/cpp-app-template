add_library(core STATIC
    src/core.cpp
)
add_library(core::core ALIAS core)

target_include_directories(core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_compile_features(core PUBLIC cxx_std_20)
