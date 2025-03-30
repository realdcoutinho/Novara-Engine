# Declare engine library
add_library(NovaraEngine
    Base/NovaraGame.cpp
 "Scenegraph/GameObject.h" 
 "Scenegraph/GameObject.cpp" 
 "Components/BaseComponent.h" 
 "Components/BaseComponent.cpp" 
 "Components/TransformComponent.cpp" 
 "Scenegraph/GameScene.h" 
 "Scenegraph/GameScene.cpp" 
 "Base/Structs.h" 
 "Components/ControllerComponent.h" 
 "Components/ControllerComponent.cpp" 
 "Components/CameraComponent.h" 
 "Components/CameraComponent.cpp" 
 "Base/Logger.cpp" 
 "Base/Logger.h" 
 "PhysX/PhysxProxy.h" 
 "PhysX/PhysxProxy.cpp" 
 "PhysX/NovaraSimulationFilterShader.h"  
 "PhysX/PhysxErrorCallback.cpp" 
 "PhysX/PhysxErrorCallback.h" 
 "Prefabs/FixedCamera.h" 
 "Prefabs/FixedCamera.cpp" "Prefabs/FreeCamera.h" "Prefabs/FreeCamera.cpp")

# Optional: Add include directories for engine users
target_include_directories(NovaraEngine PUBLIC 

    ${CMAKE_CURRENT_SOURCE_DIR},
    
    ${CMAKE_CURRENT_SOURCE_DIR}/Base
    ${CMAKE_CURRENT_SOURCE_DIR}/Components
    ${CMAKE_CURRENT_SOURCE_DIR}/PCH
    ${CMAKE_CURRENT_SOURCE_DIR}/Scenegraph
    ${CMAKE_CURRENT_SOURCE_DIR}/PhysX

    # External libraries
    ${CMAKE_SOURCE_DIR}/Libraries/FX11/include
    ${CMAKE_SOURCE_DIR}/Libraries/DirectXTex/include
    ${CMAKE_SOURCE_DIR}/Libraries/imgui/include
    ${CMAKE_SOURCE_DIR}/Libraries/PhysX/include
    ${CMAKE_SOURCE_DIR}/Libraries/FMOD/include
    ${CMAKE_SOURCE_DIR}/Libraries/vld/include

)

target_precompile_headers(NovaraEngine PRIVATE PCH/EnginePCH.h)