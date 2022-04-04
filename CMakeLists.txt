cmake_minimum_required(VERSION 3.10)
project(Deadline VERSION 1.0)

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
    source/game/game.cc
    source/ui/ui.cc
    source/ecs/component.cc
    source/ecs/components/camera/camera.cc
    source/ecs/components/transform/transform.cc
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

set(APP_ICON_RESOURCE_WINDOWS "assets/appicon.rc")

add_executable(Deadline WIN32 source/entry-point.cc ${SourceCode} ${VendorCode} ${APP_ICON_RESOURCE_WINDOWS})

target_include_directories(Deadline PUBLIC
    source/application
    source/game
    source/ui
    source/ecs
   )

target_include_directories(Deadline
    PUBLIC vendor/glad/include
    PUBLIC vendor/imgui
    PUBLIC vendor/json
    PUBLIC vendor/glm
    PUBLIC vendor/stb
    )

target_link_libraries(Deadline
    PUBLIC glfw
    PUBLIC glad)