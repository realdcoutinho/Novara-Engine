
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



#pragma region PHYSX
//NVIDIA PhysX
//https://gameworksdocs.nvidia.com/PhysX/4.0/documentation/PhysXGuide/Index.html
#pragma warning(push)
//#pragma warning ( disable : ALL_CODE_ANALYSIS_WARNINGS )
#include <PxPhysicsAPI.h>
#pragma warning(pop)
using namespace physx;

#pragma comment(lib, "PhysX_64.lib")
#pragma comment(lib, "PhysXFoundation_64.lib")
#pragma comment(lib, "PhysXCommon_64.lib")
#pragma comment(lib, "PhysXExtensions_static_64.lib")
#pragma comment(lib, "PhysXPvdSDK_static_64.lib")
#pragma comment(lib, "PhysXCharacterKinematic_static_64.lib")

#pragma endregion



#pragma region DIRECTX Extensions
//**FX11 (Helper for loading Effects (D3DX11))
//https://github.com/microsoft/FX11
#include <d3dx11effect.h>
//#pragma comment(lib, "Effects11.lib")

//*DirectXTex (Helper for loading Textures (D3DX11))
//https://github.com/microsoft/DirectXTex
#pragma warning(push)
//#pragma warning ( disable : ALL_CODE_ANALYSIS_WARNINGS)
#include <DirectXTex.h>
#pragma warning(pop)
//#pragma comment(lib, "DirectXTex.lib")

//*XINPUT 9.1
#include <Xinput.h>
#pragma comment(lib, "XINPUT9_1_0.LIB")
#pragma endregion


#pragma region IMGUI
#include <imgui.h>
#include <imgui_impl_win32.h>
#include <imgui_impl_dx11.h>

#pragma comment(lib, "ImGui_x64.lib")
#pragma endregion






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
#include "InputManager.h"
#include "PhysxProxy.h"
#include "FreeCamera.h"
#include "GameTime.h"
#include "Macros.h"
#include "Utils.h"
#include "Logger.h"
#include "Singleton.h"
#include "GameStats.h"
#include "NovaraSimulationFilterShader.h"
#include "PhysxAllocator.h"
#include "PhysxErrorCallback.h"
#include "ContentLoader.h"
#include "ContentManager.h"
#include "MaterialManager.h"
#include "SceneManager.h"
#include "PhysXManager.h"
#include "RenderTarget.h"
#include "MathHelper.h"
#include "VertexHelper.h"
#include "PhysxHelper.h"
#include "EffectHelper.h"
#include "DebugRenderer.h"
#include "EffectLoader.h"
#include "ImguiHelper.h"
#include "Enumerations.h"
#include "ModelComponent.h"
#include "TextureData.h"
#include "MeshFilter.h"
#include "MeshDrawComponent.h"
#include "MeshIndexedDrawComponent.h"
#include "BaseMaterial.h"
#include "ModelAnimator.h"
#include "BinaryReader.h"
#include "SpriteFont.h"
#include "Material.h"
#include "ShadowMapMaterial.h"
#include "ShadowMapRenderer.h"
#include "PostProcessingMaterial.h"





