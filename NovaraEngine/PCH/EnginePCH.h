
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


//STL
#include <algorithm>
#include <functional>
#include <typeinfo>
#include <string>



//ENGINE HEADERS
#include "BaseComponent.h"
#include "GameObject.h"
#include "TransformComponent.h"
#include "GameScene.h"
#include "Structs.h"