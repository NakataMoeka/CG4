#include "player.h"
#include"input.h"
using namespace DirectX;
Player::Player()
{
}
void Player::Initialize()
{
	model = model->Create("car", false);
	playerObj = Object3d::Create(model);
	//Create�̌�ɏ����Ȃ���client.h��InternalRelease()�ŃG���[���N����//Create�̌�ɏ����Ȃ���client.h��InternalRelease()�ŃG���[���N����
	playerObj->CreateGraphicsPipeline(L"Resources/shaders/OBJPS.hlsl", L"Resources/shaders/OBJVS.hlsl");

}


void Player::Move()
{
			radWS = XMConvertToRadians(playerAngle.y+90.0f);
			XMVECTOR moveUD = { 0,0,0.1f,0 };//�㉺�����p�̈ړ��x�N�g��
			XMVECTOR moveLR = { 0.1f,0,0,0 };//���E�����̈ړ��p�x�N�g��
			XMMATRIX matRot = XMMatrixRotationY(XMConvertToRadians(playerAngle.y));//y ���𒆐S�ɉ�]����}�g���b�N�X���쐬
			moveUD = XMVector3TransformNormal(moveUD, matRot);
			moveLR = XMVector3TransformNormal(moveLR, matRot);
			if (Input::GetInstance()->PushKey(DIK_E))
			{
				playerAngle.y += 1;

			}
			else if (Input::GetInstance()->PushKey(DIK_Q))
			{
				playerAngle.y-= 1;

			}
			if (Input::GetInstance()->PushKey(DIK_W))
			{
				playerPos.x += moveUD.m128_f32[0];
				playerPos.z += moveUD.m128_f32[2];
			}
			else if (Input::GetInstance()->PushKey(DIK_S))
			{
				playerPos.x -= moveUD.m128_f32[0];
				playerPos.z -= moveUD.m128_f32[2];
			}
			else if (Input::GetInstance()->PushKey(DIK_D))
			{
				playerPos.x += moveLR.m128_f32[0];
				playerPos.z += moveLR.m128_f32[2];
			}
			else if (Input::GetInstance()->PushKey(DIK_A))
			{
				playerPos.x -= moveLR.m128_f32[0];
				playerPos.z -= moveLR.m128_f32[2];
			}



	playerObj->SetPosition(playerPos);
	playerObj->SetRotation(playerAngle);
	playerObj->Update();
}

void Player::Draw()
{
	playerObj->Draw();
}
