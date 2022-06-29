#include "player.h"
#include"input.h"
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
			if (Input::GetInstance()->PushKey(DIK_D))
			{
				playerAngle.y += 1;

			}
			if (Input::GetInstance()->PushKey(DIK_A))
			{
				playerAngle.y-= 1;

			}
			if (Input::GetInstance()->PushKey(DIK_W))
			{
				playerPos.z += 0.1;

			}
			if (Input::GetInstance()->PushKey(DIK_S))
			{
				playerPos.z -= 0.1;

			}

	playerObj->SetPosition(playerPos);
	playerObj->SetRotation(playerAngle);
	playerObj->Update();
}

void Player::Draw()
{
	playerObj->Draw();
}
