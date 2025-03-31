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
 "Prefabs/FixedCamera.cpp" 
 "Prefabs/FreeCamera.h" 
 "Prefabs/FreeCamera.cpp" 
 "Managers/InputManager.h" 
 "Managers/InputManager.cpp" 
 "Base/Enumerations.h" 
 "Utils/Utils.h" 
 "Utils/Macros.h" 
 "Utils/Singleton.h" 
 "Base/GameTime.h" 
 "Base/GameTime.cpp" 
 "Base/GameStats.h" 
 "Base/GameStats.cpp" 
 "Managers/SceneManager.h" 
 "Managers/SceneManager.cpp" 
 "Managers/PhysXManager.h" 
 "Managers/PhysXManager.cpp" 
 "Managers/LightManager.h" 
 "Managers/LightManager.cpp" 
 "Managers/MaterialManager.h" 
 "Managers/MaterialManager.cpp" 
 "Misc/BaseMaterial.h" 
 "Misc/BaseMaterial.cpp" 
 "Misc/Material.h" 
 "Misc/Material.cpp" 
 "Utils/PhysxHelper.h" 
 "Utils/PhysxHelper.cpp" 
 "Utils/MathHelper.H" 
 "Contents/ContentLoader.h" 
 "Managers/ContentManager.h" 
 "Managers/ContentManager.cpp" 
 "Misc/RenderTarget.h" 
 "Misc/RenderTarget.cpp")

# Optional: Add include directories for engine users
target_include_directories(NovaraEngine PUBLIC 

    ${CMAKE_CURRENT_SOURCE_DIR},
    
    ${CMAKE_CURRENT_SOURCE_DIR}/Base
    ${CMAKE_CURRENT_SOURCE_DIR}/Components
    ${CMAKE_CURRENT_SOURCE_DIR}/PCH
    ${CMAKE_CURRENT_SOURCE_DIR}/Scenegraph
    ${CMAKE_CURRENT_SOURCE_DIR}/PhysX
    ${CMAKE_CURRENT_SOURCE_DIR}/Managers
    ${CMAKE_CURRENT_SOURCE_DIR}/Utils
    ${CMAKE_CURRENT_SOURCE_DIR}/Prefabs
    ${CMAKE_CURRENT_SOURCE_DIR}/Misc
    ${CMAKE_CURRENT_SOURCE_DIR}/Contents


    # External libraries
    ${CMAKE_SOURCE_DIR}/Libraries/FX11/include
    ${CMAKE_SOURCE_DIR}/Libraries/DirectXTex/include
    ${CMAKE_SOURCE_DIR}/Libraries/imgui/include
    ${CMAKE_SOURCE_DIR}/Libraries/PhysX/include
    ${CMAKE_SOURCE_DIR}/Libraries/FMOD/include
    ${CMAKE_SOURCE_DIR}/Libraries/vld/include

)

target_precompile_headers(NovaraEngine PRIVATE PCH/EnginePCH.h)

# Path para os .lib
#link_directories(${CMAKE_SOURCE_DIR}/Libraries/PhysX/lib/checked)

message(STATUS "PhysX lib path: ${CMAKE_SOURCE_DIR}/Libraries/PhysX/lib/checked")


# Link required system libraries for DirectX
target_link_libraries(NovaraEngine PUBLIC
    d3d11
    dxgi
    d3dcompiler

    "${CMAKE_SOURCE_DIR}/Libraries/PhysX/lib/checked/PhysX_64.lib"
    "${CMAKE_SOURCE_DIR}/Libraries/PhysX/lib/checked/PhysXCharacterKinematic_static_64.lib"
    "${CMAKE_SOURCE_DIR}/Libraries/PhysX/lib/checked/PhysXCommon_64.lib"
    #"${CMAKE_SOURCE_DIR}/Libraries/PhysX/lib/checked/PhysXCooking_64.lib"
    "${CMAKE_SOURCE_DIR}/Libraries/PhysX/lib/checked/PhysXExtensions_static_64.lib"
    "${CMAKE_SOURCE_DIR}/Libraries/PhysX/lib/checked/PhysXFoundation_64.lib"
    "${CMAKE_SOURCE_DIR}/Libraries/PhysX/lib/checked/PhysXPvdSDK_static_64.lib"
    #"${CMAKE_SOURCE_DIR}/Libraries/PhysX/lib/checked/PhysXTask_static_64.lib"
    #"${CMAKE_SOURCE_DIR}/Libraries/PhysX/lib/checked/PhysXVehicle_static_64.lib"
    #"${CMAKE_SOURCE_DIR}/Libraries/PhysX/lib/checked/SceneQuery_static_64.lib"
    #"${CMAKE_SOURCE_DIR}/Libraries/PhysX/lib/checked/SimulationController_static_64.lib"
)

target_compile_definitions(NovaraEngine PUBLIC PX_STATIC_LIB)


#target_link_libraries(NovaraEngine
#    PUBLIC
#        PhysX_64
#        PhysXCommon_64
#        PhysXExtensions_static_64
#        PhysXPvdSDK_static_64
#        PhysXFoundation_64
#        PhysXCharacterKinematic_static_64
#)
#
#target_include_directories(NovaraEngine
#    PUBLIC
#        ${PHYSX_SDK_DIR}/include
#        ${PHYSX_SDK_DIR}/source/physx/include
#        ${PHYSX_SDK_DIR}/source/physxvehicle/include
#)
#
#link_directories(
#    ${PHYSX_SDK_DIR}/lib/${PLATFORM}  # Ex: lib/windows.x86_64.vc142.md/debug
#)

#set(PHYSX_LIB_DIR ${CMAKE_SOURCE_DIR}/Libraries/PhysX/lib/checked)
#
#target_link_libraries(NovaraEngine PUBLIC
#    ${PHYSX_LIB_DIR}/PhysX_64.lib
#    ${PHYSX_LIB_DIR}/PhysXCommon_64.lib
#    ${PHYSX_LIB_DIR}/PhysXFoundation_64.lib
#    ${PHYSX_LIB_DIR}/PhysXExtensions_static_64.lib
#    ${PHYSX_LIB_DIR}/PhysXPvdSDK_static_64.lib
#    ${PHYSX_LIB_DIR}/PhysXCharacterKinematic_static_64.lib
#)
#
## Match PhysX release runtime with /MDd (Debug)
#target_compile_options(NovaraEngine PRIVATE /MDd)
#
#if (CMAKE_BUILD_TYPE STREQUAL "Debug")
#    target_compile_options(NovaraEngine PRIVATE /MDd)
#else()
#    target_compile_options(NovaraEngine PRIVATE /MD)
#endif()