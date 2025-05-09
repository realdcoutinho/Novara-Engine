#include "EnginePCH.h"
#include "FixedCamera.h"
#include "CameraComponent.h"

void FixedCamera::Initialize(const SceneContext&)
{
	AddComponent(std::move(make_unique<CameraComponent>()));
}