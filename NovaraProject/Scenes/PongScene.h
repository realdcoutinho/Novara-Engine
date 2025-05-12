#pragma once
#include "GameScene.h"


#include <DirectXMath.h>
using namespace DirectX;

#include <PhysxProxy.h>


#pragma warning(disable: 4505 26812)
#include "fmod.hpp" //Precompiled Header
#include "fmod_errors.h"
#pragma warning(pop)

class RigidBodyComponent;

class PongScene final : public GameScene
{
public:
	PongScene() : GameScene(L"PongGame") {}
	~PongScene() override = default;

	PongScene(const PongScene& other) = delete;
	PongScene(PongScene&& other) noexcept = delete;
	PongScene& operator=(const PongScene& other) = delete;
	PongScene& operator=(PongScene&& other) noexcept = delete;

protected:
	void Initialize() override;
	void Update() override;

	PxPhysics& m_Physx{ PxGetPhysics() };


	void InitializePeddles();
	GameObject* m_pLeftPeddle{ nullptr };
	XMFLOAT3 m_pLeftPos{};
	RigidBodyComponent* m_pLeftTrigger{ nullptr };
	GameObject* m_pRightPeddle{ nullptr };
	XMFLOAT3 m_pRightPos{};
	RigidBodyComponent* m_pRightTrigger{ nullptr };

	//void PeddleMovement();
	float m_Speed{ 15.0f };
	float m_Size{ 8 };

	//void InitializeBall();
	GameObject* m_pBall{ nullptr };

	//void InitializeBorders();
	RigidBodyComponent* m_pTopWall{ nullptr };
	RigidBodyComponent* m_pBottomWall{ nullptr };
	RigidBodyComponent* m_pLeftWall{ nullptr };
	RigidBodyComponent* m_pRightWall{ nullptr };
	bool m_OutOfBounds{ false };


	//void BallMovement();
	XMFLOAT3 m_BallSpeed{};

	virtual void OnSceneActivated() override;

	//void Reset();
	bool m_GameStarted{ false };


	FMOD::Channel* m_pChannel2D{ nullptr };
	FMOD::Sound* m_pSound{};
	//void InitializeSounds();
	//void PlaySounds();

};
