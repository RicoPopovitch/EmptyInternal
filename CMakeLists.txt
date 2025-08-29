cmake_minimum_required(VERSION 3.10)
project(template LANGUAGES CXX)

add_library(template SHARED
    source/main.cpp
    source/overlay/src/overlay.cpp
    source/backend/src/engine.cpp
    source/vendor/imgui/imgui.cpp
    source/vendor/imgui/imgui_draw.cpp
    source/vendor/imgui/imgui_tables.cpp
    source/vendor/imgui/imgui_widgets.cpp
    source/vendor/imgui/backends/imgui_impl_win32.cpp
    source/vendor/imgui/backends/imgui_impl_dx11.cpp
)

target_include_directories(template PRIVATE
    source/overlay/includes
	source/backend/includes
    source/vendor/imgui
    source/vendor/imgui/backends
)

target_compile_features(template PRIVATE cxx_std_17)

if (WIN32)
    target_compile_definitions(template PRIVATE WIN32_LEAN_AND_MEAN)
endif()

