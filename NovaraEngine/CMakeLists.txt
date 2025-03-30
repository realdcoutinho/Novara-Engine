# Declare engine library
add_library(NovaraEngine
    Base/NovaraGame.cpp
 "Scenegraph/GameObject.h" "Scenegraph/GameObject.cpp" "Components/BaseComponent.h" "Components/BaseComponent.cpp" "Components/TransformComponent.cpp" "Scenegraph/GameScene.h" "Scenegraph/GameScene.cpp" "Base/Structs.h" "Components/ControllerComponent.h" "Components/ControllerComponent.cpp")

# Optional: Add include directories for engine users
target_include_directories(NovaraEngine PUBLIC 

    ${CMAKE_CURRENT_SOURCE_DIR},
    
    ${CMAKE_CURRENT_SOURCE_DIR}/Base
    ${CMAKE_CURRENT_SOURCE_DIR}/Components
    ${CMAKE_CURRENT_SOURCE_DIR}/PCH
    ${CMAKE_CURRENT_SOURCE_DIR}/Scenegraph

    # External libraries
    ${CMAKE_SOURCE_DIR}/Libraries/FX11/include
    ${CMAKE_SOURCE_DIR}/Libraries/DirectXTex/include
    ${CMAKE_SOURCE_DIR}/Libraries/imgui/include
    ${CMAKE_SOURCE_DIR}/Libraries/PhysX/include
    ${CMAKE_SOURCE_DIR}/Libraries/FMOD/include
    ${CMAKE_SOURCE_DIR}/Libraries/vld/include

)

target_precompile_headers(NovaraEngine PRIVATE PCH/EnginePCH.h)