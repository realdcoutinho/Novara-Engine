add_executable(MyGame
    main.cpp
    MainGame.cpp
    MainGame.h
         "pch.h"
         "Scenes/MinionScene.cpp"
         "Scenes/MinionScene.h"
        "ColorMaterial.cpp"
        "ColorMaterial.h"
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
target_link_libraries(MyGame PRIVATE NovaraEngine)

# Include engine headers
target_include_directories(MyGame PRIVATE
    ${CMAKE_SOURCE_DIR}/NovaraEngine
)


add_custom_command(
    TARGET MyGame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_SOURCE_DIR}/NovaraProject/Resources"
            "$<TARGET_FILE_DIR:MyGame>/Resources"
)




# Install Resources folder to install dir
install(DIRECTORY ${CMAKE_SOURCE_DIR}/NovaraProject/Resources DESTINATION bin)