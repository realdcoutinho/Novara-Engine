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
)

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




# Install Resources folder to install dir
install(DIRECTORY ${CMAKE_SOURCE_DIR}/NovaraProject/Resources DESTINATION bin)