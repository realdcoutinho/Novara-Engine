#include "EnginePCH.h"
#include "FixedCamera.h"

void FixedCamera::Initialize(const SceneContext&)
{
	AddComponent(std::move(make_unique<CameraComponent>()));
}