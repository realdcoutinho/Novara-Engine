#include "EnginePCH.h"
#include "FixedCamera.h"

void FixedCamera::Initialize(const SceneContext&)
{
	AddComponent(new CameraComponent());
}