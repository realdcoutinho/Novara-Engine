#pragma once

#include <d3d11.h>
#include <dxgi.h>
#include <DirectXColors.h>
#include <DirectXMath.h>
#include <memory>
#include <xstring>




using namespace std;

class CameraComponent;
class InputManager;
class LightManager;
class GameTime;
class NovaraGame;
class MaterialManager;


struct D3D11Context
{
	ID3D11Device* pDevice{};
	ID3D11DeviceContext* pDeviceContext{};
	IDXGIAdapter* pAdapter{};
	IDXGIOutput* pOutput{};
};

struct SceneSettings
{
	bool showInfoOverlay{ true };
	bool enableOnGUI{ false };

	bool drawPhysXDebug{ true };
	bool drawGrid{ true };
	bool drawUserDebug{ true };

	bool vSyncEnabled{ true };
	//XMFLOAT4 clearColor{ DirectX::Colors::CornflowerBlue };
	DirectX::XMFLOAT4 clearColor;

	SceneSettings()
		: clearColor()
	{
		// Convert DirectX::Colors::CornflowerBlue to XMFLOAT4
		DirectX::XMStoreFloat4(&clearColor, DirectX::Colors::CornflowerBlue);
	}

	void Toggle_ShowInfoOverlay() { showInfoOverlay = !showInfoOverlay; }
	bool Toggle_DrawPhysXDebug() { drawPhysXDebug = !drawPhysXDebug; }
	bool Toggle_DrawGrid() { drawGrid = !drawGrid; }
};

struct SceneContext
{
	unique_ptr<InputManager> pInput{};
	unique_ptr<LightManager> pLights{};
	unique_ptr<GameTime> pGameTime{};
	CameraComponent* pCamera{};

	D3D11Context d3dContext{};

	float windowWidth{};
	float windowHeight{};
	float aspectRatio{};
	UINT frameNumber{};

	SceneSettings settings{};
};

struct GameContext
{
	UINT windowWidth{ 1280 };
	UINT windowHeight{ 720 };
	std::string windowTitle{ "Novara Engine" };
	HWND windowHandle{};
	std::wstring contentRoot{ L"./Resources/" };
	float inputUpdateFrequency{ 0.016f };

	D3D11Context d3dContext{};
	NovaraGame* pGame{};
};

struct PerfStats
{
	float averageFps;
	float averageMs;
	float highMs;
	float lowMs;

	float averageFps_interim;
	float averageMs_interim;

	long frameNr;

	void Reset()
	{
		averageFps = 0;
		averageMs = 0;
		highMs = 0;
		lowMs = 0;

		averageFps_interim = 0;
		averageMs_interim = 0;

		frameNr = 0;
	}
};