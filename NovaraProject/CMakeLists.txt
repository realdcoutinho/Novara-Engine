cmake_minimum_required(VERSION 3.20)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DUNICODE -D_UNICODE)


# Find NovaraEngine
add_subdirectory(../NovaraEngine NovaraEngine)

# Add source files for NovaraProject
file(GLOB_RECURSE PROJECT_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB_RECURSE PROJECT_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

# Create executable
add_executable(NovaraProject ${PROJECT_SOURCES} ${PROJECT_HEADERS})

# Link with NovaraEngine
target_link_libraries(NovaraProject PRIVATE NovaraEngine)

target_precompile_headers(NovaraProject PUBLIC stdafx.h)

# Include directories for NovaraProject
target_include_directories(NovaraProject PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/Prefabs"
)


# External dependencies
set(EXTERNAL_DIR "${CMAKE_SOURCE_DIR}/Libraries")

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


set(vld_include "${CMAKE_SOURCE_DIR}/Libraries/vld/include")


message(STATUS "External Libraries Directory: ${vld_include}")


# Link libraries based on build type
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(LIB_SUFFIX "debug")
else()
    set(LIB_SUFFIX "release")
endif()

message(STATUS "External Libraries Directory: ${EXTERNAL_DIR}/DirectXTex/lib/${LIB_SUFFIX}")


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