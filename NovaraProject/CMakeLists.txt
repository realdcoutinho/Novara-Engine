add_executable(MyGame
    main.cpp
    MainGame.cpp
    MainGame.h
 "pch.h" "MinionScene.cpp" "MinionScene.h")

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