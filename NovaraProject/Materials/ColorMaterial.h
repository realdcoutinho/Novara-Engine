#pragma once
#include "BaseMaterial.h"
#include "Material.h"

class ColorMaterial final: public Material<ColorMaterial>
{
public:
    ColorMaterial();
    ~ColorMaterial() override = default;

    ColorMaterial(const ColorMaterial& other) = delete;
    ColorMaterial(ColorMaterial&& other) noexcept = delete;
    ColorMaterial& operator=(const ColorMaterial& other) = delete;
    ColorMaterial& operator=(ColorMaterial&& other) noexcept = delete;

    void UseTransparency(bool enabled);
    void SetColor(const XMFLOAT4& color) const;

protected:
    void InitializeEffectVariables() override;
};