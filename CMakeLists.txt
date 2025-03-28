cmake_minimum_required(VERSION 3.20)

project(NovaraEngine LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DUNICODE -D_UNICODE)

# Add subdirectories
add_subdirectory(NovaraEngine)
add_subdirectory(NovaraProject)


