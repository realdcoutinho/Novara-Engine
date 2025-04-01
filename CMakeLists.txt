cmake_minimum_required(VERSION 3.20)
project(Novara)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add engine and project subdirectories
add_subdirectory(NovaraEngine)
add_subdirectory(NovaraProject)

install(TARGETS FinalGame DESTINATION bin)
include (InstallRequiredSystemLibraries)




## === Standardized output directories ===
## Use the same layout for all IDEs/build tools
#set(BIN_DIR ${CMAKE_BINARY_DIR}/bin)
#
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BIN_DIR}/lib)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BIN_DIR}/lib)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})

foreach(OUTPUTCONFIG Debug Release RelWithDebInfo MinSizeRel)
    string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG_UPPER)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER} ${BIN_DIR}/${OUTPUTCONFIG}/lib)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER} ${BIN_DIR}/${OUTPUTCONFIG}/lib)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER} ${BIN_DIR}/${OUTPUTCONFIG})
endforeach()







set(CPACK_PACKAGE_NAME "NovaraEngine")
set(CPACK_PACKAGE_VENDOR "Diogo Coutinho")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "MyGame - built using Novara Engine")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "NovaraEngine")

# Set installer output directory
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CPACK_OUTPUT_FILE_PREFIX "${CMAKE_SOURCE_DIR}/Installers/Debug")
else()
    set(CPACK_OUTPUT_FILE_PREFIX "${CMAKE_SOURCE_DIR}/Installers/Release")
endif()

# Optional icons/license
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")

# Set generator (you can also generate .zip or NSIS installer)
set(CPACK_GENERATOR "NSIS") # or "NSIS" for Windows installer .exe
set(CPACK_PACKAGE_FILE_NAME "NovaraEngine${CPACK_PACKAGE_VERSION}")

include(CPack)