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
 "Utils/MathHelper.h" 
 "Contents/ContentLoader.h" 
 "Managers/ContentManager.h" 
 "Managers/ContentManager.cpp" 
 "Misc/RenderTarget.h" 
 "Misc/RenderTarget.cpp" 
 "Graphics/DebugRenderer.h" 
 "Utils/VertexHelper.h" 
 "Utils/VertexHelper.cpp" 
 "Graphics/DebugRenderer.cpp" 
 "Utils/EffectHelper.h" 
 "Utils/EffectHelper.cpp" 
 "Contents/EffectLoader.h" 
 "Contents/EffectLoader.cpp" 
 "Utils/ImguiHelper.h" 
 "Utils/ImguiHelper.cpp" "Components/MeshDrawComponent.h" "Components/MeshDrawComponent.cpp" "Components/MeshIndexedDrawComponent.h" "Components/MeshIndexedDrawComponent.cpp" "Components/ModelComponent.h" "Components/ModelComponent.cpp" "Misc/MeshFilter.h" "Misc/MeshFilter.cpp" "Misc/TextureData.h" "Misc/TextureData.cpp" "Misc/ModelAnimator.h" "Misc/ModelAnimator.cpp" "Components/ParticleEmitterComponent.h" "Components/ParticleEmitterComponent.cpp" "Components/RigidBodyComponent.h" "Components/RigidBodyComponent.cpp" "Components/SpriteComponent.h" "Components/SpriteComponent.CPP" "Contents/MeshFilterLoader.h" "Contents/MeshFilterLoader.CPP" "Utils/BinaryReader.h" "Utils/BinaryReader.cpp" "Contents/PxMeshLoader.h" "Contents/PxMeshLoader.cpp" "Contents/SpriteFontLoader.h" "Contents/SpriteFontLoader.cpp" "Misc/SpriteFont.h" "Misc/SpriteFont.cpp" "Contents/TextureDataLoader.h" "Contents/TextureDataLoader.cpp" "Graphics/ShadowMapRenderer.h" "Graphics/ShadowMapRenderer.cpp" "Misc/ShadowMapMaterial.h" "Misc/ShadowMapMaterial.cpp" "Graphics/SpriteRenderer.h" "Graphics/SpriteRenderer.cpp" "Graphics/TextRenderer.h" "Graphics/TextRenderer.cpp" "Misc/PostProcessingMaterial.h" "Misc/PostProcessingMaterial.cpp" "Misc/ParticleMaterial.h" "Misc/ParticleMaterial.cpp")

# Optional: Add include directories for engine users
target_include_directories(NovaraEngine PUBLIC 

    ${CMAKE_CURRENT_SOURCE_DIR}
    
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
    ${CMAKE_CURRENT_SOURCE_DIR}/Graphics


    # External libraries
    ${CMAKE_SOURCE_DIR}/Libraries/FX11/include
    ${CMAKE_SOURCE_DIR}/Libraries/DirectXTex/include
    ${CMAKE_SOURCE_DIR}/Libraries/imgui/include
    ${CMAKE_SOURCE_DIR}/Libraries/PhysX/include
    ${CMAKE_SOURCE_DIR}/Libraries/FMOD/include
    ${CMAKE_SOURCE_DIR}/Libraries/vld/include

)

target_precompile_headers(NovaraEngine PRIVATE PCH/EnginePCH.h)

# Determine PhysX lib subfolder based on build type
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(PHYSX_LIB_SUBDIR "debug")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(PHYSX_LIB_SUBDIR "release")
else()
    set(PHYSX_LIB_SUBDIR "checked")  # fallback ou para RelWithDebInfo
endif()

# Final PhysX lib path
set(PHYSX_LIB_PATH "${CMAKE_SOURCE_DIR}/Libraries/PhysX/lib/${PHYSX_LIB_SUBDIR}")
message(STATUS "PhysX lib path: ${PHYSX_LIB_PATH}")





if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(FX11_LIB_SUBDIR "debug")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(FX11_LIB_SUBDIR "release")
else()
    set(FX11_LIB_SUBDIR "profile")  # fallback
endif()

set(FX11_LIB_PATH "${CMAKE_SOURCE_DIR}/Libraries/FX11/lib/${FX11_LIB_SUBDIR}")
message(STATUS "FX11 lib path: ${FX11_LIB_PATH}")



if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(IMGUI_LIB_SUBDIR "debug")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(IMGUI_LIB_SUBDIR "release")
else()
    set(IMGUI_LIB_SUBDIR "debug")  # fallback
endif()

set(IMGUI_LIB_PATH "${CMAKE_SOURCE_DIR}/Libraries/imgui/lib/${IMGUI_LIB_SUBDIR}")
message(STATUS "IMGUI lib path: ${IMGUI_LIB_PATH}")


target_link_libraries(NovaraEngine PUBLIC
    d3d11
    dxgi
    d3dcompiler
    
    
    "${FX11_LIB_PATH}/Effects11.lib"

    "${IMGUI_LIB_PATH}/ImGui_x64.lib"

    "${PHYSX_LIB_PATH}/PhysX_64.lib"
    "${PHYSX_LIB_PATH}/PhysXCharacterKinematic_static_64.lib"
    "${PHYSX_LIB_PATH}/PhysXCommon_64.lib" # <- nota: n�o tem _static no nome, mas parece ser release
    "${PHYSX_LIB_PATH}/PhysXExtensions_static_64.lib"
    "${PHYSX_LIB_PATH}/PhysXFoundation_64.lib"
    "${PHYSX_LIB_PATH}/PhysXPvdSDK_static_64.lib"
    "${PHYSX_LIB_PATH}/PhysXTask_static_64.lib"
    "${PHYSX_LIB_PATH}/PhysXVehicle_static_64.lib"
    "${PHYSX_LIB_PATH}/SceneQuery_static_64.lib"
    "${PHYSX_LIB_PATH}/SimulationController_static_64.lib"
)

target_compile_definitions(NovaraEngine PUBLIC PX_STATIC_LIB)


file(GLOB PHYSX_DLLS "${CMAKE_SOURCE_DIR}/Libraries/PhysX/bin/checked/*.dll")

set(DLL_DESTINATION "${CMAKE_BINARY_DIR}/NovaraProject")

foreach(DLL ${PHYSX_DLLS})
    get_filename_component(DLL_NAME "${DLL}" NAME)
    file(COPY "${DLL}" DESTINATION "${DLL_DESTINATION}")
endforeach()