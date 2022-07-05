#include "player.h"
#include"input.h"
using namespace DirectX;
Player::Player()
{
}
Player::~Player()
{
}
void Player::Initialize()
{
	model = model->Create("car", false);
	playerObj = Object3d::Create(model);
	model2 = model2->Create("bullet", false);
	SphereObj = Object3d::Create(model2);
	//Create�̌�ɏ����Ȃ���client.h��InternalRelease()�ŃG���[���N����//Create�̌�ɏ����Ȃ���client.h��InternalRelease()�ŃG���[���N����
	playerObj->CreateGraphicsPipeline(L"Resources/shaders/OBJPS.hlsl", L"Resources/shaders/OBJVS.hlsl");
	SphereObj->CreateGraphicsPipeline(L"Resources/shaders/OBJPS.hlsl", L"Resources/shaders/OBJVS.hlsl");
	SphereObj->SetParent(playerObj);
}

void Player::Init()
{
}


void Player::Move()
{
	XMVECTOR moveUD = { 0,0,0.1f,0 };//�㉺�����p�̈ړ��x�N�g��
	XMVECTOR moveLR = { 0.1f,0,0,0 };//���E�����̈ړ��p�x�N�g��
	XMMATRIX matRot = XMMatrixRotationY(XMConvertToRadians(playerAngle.y));//y ���𒆐S�ɉ�]����}�g���b�N�X���쐬
	moveUD = XMVector3TransformNormal(moveUD, matRot);
	moveLR = XMVector3TransformNormal(moveLR, matRot);
	if (Input::GetInstance()->PushKey(DIK_RIGHTARROW))
	{
		playerAngle.y += 1;

	}
	else if (Input::GetInstance()->PushKey(DIK_LEFTARROW))
	{
		playerAngle.y -= 1;
	}
	if (Input::GetInstance()->PushKey(DIK_W))
	{
		playerPos.x += moveUD.m128_f32[0];
		playerPos.z += moveUD.m128_f32[2];
		sphereAngle.x += 10;
	}
	else if (Input::GetInstance()->PushKey(DIK_S))
	{
		playerPos.x -= moveUD.m128_f32[0];
		playerPos.z -= moveUD.m128_f32[2];
		sphereAngle.x -= 10;
	}
	else if (Input::GetInstance()->PushKey(DIK_D))
	{
		playerPos.x += moveLR.m128_f32[0];
		playerPos.z += moveLR.m128_f32[2];
		sphereAngle.z += 10;
	}
	else if (Input::GetInstance()->PushKey(DIK_A))
	{
		playerPos.x -= moveLR.m128_f32[0];
		playerPos.z -= moveLR.m128_f32[2];
		sphereAngle.z -= 10;
	}


	playerObj->SetPosition(playerPos);
	playerObj->SetRotation(playerAngle);
	playerObj->SetScale({ 0.3, 0.3, 0.3 });
	playerObj->Update();

}

void Player::Ball()
{

	SphereObj->SetPosition(spherePos);
	SphereObj->SetScale(sphereSize);
	SphereObj->SetRotation(sphereAngle);
	SphereObj->Update();

}

void Player::Update()
{
	Move();
	Ball();
}

void Player::Collision(GameObject* gameObject)
{
}

void Player::Draw()
{
	playerObj->Draw();
	SphereObj->Draw();
}
