cmake_minimum_required(VERSION 3.10)
project(LDGame VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

######### GLFW Modules #########
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glad)
######### GLFW Modules #########

set(SourceCode
    source/application/application.cc
    source/window/window.cc
    source/ui/ui.cc
    )

set(VendorCode
    vendor/glad/src
    vendor/imgui/imgui_demo.cpp
    vendor/imgui/imgui_draw.cpp
    vendor/imgui/imgui_tables.cpp
    vendor/imgui/imgui_widgets.cpp
    vendor/imgui/imgui.cpp
    vendor/imgui/backends/imgui_impl_glfw.cpp
    vendor/imgui/backends/imgui_impl_opengl3.cpp
    )

add_executable(LDGame source/entry-point.cc ${SourceCode} ${VendorCode})

target_include_directories(LDGame PUBLIC
    source/application
    source/window
    source/ui
   )

target_include_directories(LDGame
    PUBLIC vendor/glad/include
    PUBLIC vendor/imgui
    )

target_link_libraries(LDGame
    PUBLIC glfw
    PUBLIC glad)