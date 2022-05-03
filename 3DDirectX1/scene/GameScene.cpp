#include "GameScene.h"
#include <cassert>
//#include "FbxLoader.h"
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
	model2 = model2->Create("Player");
	object3d = Object3d::Create(model);
	object3d2 = Object3d::Create(model2);
	
	object3d2->SetRotation({ 0,180,0 });
	object3d2->SetPosition({ 0,0,0 });
	object3d->Update();
	object3d2->Update();
	//���f�������w�肵�ēǂݍ���
	//FbxLoader::GetInstance()->LoadModelFromFile("cube");
	//����������

	//object3d2->Update();


	// �f�o�b�O�e�L�X�g�p�e�N�X�`���ǂݍ���
	if (!Sprite::LoadTexture(debugTextTexNumber, L"Resources/debugfont.png")) {
		assert(0);
		return;
	}
	// �f�o�b�O�e�L�X�g������
	debugText.Initialize(debugTextTexNumber);
	
	Sprite::LoadTexture(1, L"Resources/jimenParticle.png");

	sprite = Sprite::CreateSprite(1, playerPosition2);

	//audio->SoundPlayWave("Resources/�V���b�g.wav",true);
	// �J���������_���Z�b�g
	camera->SetTarget({ 0, 1, 0 });
	//camera->SetDistance(20.0f);
			v2.x = v * cos(60 * PI / 180.0);
			v2.y = v * sin(60 * PI / 180.0);
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
	if (input->TriggerKey(DIK_SPACE)) {

		Mflag = true;
	}
	
		if (Mflag == true) {
			
			if (playerPosition2.y<= 500) {
				playerPosition2.x += v2.x;
				playerPosition2.y -= v2.y;


				v2.y = -g + v2.y;
				g = k * v / m;
		
		

			}
		}
	
	sprite->SetPosition(playerPosition2);
#pragma endregion


	if (input->PushMouse(0)) {
		debugText.Printf(100, 100, 5.0f, "www");
	}
	// �p�[�e�B�N������
	//CreateParticles();
	camera->Update();
	particleMan->Update();
	object3d->SetPosition(playerPosition);
	object3d->Update();
	object3d2->Update();
	
}

void GameScene::Draw()
{
	Object3d::PreDraw(dxCommon->GetCmdList());
	object3d->Draw();
	//object3d2->Draw();
	Object3d::PostDraw();


	sprite->PreDraw(dxCommon->GetCmdList());
	sprite->Draw();
	char str[256];


	debugText.Printf(0, 140, 3.0f, "%f,%f",playerPosition2.y,v);
	debugText.Printf(0, 180, 3.0f, "%d", tFlag);
	debugText.Printf(0, 80, 3.0f, "SPACE:free fall");

	debugText.DrawAll(dxCommon->GetCmdList( ));
	sprite->PostDraw();
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

