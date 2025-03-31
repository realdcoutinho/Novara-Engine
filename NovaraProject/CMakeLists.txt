add_executable(MyGame
    main.cpp
    MainGame.cpp
    MainGame.h
 "pch.h")

# Link engine
target_link_libraries(MyGame PRIVATE NovaraEngine)

# Include engine headers
target_include_directories(MyGame PRIVATE
    ${CMAKE_SOURCE_DIR}/NovaraEngine
)