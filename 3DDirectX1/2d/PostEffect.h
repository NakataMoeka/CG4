#pragma once
#include "Sprite.h"
#include <DirectXMath.h>
class PostEffect : public Sprite
{
	// Microsoft::WRL::���ȗ�
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::���ȗ�
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;
public:


	PostEffect();


	void Initialize();

	void CreateGraphicsPipeline();


	void PreDrawScene(ID3D12GraphicsCommandList* cmdList);


	void PostDrawScene(ID3D12GraphicsCommandList* cmdList);

	void Draw(ID3D12GraphicsCommandList* cmdList);

	//�e�N�X�`���o�b�t�@
	ComPtr<ID3D12Resource> texBuff;
	//SRV�p�f�X�N���v�^�q�[�v
	ComPtr<ID3D12DescriptorHeap> descHeapSRV;
	//�[�x�o�b�t�@
	ComPtr<ID3D12Resource> depthBuff;
	//RTV�p�f�X�N���v�^�q�[�v
	ComPtr<ID3D12DescriptorHeap> descHeapRTV;
	//DSV�p�f�X�N���v�^�q�[�v
	ComPtr<ID3D12DescriptorHeap> descHeapDSV;

	//���[�g�V�O�l�`��
	ComPtr<ID3D12RootSignature> rootSignature;
	//�p�C�v���C���X�e�[�g�I�u�W�F�N�g
	ComPtr<ID3D12PipelineState> pipelineState;

	//��ʃN���A�J���[
	static const float clearColor[4];

};
