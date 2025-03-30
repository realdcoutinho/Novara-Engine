cmake_minimum_required(VERSION 3.20)
project(Novara)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directories for your libraries
include_directories(
    ${CMAKE_SOURCE_DIR}/Libraries/FX11/include
    ${CMAKE_SOURCE_DIR}/Libraries/DirectXTex/include
    ${CMAKE_SOURCE_DIR}/Libraries/imgui/include
    ${CMAKE_SOURCE_DIR}/Libraries/PhysX/include
    ${CMAKE_SOURCE_DIR}/Libraries/FMOD/include
    ${CMAKE_SOURCE_DIR}/Libraries/vld/include
)


# Add engine and project subdirectories
add_subdirectory(NovaraEngine)
add_subdirectory(NovaraProject)


