#pragma once

class RenderTarget;

class NovaraGame
{
public:

	NovaraGame();
	virtual ~NovaraGame();
	NovaraGame(const NovaraGame& other) = delete;
	NovaraGame(NovaraGame&& other) noexcept = delete;
	NovaraGame& operator=(const NovaraGame& other) = delete;
	NovaraGame& operator=(NovaraGame&& other) noexcept = delete;


	static LRESULT CALLBACK WindowsProcedureStatic(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	const GameContext& GetGameContext() const { return m_GameContext; }

	HRESULT Run(HINSTANCE hInstance);

	void SetRenderTarget(RenderTarget* renderTarget);
	RenderTarget* GetRenderTarget() const;

protected:
	virtual void OnGamePreparing(GameContext& gameContext) {}
	virtual LRESULT WindowProcedureHook(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	virtual void Initialize() = 0;

	bool m_IsActive{};

private:

	//FUNCTIONS
	//Initializations
	HRESULT InitializeAdapterAndOutput();
	HRESULT InitializeWindow();
	HRESULT InitializeDirectX();
	//HRESULT InitializePhysX() const;
	HRESULT InitializeImGui() const;
	HRESULT InitializeGame();

	void ValidateGameContext();
	void GameLoop() const;

	//Windows Proc
	void StateChanged(int state, bool active);
	LRESULT WindowsProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	HINSTANCE m_hInstance{};
	ComPtr<IDXGISwapChain> m_pSwapchain{};
	ComPtr<IDXGIFactory> m_pDxgiFactory{};
	D3D11_VIEWPORT m_Viewport{};

	unique_ptr<RenderTarget> m_pDefaultRenderTarget{};
	RenderTarget* m_pCurrentRenderTarget{};

	GameContext m_GameContext{};
};
