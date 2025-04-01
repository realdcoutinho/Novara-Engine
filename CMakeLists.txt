cmake_minimum_required(VERSION 3.20)
project(Novara)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add engine and project subdirectories
add_subdirectory(NovaraEngine)
add_subdirectory(NovaraProject)

install(TARGETS MyGame DESTINATION bin)
include (InstallRequiredSystemLibraries)

set(CPACK_PACKAGE_NAME "NovaraGame")
set(CPACK_PACKAGE_VENDOR "Diogo Coutinho")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "MyGame - built using Novara Engine")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "NovaraGame")

# Optional icons/license
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")

# Set generator (you can also generate .zip or NSIS installer)
set(CPACK_GENERATOR "NSIS") # or "NSIS" for Windows installer .exe
set(CPACK_PACKAGE_FILE_NAME "NovaraGame${CPACK_PACKAGE_VERSION}")

include(CPack)