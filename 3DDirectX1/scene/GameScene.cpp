#include "GameScene.h"
#include <cassert>
//#include "FbxLoader.h"
#include<time.h>
GameScene::GameScene()
{
}

GameScene::~GameScene()
{
	safe_delete(object3d);
	safe_delete(object3d2);
	safe_delete(model);
	safe_delete(model2);
	safe_delete(sprite);
	safe_delete(particleMan);
}

void GameScene::Initialize(DirectXCommon* dxCommon, Input* input, Audio* audio)
{
	//u
	assert(dxCommon);
	assert(input);
	assert(audio);

	this->dxCommon = dxCommon;
	this->input = input;
	this->audio = audio;

	// �J��������
	camera = new DebugCamera(WinApp::window_width, WinApp::window_height, input);

	// 3D�I�u�W�F�N�g�ɃJ�������Z�b�g
	Object3d::SetCamera(camera);
	// �p�[�e�B�N���}�l�[�W������
	particleMan = ParticleManager::Create(dxCommon->Getdev(), camera);

	model = model->Create("bullet");
	model2 = model2->Create("bullet");
	object3d = Object3d::Create(model);
	object3d2 = Object3d::Create(model2);
	

	object3d->Update();
	object3d2->Update();
	//���f�������w�肵�ēǂݍ���
	//FbxLoader::GetInstance()->LoadModelFromFile("cube");
	//����������




	// �f�o�b�O�e�L�X�g�p�e�N�X�`���ǂݍ���
	if (!Sprite::LoadTexture(debugTextTexNumber, L"Resources/debugfont.png")) {
		assert(0);
		return;
	}
	// �f�o�b�O�e�L�X�g������
	debugText.Initialize(debugTextTexNumber);
	
	Sprite::LoadTexture(1, L"Resources/Circle.png");
	Sprite::LoadTexture(2, L"Resources/white1x1.png");

	sprite = Sprite::CreateSprite(1, playerPos22d);
	sprite2 = Sprite::CreateSprite(2,playerPos2d);
	sprite->SetSize({ 100, 100 });
	sprite2->SetSize(playerSize2d);

	//audio->SoundPlayWave("Resources/�V���b�g.wav",true);
	// �J���������_���Z�b�g
	camera->SetTarget({ 0, 1, 0 });
	camera->SetEye({ 0, 0, -50 });
	//camera->SetDistance(20.0f);
			//v2.x = v * cos(60 * PI / 180.0);
			//v2.y = v * sin(60 * PI / 180.0);
		
	//vu = v;
	//vBu = vB;
	//srand(time(NULL));
}

void GameScene::Update()
{

#pragma region MT4_�ۑ�1�R�����g�A�E�g	

	//if (input->TriggerKey(DIK_SPACE)) {

	//	Mflag = true;
	//}
	//

	//if (Mflag == true) {
	//	playerPosition2.y = playerPosition2.y + v;
	//	v = -g + v;
	//	g = k*v / m;
	/*	if (playerPosition2.y >= 1000) {
			playerPosition2.y = 30;
			v = 0.0f;
			g = 9.8f / 60.0f;
			fx1 = 1.0f;
			m = 5.0f;
			Mflag = false;
		}*/
	//}
#pragma endregion

#pragma region MT4_�ۑ�2_1
	//if (input->TriggerKey(DIK_SPACE)) {

	//	Mflag = true;
	//}
	//if (Mflag == true) {
	//	if (v <= 0) {
	//		v = 0;
	//	}
	//	playerPosition2.x = playerPosition2.x + v;
	//
	//		v = v - a;

	//	fx = 100 * cos(60 * PI / 180.0);
	//	fy = 100 * sin(60 * PI / 180.0);

	//	N = m * g - fy;
	//	fx = fx - (uk * N);
	//
	//	a = fx / m;
	//	a = a / 300;

	//}
#pragma endregion
	
#pragma region MT4_�ۑ�2_2

	//if (input->TriggerKey(DIK_SPACE)) {

	//	Mflag = true;
	//}
	//
	//	if (Mflag == true) {
	//		
	//		if (playerPosition2.y<= 500) {
	//			playerPosition2.x += v2.x;
	//			playerPosition2.y -= v2.y;


	//			v2.y = -g + v2.y;
	//			g = k * v / m;

	//		}
	//	}
	//
	//sprite->SetPosition(playerPosition2);
#pragma endregion
#pragma region MT4_�ۑ�3

	/*sphereA.center = XMVectorSet(playerPosition.x, playerPosition.y, playerPosition.z, 1);
	sphereB.center = XMVectorSet(playerPositionB.x, playerPositionB.y, playerPositionB.z, 1);
	sphereA.radius = 2.0f;
	sphereB.radius = 2.0f;

	if (input->TriggerKey(DIK_SPACE)) {

		Mflag = true;
	}
	
	if (Mflag == true) {

		playerPosition.x += v;
		playerPositionB.x -= vB;
	}
	if (Collision::CheckSphere2Sphere(sphereA, sphereB)) {
		debugText.Printf(0, 500, 3.0f, "Hit");

		v = (vBu * m2 - vu * m) / m;
		vB = (v * m - vBu * m2) / m2;
		v *= e;
		vB *= e;
	}*/


#pragma endregion
#pragma region MT4_�ۑ�4



//if (input->TriggerKey(DIK_SPACE)) {
//
//	Mflag = true;
//}
//
//if (Mflag == true) 
//{
//	Length += 0.5f;
//	if (Length >= 50)
//	{
//		Length = 50;
//	}
//		radius = angle * 3.14f / 180.0f;
//		add_x = cos(radius) * Length;
//		add_y = sin(radius) * Length;
//		playerPosition.x = playerPositionB.x + add_x;
//		playerPosition.y = playerPositionB.y + add_y;
//		angle += va;
//}
//if (input->TriggerKey(DIK_R)) {
//	Mflag = false;
//	Length = 0;
//	playerPosition = { 0.0f,0.0f,0.0f };
//}

#pragma endregion
#pragma region MT4_�ۑ�5
//if (input->TriggerKey(DIK_SPACE)) {
//
//	Mflag = true;
//}
//playerEndPos2d2 = { playerPos2d2.x+cosf(XMConvertToRadians(angle))*100,playerPos2d2.y + sinf(XMConvertToRadians(angle))*100 };
//
//circle.center = { playerPos2d.x + 100, playerPos2d.y + 100, 0 };
//circle.radius = 100;
//line.center = { playerPos2d2.x + 100, playerPos2d2.y + 0.5f, 0 };
//line.scale= { 1,150,1 };
//
////if (Mflag == true) {
//	
//	//if (playerPos2d2.x >= 0 && playerPos2d2.x < 1280) {
//		if (input->PushKey(DIK_D)) {
//			playerPos2d2.x += 1;
//		}
//		if (input->PushKey(DIK_A)) {
//			playerPos2d2.x -= 1;
//		}
//	//}
//	//if (playerPos2d2.y >= 0 && playerPos2d2.y <720) {
//		if (input->PushKey(DIK_W)) {
//			playerPos2d2.y -= 1;
//		}
//		if (input->PushKey(DIK_S)) {
//			playerPos2d2.y += 1;
//		}
//	//}
//	if (input->PushKey(DIK_Q)) {
//		angle -=1 ;
//	}
//	if (input->PushKey(DIK_E)) {
//		angle += 1;
//	}
//	if (Collision::CheckSphere2Box(circle, line))
//	{
//		sprite->SetColor({ 1,0,0,1 });
//	}
//	else
//	{
//		sprite->SetColor({ 1,1,1,1 });
//	}
//	
//		
//	
//
//
//		
//		
	
//}

//sprite->SetPosition(playerPos2d);
//sprite2->SetPosition(playerPos2d2);
//sprite2->SetRotation(angle);
#pragma endregion
#pragma region MT4_�ۑ�6

	//if (input->TriggerKey(DIK_1)) {
	//	playerPos2d = { 300,300 };
	//	playerSize2d = { 100, 100 };
	//	easeTimer = 0;
	//	EaseFlag = 1;
	//}
	//if (input->TriggerKey(DIK_2)) {
	//	playerPos2d = { 300,300 };
	//	playerSize2d = { 100, 100 };
	//	easeTimer = 0;
	//	EaseFlag = 2;
	//}
	//if (input->TriggerKey(DIK_3)) {
	//	playerPos2d = { 300,300 };
	//	playerSize2d = { 100, 100 };
	//	easeTimer = 0;
	//	EaseFlag = 3;
	//}
	//if (input->TriggerKey(DIK_4)) {
	//	playerPos2d = { 300,300 };
	//	playerSize2d = { 100, 100 };
	//	easeTimer = 0;
	//	EaseFlag = 4;
	//}
	//if (EaseFlag== 1) {
	//	if (easeTimer < 0.2) {
	//		easeTimer += 0.1 / 60;
	//	}
	//	playerPos2d = Eas::easeInQuad(playerPos2d, playerEndPos2d, easeTimer,0.2);
	//}
	//if (EaseFlag == 2) {
	//	if (easeTimer < 0.2) {
	//		easeTimer += 0.1 / 60;
	//	}
	//	playerPos2d = Eas::easeOutQuad(playerPos2d, playerEndPos2d, easeTimer,0.2);
	//}
	//if (EaseFlag == 3) {
	//	if (easeTimer < 0.2) {
	//		easeTimer += 0.1 / 60;
	//	}
	//	playerPos2d = Eas::easeInCubic(playerPos2d, playerEndPos2d, easeTimer,0.2);
	//}
	//if (EaseFlag == 4) {
	//	if (easeTimer < 0.2) {
	//		easeTimer += 0.1 / 60;
	//	}
	//	playerPos2d = Eas::easeOutCubic(playerPos2d, playerEndPos2d, easeTimer,0.2);
	//}
	//if (input->TriggerKey(DIK_R)) {
	//	playerPos2d = { 300,300 };
	//	playerSize2d = { 100, 100 };
	//	easeTimer = 0;
	//	EaseFlag = 0;
	//}
#pragma endregion
#pragma region MT4_�ۑ�8
////
//circle.center = { playerPos22d.x+10, playerPos22d.y+10, 0 };
//circle.radius = 100;
//ray.start = { input->GetMousePos().x,input->GetMousePos().y,0 };
//ray.dir = { 1,0,0,0 };
//x = playerPos2d.x;
////sprite->SetParent(sprite);
//if (input->PushMouse(0)) {
//
//	if (Collision::CheackRay2Sphere(ray, circle)) {
//		playerPos22d = { input->GetMousePos().x+1,input->GetMousePos().y };
//		playerPos2d = { input->GetMousePos().x,0 };
//
//	}
//	playerSize2d.y = playerPos22d.y;
//}
//else if(!input->PushMouse(0)&&playerPos22d.y>100) {
//
//	dist = playerPos22d.y - 100;
//	a = dist * k / m;
//	v += a;
//	v -= v * kv;
//	playerPos22d.y += v;
//	playerSize2d.y = playerPos22d.y;
//}

#pragma endregion
#pragma region MT4_�ۑ�9
if (input->TriggerKey(DIK_SPACE)) {
	Mflag = true;
	//x = 45;
}
if (Mflag == true) {
	
	angle += -m * gacc* sin(x / 450);
	x += angle;

	float an = x/450 + 3.1415926535897932384626433832795f / 2;

	// �O�p�֐����g�p���A�~�̈ʒu������o���B
	float add_x = cos(an) * 450;
	float add_y = sin(an) * 450;

	// ���ʂłł��ʒu�𒆐S�ʒu�ɉ��Z���A�����`��ʒu�Ƃ���
	playerPos22d.x =450 + add_x;
	playerPos22d.y = 0 + add_y;

	// ������ς���
	//angle2 += 10.0f;

}

#pragma endregion
	// �p�[�e�B�N������
	//CreateParticles();
	camera->Update();
	particleMan->Update();
	sprite2->SetSize(playerSize2d);
	sprite->SetPosition(playerPos22d);
	sprite2->SetPosition(playerPos22d);

	sprite->SetAnchorPoint({ 0.5,0.5 });
	//sprite2->SetAnchorPoint({ 1,1 });
	sprite2->SetRotation(angle);
	//sprite->SetRotation(angle);
	object3d->SetPosition(playerPosition);
	//object3d2->SetPosition(playerPositionB);
	object3d2->SetScale({ 2.0f,2.0f,2.0f });
	object3d->Update();
	object3d2->Update();
	
}

void GameScene::Draw()
{	// �[�x�o�b�t�@�N���A
	dxCommon->ClearDepthBuffer();
	Object3d::PreDraw(dxCommon->GetCmdList());
	//object3d->Draw();
	//object3d2->Draw();
	Object3d::PostDraw();


	Sprite::PreDraw(dxCommon->GetCmdList());
	sprite->Draw();
	sprite2->Draw();
	//char str[256];

//	debugText.Printf(0, 80, 3.0f, "%f",playerPos2d.x);
	debugText.Printf(0, 140, 3.0f, "%f,%f", playerPos22d.x, playerPos22d.y);

	//debugText.Printf(0, 80, 3.0f, "SPACE:free fall");

	debugText.DrawAll(dxCommon->GetCmdList( ));
	Sprite::PostDraw();
}
void GameScene::CreateParticles()
{
	for (int i = 0; i < 10; i++) {
		// X,Y,Z�S��[-5.0f,+5.0f]�Ń����_���ɕ��z
		const float rnd_pos = 10.0f;
		XMFLOAT3 pos{};
		pos.x = (float)rand() / RAND_MAX * rnd_pos - rnd_pos / 2.0f;
		pos.y = (float)rand() / RAND_MAX * rnd_pos - rnd_pos / 2.0f;
		pos.z = (float)rand() / RAND_MAX * rnd_pos - rnd_pos / 2.0f;

		const float rnd_vel = 0.1f;
		XMFLOAT3 vel{};
		vel.x = (float)rand() / RAND_MAX * rnd_vel - rnd_vel / 2.0f;
		vel.y = (float)rand() / RAND_MAX * rnd_vel - rnd_vel / 2.0f;
		vel.z = (float)rand() / RAND_MAX * rnd_vel - rnd_vel / 2.0f;

		XMFLOAT3 acc{};
		const float rnd_acc = 0.001f;
		acc.y = -(float)rand() / RAND_MAX * rnd_acc;

		// �ǉ�
		particleMan->Add(60, pos, vel, acc, 1.0f, 0.0f);
	}
}

