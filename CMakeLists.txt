cmake_minimum_required(VERSION 3.10)
project(template LANGUAGES CXX)

add_library(template SHARED
    source/main.cpp
    source/overlay/src/overlay.cpp
    source/backend/src/engine.cpp
)

target_include_directories(template PRIVATE
    source/overlay/includes
	source/backend/includes
)

target_compile_features(template PRIVATE cxx_std_17)

if (WIN32)
    target_compile_definitions(template PRIVATE WIN32_LEAN_AND_MEAN)
endif()
