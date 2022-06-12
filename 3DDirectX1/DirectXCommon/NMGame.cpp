#include "NMGame.h"

void NMGame::Initialize()
{
	Framework::Initialize();

	//�Q�[���V�[���̏�����
	gameScene = new GameScene();
	gameScene->Initialize(dxcommon, audio);

}

void NMGame::Update()
{
	Framework::Update();
	//�Q�[���V�[���̖��t���[������
	gameScene->Update();
}

void NMGame::Draw()
{
	//�`��
	postEffect->PreDrawScene(dxcommon->GetCmdList());

	gameScene->Draw();
	postEffect->PostDrawScene(dxcommon->GetCmdList());

	dxcommon->preDraw();
	gameScene->DrawBG();
	postEffect->Draw(dxcommon->GetCmdList());
	gameScene->DrawFront();
	//gameScene->Draw();
	dxcommon->postDraw();
}

void NMGame::Finalize()
{
	// �e����
	Framework::Finalize();
	safe_delete(gameScene);
}
