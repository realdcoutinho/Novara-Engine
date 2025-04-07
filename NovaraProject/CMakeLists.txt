add_executable(FinalGame
    main.cpp
    MainGame.cpp
    MainGame.h
         "pch.h"
         "Scenes/MinionScene.cpp"
         "Scenes/MinionScene.h"
        "Materials/ColorMaterial.cpp"
        "Materials/ColorMaterial.h"
        "Prefabs/CubePrefab.cpp"
        "Prefabs/CubePrefab.h"
        "Prefabs/SpherePrefab.h"
        "Prefabs/TorusPrefab.h"
        "Resources/Effects/PosNorm3D.fx"
        "Resources/Effects/PosNormCol3D.fx"
        "Resources/Effects/SpriteRenderer.fx"
        "Resources/Effects/TextRenderer.fx"
 "Scenes/Pong.cpp")

if (WIN32)
    set_target_properties(FinalGame PROPERTIES
        WIN32_EXECUTABLE TRUE
    )
endif()

# Link engine
target_link_libraries(FinalGame PRIVATE NovaraEngine)

# Include engine headers
target_include_directories(FinalGame PRIVATE
    ${CMAKE_SOURCE_DIR}/NovaraEngine
)


add_custom_command(
    TARGET FinalGame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_SOURCE_DIR}/NovaraProject/Resources"
            "$<TARGET_FILE_DIR:FinalGame>/Resources"
)


#add_custom_command(TARGET FinalGame POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy_if_different
#        "${CMAKE_SOURCE_DIR}/Libraries/PhysX/bin/$<CONFIG>/PhysX_64.dll"
#        "${CMAKE_SOURCE_DIR}/Libraries/PhysX/bin/$<CONFIG>/PhysXCommon_64.dll"
#        "${CMAKE_SOURCE_DIR}/Libraries/FMOD/bin/$<CONFIG>/fmod64.dll"
#        "${CMAKE_SOURCE_DIR}/Libraries/FX11/bin/$<CONFIG>/Effects11.dll"
#        $<TARGET_FILE_DIR:FinalGame>
#)


#add_custom_command(TARGET FinalGame POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy_if_different
#        "${CMAKE_SOURCE_DIR}/Libraries/PhysX/bin/$<CONFIG>/PhysX_64.dll"
#        "${CMAKE_SOURCE_DIR}/Libraries/PhysX/bin/$<CONFIG>/PhysXCommon_64.dll"
#        "${CMAKE_SOURCE_DIR}/Libraries/PhysX/bin/$<CONFIG>/PhysXCooking_64.dll"
#        "${CMAKE_SOURCE_DIR}/Libraries/PhysX/bin/$<CONFIG>/PhysXFoundation_64.dll"
#        "${CMAKE_SOURCE_DIR}/Libraries/FMOD/bin/$<CONFIG>/fmod64.dll"
#        "${CMAKE_SOURCE_DIR}/Libraries/FX11/bin/$<CONFIG>/Effects11.dll"
#        $<TARGET_FILE_DIR:FinalGame>
#)



# Install Resources folder to install dir
install(DIRECTORY ${CMAKE_SOURCE_DIR}/NovaraProject/Resources DESTINATION bin)