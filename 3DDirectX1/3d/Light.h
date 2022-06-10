#pragma once
#include <Windows.h>
#include <wrl.h>
#include <d3d12.h>
#include <DirectXMath.h>
#include <d3dx12.h>
class Light {
private: // �G�C���A�X
// Microsoft::WRL::���ȗ�
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::���ȗ�
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;
	using XMVECTOR = DirectX::XMVECTOR;

public:
	struct ConstBufferData
	{
		XMVECTOR lightv;
		XMFLOAT3  lightcolor;
	};

	static void StaticInitialize(ID3D12Device* device);

	static Light* Create();

	void Initialize();

	void TransferConstBuffer();

	void Update();

	void SetLightDir(const XMVECTOR& lightdir);

	void SetLightColor(const XMFLOAT3 lightcolor);

	void Draw(ID3D12GraphicsCommandList* cmdList, UINT rootParameterIndex);

private://�ÓI�����o�ϐ�
	static ID3D12Device* device;
private://�����o�ϐ�
	//�萔�o�b�t�@
	ComPtr<ID3D12Resource> constBuff;
	//���C�g��������(�P�ʃx�N�g��)
	XMVECTOR lightdir = { 1,0,0,0 };
	//���C�g�F
	XMFLOAT3 lightcolor{ 1,1,1 };
	//�_�[�e�B�[�t���O
	bool dirty = false;
}; 
