cmake_minimum_required(VERSION 3.20)
project(Novara)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add engine and project subdirectories
add_subdirectory(NovaraEngine)
add_subdirectory(NovaraProject)
