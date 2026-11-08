add_executable(core_tests test_core.cpp)
target_link_libraries(core_tests PRIVATE core::core)

set_target_properties(core_tests PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

add_test(NAME core_tests COMMAND core_tests)
