
![20250327_2252_Novara Engine Logo Design_simple_compose_01jqcsekc6enfvefw5tn10rgxx](https://github.com/user-attachments/assets/1abc67da-a420-488d-920a-dbb4683bfeb9)

# Novara Engine 🚀  

Novara Engine is a **DirectX-based** game engine built from the ground up, inspired by the Overlord Engine from the Graphics Programming 2 course. The goal of this project is to **modernize and fully recreate** the engine while implementing best practices and up-to-date technologies.

## 🎯 **Project Goals**
- Recreate the core functionality of the a 3D game Engine
- Implement **modern rendering techniques** using DirectX
- Ensure a **modular and scalable** architecture
- Keep the engine **optimized and extensible** for future use

## ⚙️ **Current Features**
- Basic project structure & setup
- DirectX-based rendering pipeline (WIP)
- Modular folder structure for scalability

## 📌 **Planned Features**
- Advanced rendering techniques (PBR, shadows, post-processing)
- Physics & collision system
- Audio integration
- Playable Game

## 🛠️ **Building & Running**
✅ *Requirements*:
- CMake (v3.10 or higher)
- MSVC Toolchain (via Visual Studio 2022 or Build Tools for Visual Studio)
- Windows SDK
- NSIS (optional)(https://nsis.sourceforge.io/) (for building Windows installer `.exe`)
- ⚠️ GCC and Clang are not supported. This project requires the MSVC compiler due to its reliance on Windows-specific features and DirectX.

## 🚀 **Building the Engine**
You can build and run Novara Engine using your preferred workflow:

### 🧩 **Option 1: CLion (Recommended)**
- Open the project folder in CLion
- Go to File > Settings > Build, Execution, Deployment > Toolchains
- Set the toolchain to use Visual Studio (MSVC)
- CLion will automatically detect CMake and generate all necessary build files

### 🎯 **Option 2: Visual Studio (CMake-based Workflow)**
- Open Visual Studio 2022
- Select "Open a local folder" and choose the root of the project
- Visual Studio will detect the CMakeLists.txt file and configure the project automatically

## 🎮 **Building the Game (Packaging into Installer or Zip)**

Once the engine and game are compiled, you can package your game using **CPack** to generate a `.exe` installer or `.zip` file.

### ✅ Steps:
1. Build the project in **Release** or **Debug** mode using CLion or Visual Studio.
2. Open a terminal and navigate to the corresponding build output folder, usually something like:

```cd path/to/project/cmake-build/x64-Release```

3. Run the following command to package the game:

```cpack -C RELEASE```

Replace `RELEASE` with `DEBUG` if you're building the Debug configuration.

This will generate an installer (if you're using NSIS) or a zip file containing your game under the name defined by `CPack`.

---

### ⚙️ **Customizing Game Metadata**

In your `CMakeLists.txt`, you can customize the generated installer or archive by changing the following:

```
cmake
set(CPACK_PACKAGE_NAME "NovaraGame")										# Game name
set(CPACK_PACKAGE_VENDOR "Diogo Coutinho")									# Developer or studio
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "MyGame - built using Novara Engine")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "NovaraGame")							# Install directory
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")		# Optional license file
set(CPACK_GENERATOR "NSIS")													# Installer format (e.g., "NSIS", "ZIP")
set(CPACK_PACKAGE_FILE_NAME "NovaraGame${CPACK_PACKAGE_VERSION}")			# Output filename
```

## 🔥 **Contributing**
This is an ongoing personal project, but contributions, feedback, and suggestions are welcome!
