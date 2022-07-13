#pragma once
#include <Windows.h>
#include <wrl.h>
#include <d3d12.h>
#include <DirectXMath.h>
#include <d3dx12.h>
#include <string>

#include "Camera.h"
class Draw2D
{
private: // �G�C���A�X
// Microsoft::WRL::���ȗ�
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::���ȗ�
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;

public: // �T�u�N���X
	// ���_�f�[�^�\����
	struct VertexPosUv
	{
		XMFLOAT3 pos; // xyz���W
		XMFLOAT2 uv;  // uv���W
	};

	// �萔�o�b�t�@�p�f�[�^�\����
	struct ConstBufferData
	{
		XMFLOAT4 color;	// �F (RGBA)
		XMMATRIX mat;	// �R�c�ϊ��s��
	};

public: // �ÓI�����o�֐�

	static bool StaticInitialize(ID3D12Device* dev ,int window_width, int window_height);

	static void PreDraw(ID3D12GraphicsCommandList* cmdList);

	/// <summary>
	/// �`��㏈��
	/// </summary>
	static void PostDraw();

	/// <summary>
	/// 3D�I�u�W�F�N�g����
	/// </summary>
	/// <returns></returns>
	static Draw2D* Create();

private: // �ÓI�����o�ϐ�

	//�ÓI�����o�ϐ�
	//�e�N�X�`���̍ő喇��
	static const int spriteSRVCount = 512; //�e�N�X�`���̍ő喇��
	//���_��
	static const int vertNum = 4;
	//�f�o�C�X
	static ID3D12Device* dev;
	//�f�X�N���v�^�T�C�Y
	static UINT descriptorHandleIncrementSize;
	//�R�}���h���X�g
	static ID3D12GraphicsCommandList* cmdList;
	//���[�g�V�O�l�`��
	static ComPtr<ID3D12RootSignature> rootSignature;
	//�p�C�v���C���X�e�[�g�I�u�W�F�N�g
	static ComPtr<ID3D12PipelineState> pipelineState;
	//�f�X�N���v�^�q�[�v
	static ComPtr<ID3D12DescriptorHeap> descHeap;
	//�e�N�X�`���o�b�t�@
	static ComPtr<ID3D12Resource> texBuff[spriteSRVCount];
	//�ˉe�s��
	static XMMATRIX matProjection;

	//�����o�ϐ�
	//���_�o�b�t�@
	ComPtr<ID3D12Resource> vertBuff;
	//�萔�o�b�t�@
	ComPtr<ID3D12Resource> constBuff;
	//���_�o�b�t�@�r���[
	D3D12_VERTEX_BUFFER_VIEW vbView{};
	//�e�N�X�`���ԍ�
	UINT texNumber = 0;
	//Z���̉�]�p
	float rotation = 0.0f;
	//���[�J�����W
	XMFLOAT2 position = {};
	XMFLOAT2 position2 = {};
	//�X�v���C�g���A����
	XMFLOAT2 size = { 100.0f,100.0f };
	//���[���h�ϊ��s��
	XMMATRIX matWorld{};
	//�F
	XMFLOAT4 color = { 1,1,1,1 };

private:// �ÓI�����o�֐�
	
	void GraphicsPipline();
	

public: // �����o�֐�
	bool Initialize();

	void CreateModel(XMFLOAT2 startPos, XMFLOAT2 endPos);

	void Update();


	void Draw();

	float GetAngle(XMFLOAT2 startPos, XMFLOAT2 endPos);
	const XMFLOAT2& GetPosition() { return position; }

	void SetPosition(XMFLOAT2 position) { this->position = position; }

};

