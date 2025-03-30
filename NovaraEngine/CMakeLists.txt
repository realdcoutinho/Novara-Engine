# Declare engine library
add_library(NovaraEngine
    Base/NovaraGame.cpp
 "Scenegraph/GameObject.h" "Scenegraph/GameObject.cpp")

# Optional: Add include directories for engine users
target_include_directories(NovaraEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR},
${CMAKE_CURRENT_SOURCE_DIR}/Base
${CMAKE_CURRENT_SOURCE_DIR}/PCH
${CMAKE_CURRENT_SOURCE_DIR}/Scenegraph
)

target_precompile_headers(NovaraEngine PRIVATE PCH/EnginePCH.h)