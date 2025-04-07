#pragma once

class Pong final : public GameScene
{
public:
	Pong() : GameScene(L"PongGame") {}
	~Pong() override = default;
	Pong(const Pong& other) = delete;
	Pong(Pong&& other) noexcept = delete;
	Pong& operator=(const Pong& other) = delete;
	Pong& operator=(Pong&& other) noexcept = delete;

protected:
	void Initialize() override;
	void Update() override;

private:

	PxPhysics& m_Physx{ PxGetPhysics() };

	bool InitializePeddles();
	GameObject* m_pLeftPeddle{ nullptr };
	GameObject* m_pRightPeddle{ nullptr };

	XMFLOAT3 m_LeftPos{};
	XMFLOAT3 m_RightPos{};

	RigidBodyComponent* m_pLeftTrigger{ nullptr };
	RigidBodyComponent* m_pRightTrigger{ nullptr };



	bool InitializeBall();
	GameObject* m_pBall{ nullptr };

	XMFLOAT3 m_BallSpeed{};

};