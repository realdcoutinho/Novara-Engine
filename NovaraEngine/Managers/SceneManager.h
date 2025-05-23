#pragma once
#include "Singleton.h"

class GameScene;

class SceneManager final : public Singleton<SceneManager>
{
public:
	SceneManager(const SceneManager& other) = delete;
	SceneManager(SceneManager&& other) noexcept = delete;
	SceneManager& operator=(const SceneManager& other) = delete;
	SceneManager& operator=(SceneManager&& other) noexcept = delete;

	bool AddGameScene(unique_ptr<GameScene> pScene);
	bool RemoveGameScene(GameScene* pScene);
	bool SetActiveGameScene(const std::wstring& sceneName);
	void NextScene();
	void PreviousScene();
	GameScene& GetActiveScene() const { return *m_ActiveScene; }
	const SceneContext& GetActiveSceneContext() const { return m_ActiveScene->GetSceneContext(); }
	SceneSettings& GetActiveSceneSettings() const { return m_ActiveScene->GetSceneSettings(); }

protected:
	void Initialize() override;

private:
	friend class NovaraGame;
	friend class Singleton<SceneManager>;
	SceneManager() = default;
	~SceneManager();

	void PostInitialize() const;
	void WindowStateChanged(int state, bool active) const;
	void Update();
	void Draw() const;
	void OnGUI() const;

	vector<unique_ptr<GameScene>> m_pScenes{};
	GameScene* m_ActiveScene{};
	GameScene* m_NewActiveScene{};
};
