# Declare engine library (apenas ficheiros .cpp!)
add_library(NovaraEngine
    Base/NovaraGame.cpp
    Scenegraph/GameObject.cpp
    Components/BaseComponent.cpp
    Components/TransformComponent.cpp
    Scenegraph/GameScene.cpp
    Components/ControllerComponent.cpp
    Components/CameraComponent.cpp
    Base/Logger.cpp
    PhysX/PhysxProxy.cpp
    PhysX/PhysxErrorCallback.cpp
    Prefabs/FixedCamera.cpp
    Prefabs/FreeCamera.cpp
    Managers/InputManager.cpp
    Base/GameTime.cpp
    Base/GameStats.cpp
    Managers/SceneManager.cpp
    Managers/PhysXManager.cpp
    Managers/LightManager.cpp
    Managers/MaterialManager.cpp
    Misc/BaseMaterial.cpp
    Misc/Material.cpp
    Utils/PhysxHelper.cpp
    Managers/ContentManager.cpp
    Misc/RenderTarget.cpp
    Graphics/DebugRenderer.cpp
    Utils/VertexHelper.cpp
    Utils/EffectHelper.cpp
    Contents/EffectLoader.cpp
    Utils/ImguiHelper.cpp
    Components/MeshDrawComponent.cpp
    Components/MeshIndexedDrawComponent.cpp
    Components/ModelComponent.cpp
    Misc/MeshFilter.cpp
    Misc/TextureData.cpp
    Misc/ModelAnimator.cpp
    Components/ParticleEmitterComponent.cpp
    Components/RigidBodyComponent.cpp
    Components/SpriteComponent.CPP    # <-- ok manter .CPP se for mesmo esse nome
    Contents/MeshFilterLoader.CPP     # <-- mesmo caso aqui
    Utils/BinaryReader.cpp
    Contents/PxMeshLoader.cpp
    Contents/SpriteFontLoader.cpp
    Misc/SpriteFont.cpp
    Contents/TextureDataLoader.cpp
    Graphics/ShadowMapRenderer.cpp
    Misc/ShadowMapMaterial.cpp
    Graphics/SpriteRenderer.cpp
    Graphics/TextRenderer.cpp
    Misc/PostProcessingMaterial.cpp
    Misc/ParticleMaterial.cpp
    Managers/SoundManager.cpp
)

add_compile_options(/wd26495)
add_compile_options(/wd26495) # Disable warning C26495: Variable is uninitialized.

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
    set(PHYSX_LIB_SUBDIR "release")  # fallback ou para RelWithDebInfo
endif()

# Final PhysX lib path
set(PHYSX_LIB_PATH "${CMAKE_SOURCE_DIR}/Libraries/PhysX/lib/${PHYSX_LIB_SUBDIR}")
message(STATUS "PhysX lib path: ${PHYSX_LIB_PATH}")


# Determine PhysX lib subfolder based on build type
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(DIRECTX_LIB_SUBDIR "debug")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(DIRECTX_LIB_SUBDIR "release")
else()
    set(DIRECTX_LIB_SUBDIR "release")  # fallback ou para RelWithDebInfo
endif()

# Final PhysX lib path
set(DIRECTX_LIB_PATH "${CMAKE_SOURCE_DIR}/Libraries/DirectXTex/lib/${DIRECTX_LIB_SUBDIR}")
message(STATUS "DirectXTex lib path: ${DIRECTX_LIB_PATH}")





if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(FX11_LIB_SUBDIR "debug")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(FX11_LIB_SUBDIR "release")
else()
    set(FX11_LIB_SUBDIR "release")  # fallback
endif()

set(FX11_LIB_PATH "${CMAKE_SOURCE_DIR}/Libraries/FX11/lib/${FX11_LIB_SUBDIR}")
message(STATUS "FX11 lib path: ${FX11_LIB_PATH}")



if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(IMGUI_LIB_SUBDIR "debug")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(IMGUI_LIB_SUBDIR "release")
else()
    set(IMGUI_LIB_SUBDIR "release")  # fallback
endif()

set(IMGUI_LIB_PATH "${CMAKE_SOURCE_DIR}/Libraries/imgui/lib/${IMGUI_LIB_SUBDIR}")
message(STATUS "IMGUI lib path: ${IMGUI_LIB_PATH}")


if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(FMOD_LIB_SUBDIR "debug")
    set(FMOD_LIB_NAME "fmodL64_vc.lib")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(FMOD_LIB_SUBDIR "release")
    set(FMOD_LIB_NAME "fmod64_vc.lib")
else()
    set(FMOD_LIB_SUBDIR "release")  # fallback
    set(FMOD_LIB_NAME "fmod64_vc.lib")
endif()

set(FMOD_LIB_PATH "${CMAKE_SOURCE_DIR}/Libraries/FMOD/lib/${FMOD_LIB_SUBDIR}")

message(STATUS "FMOD lib path: ${FMOD_LIB_PATH}")


target_link_libraries(NovaraEngine PUBLIC
    d3d11
    dxgi
    d3dcompiler

    Xinput9_1_0
    
    
    "${FX11_LIB_PATH}/Effects11.lib"

    "${IMGUI_LIB_PATH}/ImGui_x64.lib"
    "${FMOD_LIB_PATH}/${FMOD_LIB_NAME}"

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

    "${DIRECTX_LIB_PATH}/DirectXTex.lib"
)


target_compile_definitions(NovaraEngine PUBLIC PX_STATIC_LIB)


file(GLOB PHYSX_DLLS "${CMAKE_SOURCE_DIR}/Libraries/PhysX/bin/checked/*.dll")

set(DLL_DESTINATION "${CMAKE_BINARY_DIR}/NovaraProject")

foreach(DLL ${PHYSX_DLLS})
    get_filename_component(DLL_NAME "${DLL}" NAME)
    file(COPY "${DLL}" DESTINATION "${DLL_DESTINATION}")
endforeach()

# Install PhysX DLLs into bin directory of the install folder
install(FILES ${PHYSX_DLLS} DESTINATION bin)







file(GLOB FMOD_DLLS "${CMAKE_SOURCE_DIR}/Libraries/FMOD/bin/${FMOD_LIB_SUBDIR}/*.dll")

set(DLL_DESTINATION "${CMAKE_BINARY_DIR}/NovaraProject")

foreach(DLL ${FMOD_DLLS})
    get_filename_component(DLL_NAME "${DLL}" NAME)
    file(COPY "${DLL}" DESTINATION "${DLL_DESTINATION}")
endforeach()

# Install FMOD DLLs into bin directory of the install folder
install(FILES ${FMOD_DLLS} DESTINATION bin)
