#pragma once
#include"Object3d.h"
#include"Model.h"
/// <summary>
/// �v���C���[�֘A�̃N���X
/// </summary>
class GameObject;
class Player
{
private:
	// Microsoft::WRL::���ȗ�
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::���ȗ�
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;
public:
	Player();
	~Player();
	void Initialize();//��񂾂��̏�����
	void Init();//�V�[���`�F���W���ɂ����鏉����
	void Update();
	void Collision(class GameObject* gameObject);
	void Draw();
	int GetPower() { return power; }
	XMFLOAT3 GetPlayerPos() { return playerPos; }
	XMFLOAT3 GetSpherePos() { return spherePos; }
	XMFLOAT3 GetPlayerAngle() { return playerAngle; }
private:
	void Move();//�ړ�
	void Ball();//�{�[���֌W
private:
	Object3d* playerObj;
	Model* model;
	Object3d* SphereObj;
	Model* model2;
	XMFLOAT3 playerPos{ 0,-0.8,0 };
	XMFLOAT3 spherePos{ 0,3,6 };
	XMFLOAT3 playerAngle{ 0,0,0 };
	XMFLOAT3 sphereAngle{ 0,0,0 };
	XMFLOAT3 sphereSize{ 1,1,1 };
	float sinRad = 0;
	float cosRad = 0;
	float radAD = 0.0f;
	float radWS = 0.0f;
	int HP = 50;
	int power = 100;

};