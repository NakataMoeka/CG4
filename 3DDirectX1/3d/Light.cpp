#include"Light.h"
#include<cassert>
using namespace DirectX;
ID3D12Device* Light::device = nullptr;

void Light::StaticInitialize(ID3D12Device* device)
{
	//�ď������`�F�b�N
	assert(!Light::device);
	//nullptr�`�F�b�N
	assert(device);
	//�ÓI�����o�ϐ��̃Z�b�g
	Light::device = device;
}

Light* Light::Create()
{
	//3D�I�u�W�F�N�g�̃C���X�^���X�𐶐�
	Light* instance = new Light();
	//������
	instance->Initialize();
	//���������C���X�^���X��Ԃ�
	return instance;
}

void Light::Initialize()
{
	HRESULT result;
	// �萔�o�b�t�@�̐���
	result = device->CreateCommittedResource(
		&CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD), 	// �A�b�v���[�h�\
		D3D12_HEAP_FLAG_NONE,
		&CD3DX12_RESOURCE_DESC::Buffer((sizeof(ConstBufferData) + 0xff) & ~0xff),
		D3D12_RESOURCE_STATE_GENERIC_READ,
		nullptr,
		IID_PPV_ARGS(&constBuff));
	if (FAILED(result)) { assert(0); }
	// �萔�o�b�t�@�փf�[�^�]��
	TransferConstBuffer();
}

void Light::TransferConstBuffer()
{
	HRESULT result;
	// �萔�o�b�t�@�փf�[�^�]��
	ConstBufferData* constMap = nullptr;
	result = constBuff->Map(0, nullptr, (void**)&constMap);
	constMap->lightv = -lightdir;
	constMap->lightcolor = lightcolor;
	constBuff->Unmap(0, nullptr);
}

void Light::Update()
{
	//�l�̍X�V���������������萔�o�b�t�@��]������
	if (dirty) {
		TransferConstBuffer();
		dirty = false;
	}
}

void Light::SetLightDir(const XMVECTOR& lightdir)
{
	this->lightdir = XMVector3Normalize(lightdir);
	dirty = true;
}

void Light::SetLightColor(const XMFLOAT3 lightcolor)
{
	this->lightcolor = lightcolor;
	dirty = true;
}

void Light::Draw(ID3D12GraphicsCommandList* cmdList, UINT rootParameterIndex)
{
	//�萔�o�b�t�@�r���[���Z�b�g
	cmdList->SetGraphicsRootConstantBufferView(rootParameterIndex,
		constBuff->GetGPUVirtualAddress());
}