#pragma once
#include "BaseComponent.h"
#include <wrl/client.h>
using Microsoft::WRL::ComPtr;

struct TrianglePosNormCol;
struct QuadPosNormCol;
struct VertexPosNormCol;
struct VertexPosCol;
struct SceneContext;
//struct ID3DX11EffectMatrixVariable;
//struct ID3DX11Effect;
//struct ID3DX11EffectTechnique;
//struct ID3D11InputLayout;

class MeshDrawComponent : public BaseComponent
{
public:
	MeshDrawComponent(UINT triangleCapacity = 50, bool enableTransparency = false);
	~MeshDrawComponent() override;

	MeshDrawComponent(const MeshDrawComponent& other) = delete;
	MeshDrawComponent(MeshDrawComponent&& other) noexcept = delete;
	MeshDrawComponent& operator=(const MeshDrawComponent& other) = delete;
	MeshDrawComponent& operator=(MeshDrawComponent&& other) noexcept = delete;

	void AddTriangle(TrianglePosNormCol triangle, bool updateBuffer = false);
	void AddTriangle(VertexPosNormCol vertex1, VertexPosNormCol vertex2, VertexPosNormCol vertex3, bool updateBuffer = false);
	void AddQuad(VertexPosNormCol vertex1, VertexPosNormCol vertex2, VertexPosNormCol vertex3, VertexPosNormCol vertex4, bool updateBuffer = false);
	void AddQuad(QuadPosNormCol quad, bool updateBuffer = false);
	void RemoveTriangles();

	void UpdateBuffer() const;

	unsigned int GetTriangleCapacity() const { return m_TriangleCapacity; }
	void SetTriangleCapacity(unsigned int capacity) { m_TriangleCapacity = capacity; }

protected:

	void Draw(const SceneContext& sceneContext) override;
	void Initialize(const SceneContext& sceneContext) override;

private:

	static ComPtr<ID3DX11EffectMatrixVariable> m_pWorldVar;
	static ComPtr<ID3DX11EffectMatrixVariable> m_pWvpVar;

	std::vector<TrianglePosNormCol> m_vecTriangles;
	ComPtr<ID3D11Buffer> m_pVertexBuffer;
	UINT m_TriangleCapacity;
	bool m_UseTransparency{};

	ComPtr<ID3DX11Effect> m_pEffect;
	ComPtr<ID3DX11EffectTechnique> m_pTechnique;
	ComPtr<ID3D11InputLayout> m_pInputLayout;

	void LoadEffect(const SceneContext& sceneContext);
	void InitializeBuffer(const SceneContext& sceneContext);
};