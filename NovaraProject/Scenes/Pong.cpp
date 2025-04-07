#include "EnginePCH.h"
#include "Pong.h"
#include "../Prefabs/CubePrefab.h"
//#include "../Prefabs/SpherePrefab.h"

void Pong::Initialize()
{
	unique_ptr<FixedCamera> pFixedCamera = make_unique<FixedCamera>();
	auto pTempCamera = pFixedCamera.get();
	AddChild(std::move(pFixedCamera));

	XMVECTOR cameraPosition{ 0.0f, 35.0f, 0.0f };
	pTempCamera->GetTransform().Translate(cameraPosition);
	XMFLOAT3 cameraAngle{ 90.0f, 0.0f, 0.0f };
	pTempCamera->GetTransform().Rotate(cameraAngle, true);

	SetActiveCamera(pTempCamera->GetComponent<CameraComponent>());

	m_SceneContext.settings.drawPhysXDebug = true;
	m_SceneContext.settings.clearColor = XMFLOAT4{ 0.0f, 0.2f, 0.5f, 1.0f };


	InitializePeddles();
	InitializeBall();
}

void Pong::Update()
{

}

bool Pong::InitializePeddles()
{
	auto pBouncyMaterial = m_Physx.createMaterial(1.0f, 1.0f, 1.0f);

	XMFLOAT3 dimensions{ 1.0f, 1.0f, 4.0f };
	float distance{ 18.0f };

	//LEFT
	{
		unique_ptr<GameObject> pLeftPeddle = make_unique<CubePrefab>(dimensions, XMFLOAT4{ Colors::BlanchedAlmond });
		m_pLeftPeddle = pLeftPeddle.get();
		AddChild(std::move(pLeftPeddle));

		m_LeftPos = XMFLOAT3{ -distance, 0.0f, 0.0f };
		m_pLeftPeddle->GetTransform().Translate(m_LeftPos);


		unique_ptr<RigidBodyComponent> pRBC_Left = make_unique<RigidBodyComponent>(false);
		m_pLeftTrigger = pRBC_Left.get();
		m_pLeftPeddle->AddComponent(std::move(pRBC_Left));

		m_pLeftTrigger->AddCollider(PxBoxGeometry{ dimensions.x / 2, dimensions.y / 2, dimensions.z / 2 }, *pBouncyMaterial, true);
		m_pLeftTrigger->SetConstraint(RigidBodyConstraint::TransY, false);
		m_pLeftTrigger->SetConstraint(RigidBodyConstraint::AllRot, false);


		m_pLeftPeddle->SetOnTriggerCallBack([=](GameObject* m_pLeftTrigger, GameObject* m_pBall, PxTriggerAction action)
			{
				if (action == PxTriggerAction::ENTER && m_pLeftTrigger && m_pBall)
				{
					m_BallSpeed.x *= -1;
					//PlaySounds();


				}
			});
	}

	//Right
	{
		unique_ptr<GameObject> pRightPeddle = make_unique<CubePrefab>(dimensions, XMFLOAT4{ Colors::BlanchedAlmond });
		m_pRightPeddle = pRightPeddle.get();
		AddChild(std::move(pRightPeddle));

		m_RightPos = XMFLOAT3{ distance, 0, 0 };
		m_pRightPeddle->GetTransform().Translate(m_RightPos);

		unique_ptr<RigidBodyComponent> pRBC_Right = make_unique<RigidBodyComponent>(false);
		m_pRightTrigger = pRBC_Right.get();
		m_pRightPeddle->AddComponent(std::move(pRBC_Right));

		m_pRightTrigger->AddCollider(PxBoxGeometry{ dimensions.x / 2, dimensions.y / 2, dimensions.z / 2 }, *pBouncyMaterial, true);
		m_pRightTrigger->SetConstraint(RigidBodyConstraint::TransY, false);
		m_pRightTrigger->SetConstraint(RigidBodyConstraint::AllRot, false);

		m_pRightPeddle->SetOnTriggerCallBack([=](GameObject* m_pRightTrigger, GameObject* m_pBall, PxTriggerAction action)
			{
				if (action == PxTriggerAction::ENTER && m_pRightTrigger && m_pBall)
				{
					m_BallSpeed.x *= -1;
					//PlaySounds();

				}
			});

	}



	return true;
}

bool Pong::InitializeBall()
{
	auto pBouncyMaterial = m_Physx.createMaterial(1.0f, 1.0f, 1.0f);
	float radius = 0.75f;


	{
		//unique_ptr<CubePrefab> pSphere = make_unique<CubePrefab>();
		//m_pBall = pSphere.get();
		//AddChild(std::move(pSphere));
		//m_pBall->GetTransform().Translate(0.0f, 1.0f, 0.0f);

		//unique_ptr<RigidBodyComponent> pRigidBodyComponent = make_unique<RigidBodyComponent>(false);
		//pRigidBodyComponent->AddCollider(PxSphereGeometry{ radius }, *pBouncyMaterial);
		//pRigidBodyComponent->SetConstraint(RigidBodyConstraint::TransY, false);
		//pRigidBodyComponent->SetConstraint(RigidBodyConstraint::AllRot, false);

		//m_pBall->AddComponent(std::move(pRigidBodyComponent));
	}

	return true;
}
