#pragma once
#include "PongScene.h"
//#include "Prefabs/CubePrefab.h"
//#include "Prefabs/SpherePrefab.h"
#include "../Prefabs/CubePrefab.h"
#include "../Prefabs/SpherePrefab.h"
#include <functional>




#include "FixedCamera.h"
#include "GameObject.h"
#include "TransformComponent.h"
#include "CameraComponent.h"
#include "RigidBodyComponent.h"
#include "Structs.h"
#include "GameTime.h"
#include "InputManager.h"
#include "GameScene.h"





void PongScene::Initialize()
{
	auto pFixedCamera = make_unique<FixedCamera>();
	XMVECTOR cameraPosition{ 0.0f, 35.0f, 0.0f };
	pFixedCamera->GetTransform().Translate(cameraPosition);
	XMFLOAT3 cameraAngle{ 90.0f, 0.0f, 0.0f };
	pFixedCamera->GetTransform().Rotate(cameraAngle, true);

	auto camera = pFixedCamera->GetComponent<CameraComponent>();
	//SetActiveCamera(camera);

	m_pCamera = pFixedCamera.get();
	AddChild(std::move(pFixedCamera));


	m_pBouncyMaterial = m_Physx.createMaterial(1.0f, 1.0f, 1.0f);

	float distance{ 18.0f };
	m_PlayerOnePos = XMFLOAT3{ -distance, 0.0f, 0.0f };
	m_pPlayerOne = InitializePlayer(m_PlayerOnePos);

	m_PlayerTwoPos = XMFLOAT3{ distance, 0.0f, 0.0f };
	m_pPlayerTwo = InitializePlayer(m_PlayerTwoPos);




	//InitializePeddles();
	InitializeBall();
	InitializeBorders();
	//InitializeSounds();

	m_SceneContext.settings.drawPhysXDebug = true;
	m_SceneContext.settings.clearColor = XMFLOAT4{ 0.0f, 0.0f, 0.0f, 1.0f };


}

void PongScene::PostInitialize()
{
	auto camComp = m_pCamera->GetComponent<CameraComponent>();
	SetActiveCamera(camComp);
}

CubePrefab* PongScene::InitializePlayer(XMFLOAT3& position)
{
	XMFLOAT3 dimensions{ 1.0f, 1.0f, 4.0f };
	PxBoxGeometry cubeGeometry = PxBoxGeometry(dimensions.x / 2.f, dimensions.y / 2.f, dimensions.z / 2.f);

	auto cube = make_unique<CubePrefab>(dimensions, XMFLOAT4{ Colors::BlanchedAlmond });


	cube->GetTransform().Translate(position);

	auto pTrigger = cube->AddComponent(std::move(make_unique<RigidBodyComponent>(false)));

	pTrigger->AddCollider(PxBoxGeometry{ dimensions.x / 2, dimensions.y / 2, dimensions.z / 2 }, *m_pBouncyMaterial, true);
	pTrigger->SetConstraint(RigidBodyConstraint::TransY, false);
	pTrigger->SetConstraint(RigidBodyConstraint::AllRot, false);

	cube->SetOnTriggerCallBack([=](GameObject* pTrigger, GameObject* m_pBall, PxTriggerAction action)
		{
			if (action == PxTriggerAction::ENTER && pTrigger && m_pBall)
			{
				m_BallSpeed.x *= -1;
				//PlaySounds();  
			}
		});

	auto pointer = cube.get();

	AddChild(std::move(cube));

	return pointer;
}

//void PongScene::InitializePeddles()
//{
//	auto pBouncyMaterial = m_Physx.createMaterial(1.0f, 1.0f, 1.0f);
//
//	XMFLOAT3 dimensions{ 1.0f, 1.0f, 4.0f };
//	float distance{ 18.0f };
//	PxBoxGeometry cubeGeometry = PxBoxGeometry(dimensions.x / 2.f, dimensions.y / 2.f, dimensions.z / 2.f);
//
//	//LEFT
//	{
//		
//		auto leftPeddle = make_unique<CubePrefab>(dimensions, XMFLOAT4{ Colors::BlanchedAlmond });
//		m_pLeftPos = XMFLOAT3{ -distance, 0.0f, 0.0f };
//		leftPeddle->GetTransform().Translate(m_pLeftPos);
//
//
//		auto leftTrigger = make_unique<RigidBodyComponent>(false);
//
//		
//
//			
//		m_pLeftTrigger = leftPeddle->AddComponent(std::move(leftTrigger));
//
//
//		m_pLeftTrigger->AddCollider(PxBoxGeometry{ dimensions.x / 2, dimensions.y / 2, dimensions.z / 2 }, *m_pBouncyMaterial, true);
//		m_pLeftTrigger->SetConstraint(RigidBodyConstraint::TransY, false);
//		m_pLeftTrigger->SetConstraint(RigidBodyConstraint::AllRot, false);
//
//		leftPeddle->SetOnTriggerCallBack([=](GameObject* m_pLeftTrigger, GameObject* m_pBall, PxTriggerAction action)
//			{
//				if (action == PxTriggerAction::ENTER && m_pLeftTrigger && m_pBall)
//				{
//					m_BallSpeed.x *= -1;
//					//PlaySounds();
//
//				}
//			});
//
//		m_pLeftPeddle = leftPeddle.get();
//		AddChild(std::move(leftPeddle));
//	}
//
//	//RIGHT
//	{
//		auto rightPeddle = make_unique<CubePrefab>(dimensions, XMFLOAT4{ Colors::BlanchedAlmond });
//		m_pRightPeddle = rightPeddle.get();
//		m_pRightPos = XMFLOAT3{ distance, 0.0f, 0.0f };
//		m_pRightPeddle->GetTransform().Translate(m_pRightPos);
//		AddChild(std::move(rightPeddle));
//
//		auto rightTrigger = make_unique<RigidBodyComponent>(false);
//		m_pRightTrigger = rightTrigger.get();
//
//		m_pRightTrigger = m_pRightPeddle->AddComponent(std::move(rightTrigger));
//		m_pRightTrigger->AddCollider(PxBoxGeometry{ dimensions.x / 2, dimensions.y / 2, dimensions.z / 2 }, *m_pBouncyMaterial, true);
//		m_pRightTrigger->SetConstraint(RigidBodyConstraint::TransY, false);
//		m_pRightTrigger->SetConstraint(RigidBodyConstraint::AllRot, false);
//
//		m_pRightPeddle->SetOnTriggerCallBack([=](GameObject* m_pRightTrigger, GameObject* m_pBall, PxTriggerAction action)
//			{
//				if (action == PxTriggerAction::ENTER && m_pRightTrigger && m_pBall)
//				{
//					m_BallSpeed.x *= -1;
//					//PlaySounds();
//
//				}
//			});
//	}
//}

void PongScene::InitializeBorders()
{
	XMFLOAT3 dimensions{ 0.5f, 0.5f, 0.5f };
	//TOP AND BOTTOM
	{
		XMFLOAT3 dimensionsCollider{ 40.0f, 3.0f, 1.0f };
		float zDistance{ 10.5f };
		//TOP
		{
			auto pTopWall = make_unique<CubePrefab>(dimensions, XMFLOAT4{ Colors::Black });
			pTopWall->GetTransform().Translate(0.0f, 0.0f, zDistance);

			m_pTopWall = pTopWall->AddComponent(std::move(make_unique<RigidBodyComponent>(false)));
			m_pTopWall->AddCollider(PxBoxGeometry{ dimensionsCollider.x / 2, dimensionsCollider.y / 2, dimensionsCollider.z / 2 }, *m_pBouncyMaterial, true);
			m_pTopWall->SetConstraint(RigidBodyConstraint::TransY, false);
			m_pTopWall->SetConstraint(RigidBodyConstraint::AllRot, false);

			pTopWall->SetOnTriggerCallBack([=](GameObject* m_pTopWall, GameObject* m_pBall, PxTriggerAction action)
				{
					if (action == PxTriggerAction::ENTER && m_pTopWall && m_pBall)
					{
						m_BallSpeed.z *= -1;
					}
				});

			AddChild(std::move(pTopWall));
		}

		//BOTTOM
		{
			auto pBottomWall = make_unique<CubePrefab>(dimensions, XMFLOAT4{ Colors::Black });
			pBottomWall->GetTransform().Translate(0.0f, 0.0f, -zDistance);
			

			m_pBottomWall = pBottomWall->AddComponent(std::move(make_unique<RigidBodyComponent>(false)));
			m_pBottomWall->AddCollider(PxBoxGeometry{ dimensionsCollider.x / 2, dimensionsCollider.y / 2, dimensionsCollider.z / 2 }, *m_pBouncyMaterial, true);
			m_pBottomWall->SetConstraint(RigidBodyConstraint::TransY, false);
			m_pBottomWall->SetConstraint(RigidBodyConstraint::AllRot, false);

			pBottomWall->SetOnTriggerCallBack([=](GameObject* m_pBottomWall, GameObject* m_pBall, PxTriggerAction action)
				{
					if (action == PxTriggerAction::ENTER && m_pBottomWall && m_pBall)
					{
						m_BallSpeed.z *= -1;
					}
				});

			AddChild(std::move(pBottomWall));
		}
	}

	//LEFT AND RIGHT
	{
		XMFLOAT3 dimensionsCollider{ 1.0f, 3.0f, 22.0f };
		float xDistance{ 22.0f };

		//LEFT
		{
			auto pLeftWall = make_unique<CubePrefab>(dimensions, XMFLOAT4{ Colors::Black });
			pLeftWall->GetTransform().Translate(-xDistance, 0.0f, 0.0f);

			m_pLeftWall = pLeftWall->AddComponent(std::move(make_unique<RigidBodyComponent>(false)));
			m_pLeftWall->AddCollider(PxBoxGeometry{ dimensionsCollider.x / 2, dimensionsCollider.y / 2, dimensionsCollider.z / 2 }, *m_pBouncyMaterial, true);
			m_pLeftWall->SetConstraint(RigidBodyConstraint::TransY, false);
			m_pLeftWall->SetConstraint(RigidBodyConstraint::AllRot, false);

			pLeftWall->SetOnTriggerCallBack([=](GameObject* m_pTopWall, GameObject* m_pBall, PxTriggerAction action)
				{
					if (action == PxTriggerAction::ENTER && m_pTopWall && m_pBall)
					{
						m_pBall->GetTransform().Translate(0.0f, 1.0f, 0.0f);
						m_BallSpeed = { 0.0f, 0.0f, 0.0f };
						m_OutOfBounds = true;
					}
				});

			AddChild(std::move(pLeftWall));

		}

		//RIGHT
		{
			auto pRightWall = make_unique<CubePrefab>(dimensions, XMFLOAT4{ Colors::Black });
			pRightWall->GetTransform().Translate(xDistance, 0.0f, 0.0f);
			

			m_pRightWall = pRightWall->AddComponent(std::move(make_unique<RigidBodyComponent>(false)));
			m_pRightWall->AddCollider(PxBoxGeometry{ dimensionsCollider.x / 2, dimensionsCollider.y / 2, dimensionsCollider.z / 2 }, *m_pBouncyMaterial, true);
			m_pRightWall->SetConstraint(RigidBodyConstraint::TransY, false);
			m_pRightWall->SetConstraint(RigidBodyConstraint::AllRot, false);

			pRightWall->SetOnTriggerCallBack([=](GameObject* m_pTopWall, GameObject* m_pBall, PxTriggerAction action)
				{
					if (action == PxTriggerAction::ENTER && m_pTopWall && m_pBall)
					{
						m_pBall->GetTransform().Translate(0.0f, 1.0f, 0.0f);
						m_BallSpeed = { 0.0f, 0.0f, 0.0f };
						m_OutOfBounds = true;
					}
				});
			
			AddChild(std::move(pRightWall));
		}
	}

}

void PongScene::InitializeBall()
{
	float radius = 0.75f;


	auto pBall = make_unique<SpherePrefab>(radius, 10, XMFLOAT4{ Colors::Red });
	pBall->GetTransform().Translate(0.0f, 0.0f, 0.0f);


	auto pRigidBody = make_unique<RigidBodyComponent>(false);
	pRigidBody->SetConstraint(RigidBodyConstraint::TransY, false);
	pRigidBody->SetConstraint(RigidBodyConstraint::AllRot, false);
	pRigidBody->AddCollider(PxSphereGeometry{ radius }, *m_pBouncyMaterial);

	pBall->AddComponent(std::move(pRigidBody));
	m_pBall = pBall.get();

	AddChild(std::move(pBall));

}



void PongScene::PeddleMovement()
{
	auto& input = m_SceneContext.GetInput();

	XMFLOAT3 leftKinematicPosition{ 0.0f, 0.0f, 0.0f };
	//lEFT PADDLE MOVEMENT
	{
		auto leftPos = m_pPlayerOne->GetTransform().GetPosition();
		if (leftPos.z < m_Size)
			if (input.IsKeyboardKey(InputState::down, 'Q'))
				leftPos.z += m_Speed * m_SceneContext.pGameTime->GetElapsed();

		if (leftPos.z > -m_Size)
			if (input.IsKeyboardKey(InputState::down, 'A'))
				leftPos.z -= m_Speed * m_SceneContext.pGameTime->GetElapsed();
		m_pPlayerOne->GetTransform().Translate(leftPos.x, leftPos.y, leftPos.z);
	}
	//rIGHT PADDLE MOVEMENT
	{
		auto rightPos = m_pPlayerTwo->GetTransform().GetPosition();
		if (rightPos.z < m_Size)
			if (input.IsKeyboardKey(InputState::down, VK_UP))
				rightPos.z += m_Speed * m_SceneContext.pGameTime->GetElapsed();

		if (rightPos.z > -m_Size)
			if (input.IsKeyboardKey(InputState::down, VK_DOWN))
				rightPos.z -= m_Speed * m_SceneContext.pGameTime->GetElapsed();

		m_pPlayerTwo->GetTransform().Translate(rightPos.x, rightPos.y, rightPos.z);
	}
}

void PongScene::BallMovement()
{
	auto ballPos = m_pBall->GetTransform().GetPosition();
	ballPos.x += m_BallSpeed.x * m_SceneContext.pGameTime->GetElapsed();
	ballPos.z += m_BallSpeed.z * m_SceneContext.pGameTime->GetElapsed();

	m_pBall->GetTransform().Translate(ballPos.x, 0.0f, ballPos.z);
}

void PongScene::Update()
{
	PeddleMovement();
	BallMovement();

	auto& input = m_SceneContext.GetInput();

	if (input.IsKeyboardKey(InputState::down, VK_SPACE) && (m_OutOfBounds))
	{
		m_BallSpeed.x = 10.0f;
		m_BallSpeed.z = 10.0f;
		m_OutOfBounds = !m_OutOfBounds;
	}

	if (input.IsKeyboardKey(InputState::down, VK_SPACE) && (!m_GameStarted))
	{
		m_BallSpeed.x = 10.0f;
		m_BallSpeed.z = 10.0f;
		m_GameStarted = true;
	}

	if (input.IsKeyboardKey(InputState::down, 'R'))
	{
		Reset();
	}


}

void PongScene::OnSceneActivated()
{
	Reset();
}

void PongScene::Reset()
{
	m_pPlayerOne->GetTransform().Translate(m_PlayerOnePos);
	m_pPlayerTwo->GetTransform().Translate(m_PlayerTwoPos);
	m_pBall->GetTransform().Translate(0.0f, 0.0f, 0.0f);
	m_BallSpeed.x = 0;
	m_BallSpeed.z = 0;
	m_GameStarted = false;
}


//void PongScene::InitializeSounds()
//{
//	auto pFmod = SoundManager::Get()->GetSystem();
//
//	/*FMOD_RESULT result = */pFmod->createStream("Resources/Sounds/pong.ogg", FMOD_DEFAULT, nullptr, &m_pSound);
//}
//
//void PongScene::PlaySounds()
//{
//	auto pFmod = SoundManager::Get()->GetSystem();
//
//	/*FMOD_RESULT result = */pFmod->playSound(m_pSound, nullptr, false, &m_pChannel2D);
//
//}
