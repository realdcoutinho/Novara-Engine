cmake_minimum_required(VERSION 3.20)
project(Novara)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add engine and project subdirectories
add_subdirectory(NovaraEngine)
add_subdirectory(NovaraProject)

if (MSVC)
    message(STATUS "Building with MSVC")
    add_definitions(-D_USE_MATH_DEFINES)
    # Maybe link PhysX, DX12-specific libs
elseif (CMAKE_COMPILER_IS_GNUCXX)
    message(STATUS "Building with MinGW/GCC")
    # Setup for MinGW later, if needed
endif()