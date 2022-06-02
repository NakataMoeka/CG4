#pragma once
#include "Sprite.h"
class PostEffect :public Sprite
{
private:

	template<class T>using ComPtr = Microsoft::WRL::ComPtr<T>;

public:
	static const float clearColor[4];
	PostEffect();

	void Initialize();

	void Draw(ID3D12GraphicsCommandList* cmdList);

	void PreDrawScene(ID3D12GraphicsCommandList* cmdList);

	void PostDrawScene(ID3D12GraphicsCommandList* cmdList);

private:
	//�e�N�X�`���o�b�t�@
	ComPtr<ID3D12Resource> texBuff;
	//�f�X�N���v�^�q�[�v
	ComPtr<ID3D12DescriptorHeap> descHeapSRV;
	// �[�x�o�b�t�@
	ComPtr<ID3D12Resource> depthBuff;
	// RTV�p�f�X�N���v�^�q�[�v
	ComPtr<ID3D12DescriptorHeap> descHeapRTV;
	// DSV�p�f�X�N���v�^�q�[�v
	ComPtr<ID3D12DescriptorHeap> descHeapDSV;

};

