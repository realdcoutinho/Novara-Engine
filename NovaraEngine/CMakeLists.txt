cmake_minimum_required(VERSION 3.20)


if(TARGET NovaraEngine)
    return()
endif()

project(NovaraEngine LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
file(GLOB_RECURSE ENGINE_SOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/Base/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Components/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Content/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Graphics/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Managers/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Misc/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/PhysX/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Prefabs/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Scenegraph/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Utils/*.cpp"
)

# Add header files
file(GLOB_RECURSE ENGINE_HEADERS 
    "${CMAKE_CURRENT_SOURCE_DIR}/Base/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/Components/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/Content/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/Graphics/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/Managers/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/Misc/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/PhysX/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/Prefabs/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/Scenegraph/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/Utils/*.h"
)


# Create library
add_library(NovaraEngine STATIC ${ENGINE_SOURCES} ${ENGINE_HEADERS})

target_precompile_headers(NovaraEngine PRIVATE stdafx.h)


# Set include directories
target_include_directories(NovaraEngine PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/Base"
    "${CMAKE_CURRENT_SOURCE_DIR}/Components"
    "${CMAKE_CURRENT_SOURCE_DIR}/Content"
    "${CMAKE_CURRENT_SOURCE_DIR}/Graphics"
    "${CMAKE_CURRENT_SOURCE_DIR}/Managers"
    "${CMAKE_CURRENT_SOURCE_DIR}/Misc"
    "${CMAKE_CURRENT_SOURCE_DIR}/PhysX"
    "${CMAKE_CURRENT_SOURCE_DIR}/Prefabs"
    "${CMAKE_CURRENT_SOURCE_DIR}/Scenegraph"
    "${CMAKE_CURRENT_SOURCE_DIR}/Utils"
)

# External dependencies
set(EXTERNAL_DIR "${CMAKE_SOURCE_DIR}/GP2_Libraries")

message(STATUS "External Libraries Directory: ${EXTERNAL_DIR}")


# Include paths
include_directories(
    "${EXTERNAL_DIR}/DirectXTex/include"
    "${EXTERNAL_DIR}/FMOD/include"
    "${EXTERNAL_DIR}/FX11/include"
    "${EXTERNAL_DIR}/PhysX/include"
    "${EXTERNAL_DIR}/imgui/include"
    "${EXTERNAL_DIR}/vld/include"
)


set(vld_include "${CMAKE_SOURCE_DIR}/GP2_Libraries/vld/include")


message(STATUS "External Libraries Directory: ${vld_include}")


# Link libraries based on build type
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(LIB_SUFFIX "debug")
else()
    set(LIB_SUFFIX "release")
endif()

# Link library directories
link_directories(
    "${EXTERNAL_DIR}/DirectXTex/lib/${LIB_SUFFIX}"
    "${EXTERNAL_DIR}/FMOD/lib/${LIB_SUFFIX}"
    "${EXTERNAL_DIR}/FX11/lib/${LIB_SUFFIX}"
    "${EXTERNAL_DIR}/PhysX/lib/${LIB_SUFFIX}"
    "${EXTERNAL_DIR}/imgui/lib/${LIB_SUFFIX}"
    "${EXTERNAL_DIR}/vld/lib/${LIB_SUFFIX}"
)


# Link external libraries
target_link_libraries(NovaraEngine
    DirectXTex
    fmod
    FX11
    PhysX
    imgui
    vld
)