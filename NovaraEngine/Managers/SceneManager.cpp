#include "EnginePCH.h"
#include "SceneManager.h"


void SceneManager::Initialize()
{
	for (const unique_ptr<GameScene>& pScene : m_pScenes)
	{
		pScene->RootInitialize(m_GameContext);
	}
}

SceneManager::~SceneManager()
{
}

bool SceneManager::AddGameScene(unique_ptr<GameScene> pScene)
{
	//check if scene already exists in vector
	if(std::ranges::find(m_pScenes, pScene) != m_pScenes.end())
	{
		Logger::LogWarning(L"Scene " + pScene.get()->m_SceneName + L" already exists!");
		return false;
	}

	if (m_IsInitialized) 
	{
		pScene->RootInitialize(m_GameContext);
		pScene->RootPostInitialize();
	}

	if (m_ActiveScene == nullptr && m_NewActiveScene == nullptr)
		m_NewActiveScene = pScene.get();

	m_pScenes.push_back(std::move(pScene));

	return true;
}

bool SceneManager::RemoveGameScene(GameScene* pScene)
{
	//takes in a unique_ptr from pScnes
	auto sceneMatcher = [pScene](const std::unique_ptr<GameScene>& scene)
		{
			return scene.get() == pScene;
		};

	//has any scene been removed
	bool wasRemoved = std::erase_if(m_pScenes, sceneMatcher) > 0;

	return wasRemoved;
}

void SceneManager::NextScene()
{
	for (unsigned int i = 0; i < m_pScenes.size(); ++i)
	{
		if (m_pScenes[i].get() == m_ActiveScene)
		{
			const auto nextScene = ++i % m_pScenes.size();
			m_NewActiveScene = m_pScenes[nextScene].get();
			break;
		}
	}
}

void SceneManager::PreviousScene()
{
	const UINT numScenes = static_cast<UINT>(m_pScenes.size());
	for (UINT i = 0; i < numScenes; ++i)
	{
		if (m_pScenes[i].get() == m_ActiveScene)
		{
			if (i == 0) i = numScenes;
			--i;
			m_NewActiveScene = m_pScenes[i].get();
			break;
		}
	}
}

bool SceneManager::SetActiveGameScene(const std::wstring& sceneName)
{
	//takes in a unique_ptr from pScnes
	auto sceneMatcher = [sceneName](const std::unique_ptr<GameScene>& scene)
		{
			//	return wcscmp(scene->m_SceneName.c_str(), sceneName.c_str()) == 0;
			return scene.get()->m_SceneName == sceneName;
		};

	auto it = std::ranges::find_if(m_pScenes, sceneMatcher);

	if (it == m_pScenes.end())
		throw std::exception("Scene not found");

	m_NewActiveScene = it->get();
	return true;
}

void SceneManager::WindowStateChanged(int state, bool active) const
{
	if (state == 0 && m_ActiveScene)
	{
		m_ActiveScene->RootWindowStateChanged(state, active);
	}
}

void SceneManager::PostInitialize() const
{
	for (const std::unique_ptr<GameScene>& pScene : m_pScenes)
	{
		pScene->RootPostInitialize();
	}
}

void SceneManager::Update()
{
	if (m_NewActiveScene != nullptr)
	{
		if (m_NewActiveScene != m_ActiveScene)
		{
			//Deactivate the current active scene
			if (m_ActiveScene != nullptr)
				m_ActiveScene->RootOnSceneDeactivated();

			//Set New Scene
			m_ActiveScene = m_NewActiveScene;

			//Active the new scene and reset SceneTimer
			m_ActiveScene->RootOnSceneActivated();
			GameStats::Reset(); //Reset performance stats
		}

		m_NewActiveScene = nullptr;
	}

	if (m_ActiveScene != nullptr)
	{
		DebugRenderer::BeginFrame(m_ActiveScene->m_SceneContext.settings);
		m_ActiveScene->RootUpdate();
		return;
	}

	ASSERT_IF(m_ActiveScene == nullptr, L"No Active Scene Set!")
}

void SceneManager::Draw() const
{
	if (m_ActiveScene != nullptr)
		m_ActiveScene->RootDraw();
}

void SceneManager::OnGUI() const
{
	if (m_ActiveScene != nullptr)
		m_ActiveScene->RootOnGUI();
}
