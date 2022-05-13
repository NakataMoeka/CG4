#pragma once


#include"SafeDelete.h"
#include <DirectXMath.h>
#include"input.h"
#include"Sprite.h"
#include"Audio.h"
#include"DirectXCommon.h"
#include"DebugText.h"
#include"Object3d.h"
#include "ParticleManager.h"
#include"Model.h"
#include "DebugCamera.h"
#include "Collision.h"
class GameScene 
{
private: 
// Microsoft::WRL::���ȗ�
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::���ȗ�
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;
public: // �����o�֐�


	GameScene();


	~GameScene();

	void Initialize(DirectXCommon* dxCommon, Input* input, Audio* audio);


	void Update();

	void Draw();
	void CreateParticles();
private: // �����o�ϐ�
	DirectXCommon* dxCommon = nullptr;

	Input* input = nullptr;

	Audio* audio = nullptr;

	DebugText debugText;

	DebugCamera* camera = nullptr;
	ParticleManager* particleMan = nullptr;

	Sprite* sprite = nullptr;

	Object3d* object3d = nullptr;
	Model*	model = nullptr;

	Object3d* object3d2 = nullptr;
	Model* model2 = nullptr;

	const int debugTextTexNumber = 0;


	
	bool Mflag = false;

	//MT4_�ۑ�1
	//XMFLOAT3 playerPosition = { -50.0f,-30.0f,0.0f };
	XMFLOAT2 playerPosition2 = { 0.0f,500.0f };
	XMFLOAT2 v2 = { 0.0f,0.0f };

	bool tFlag = false;

	//float f = 10.0f;
	//float v = 40.0f;
	float k = 1.0f;
//	float a = 0.f;
	float g = 9.8f/60.0f;
	float fx1 = 1.0f;
	//float m = 5.0f;
	float t=0.0f;
	//Mt4_�ۑ�2
	float mg = 9.8f;

	float fk = 0.0f;
	float fs = 0.0f;
	float us = 0.8f;
	float uk = 1.5f;
	float N = 0.0f;
	float fx = 0.0f;
	float fy = 0.0f;
	float PI = 3.141592;
	//MT4�ۑ�3

	XMFLOAT3 playerPosition = { 0.0f,0.0f,0.0f };
	XMFLOAT3 playerPositionB = { 20.0f,0.0f,0.0f };

	const float minus = -1.0f;

	float f = 0.0f;
	float f2 = 0.0f;

	float v = 1.0f;
	float vB = -1.0f;
	float vu;
	float vBu ;

	float a = 0.1f;
	float a2 = 0.1f;

	float m = 0.7f;
	float m2 = 0.5f;
	Sphere sphereA;
	Sphere sphereB;




};
