#
# App
# 

set(SOURCES
    Source/Main.cpp
    Source/AppLayer.h
    Source/AppLayer.cpp
)

add_executable(App)

target_sources(App PRIVATE ${SOURCES})

add_compile_definitions(
    GLFW_INCLUDE_NONE
)

target_link_libraries(App Core)

target_include_directories(App PRIVATE Source)
