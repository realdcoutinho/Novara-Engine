
#ifdef _WIN32
#include <Windows.h>
#endif

// DirectX core headers
#include <d3d11.h>
#include <dxgi.h>
#include <d3dcompiler.h>

//DirectXMath
#include <DirectXCollision.h>
#include <DirectXColors.h>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
using namespace DirectX;


//Core
#include <wchar.h>
#include <string>
#include <memory>
#include <locale.h>
#include <codecvt>
#include <cwctype>

//STL
#include <algorithm>
#include <functional>

//Misc
#include <source_location>
#include <filesystem>
#include <format>
#include <codeanalysis\warnings.h>
#include <rpc.h>
#include <typeinfo>
namespace fs = std::filesystem;
#pragma endregion



//Streams
#include <iostream>
#include <fstream>
#include <sstream>

//Containers
#include <vector>
#include <map>
#include <unordered_map>


//ENGINE HEADERS
#include "BaseComponent.h"
#include "GameObject.h"
#include "TransformComponent.h"
#include "GameScene.h"
#include "CameraComponent.h"
//#include "Structs.h"

//#include "Logger.h"


#pragma region PHYSX
//NVIDIA PhysX
//https://gameworksdocs.nvidia.com/PhysX/4.0/documentation/PhysXGuide/Index.html
#pragma warning(push)
//#pragma warning ( disable : ALL_CODE_ANALYSIS_WARNINGS )
#include <PxPhysicsAPI.h>
#pragma warning(pop)
using namespace physx;


//#include <gtest/gtest.h>
