#pragma once

#include <d3dx11effect.h>

#include "ContentManager.h"

class EffectLoader : public ContentLoader<ID3DX11Effect>
{
public:
	EffectLoader(const EffectLoader& other) = delete;
	EffectLoader(EffectLoader&& other) noexcept = delete;
	EffectLoader& operator=(const EffectLoader& other) = delete;
	EffectLoader& operator=(EffectLoader&& other) noexcept = delete;
	EffectLoader() = default;
	~EffectLoader() override = default;

protected:
	ID3DX11Effect* LoadContent(const ContentLoadInfo& loadInfo) override;
	void Destroy(ID3DX11Effect* objToDestroy) override;
};