#pragma once
#include "FixedCamera.h"

#include "CameraComponent.h"

void FixedCamera::Initialize(const SceneContext&)
{
	auto pCamera = make_unique<CameraComponent>();
	m_pCamera = pCamera.get();
	AddComponent(std::move(pCamera));
}