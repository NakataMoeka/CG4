#include "NMGame.h"

void NMGame::Initialize()
{
	Framework::Initialize();
	//ゲームシーンの初期化
	gameScene = new GameScene();
	gameScene->Initialize(dxcommon, audio);

}

void NMGame::Update()
{
	Framework::Update();
	//何もなし
	if (Input::GetInstance()->TriggerKey(DIK_1)/*ここにGetterを書くつもり*/) {
		postEffect->CreateGraphicsPipeline(L"Resources/shaders/PostEffectTestPS.hlsl", L"Resources/shaders/PostEffectTestVS.hlsl");
	}
	//RGBシフト
	else if (Input::GetInstance()->TriggerKey(DIK_2)/*ここにGetterを書くつもり*/) {
		postEffect->CreateGraphicsPipeline(L"Resources/shaders/PostEffectColorPS.hlsl", L"Resources/shaders/PostEffectColorVS.hlsl");
	}
	//ガウシアンブラー
	else if (Input::GetInstance()->TriggerKey(DIK_3)/*ここにGetterを書くつもり*/) {
		postEffect->CreateGraphicsPipeline(L"Resources/shaders/BlurPS.hlsl", L"Resources/shaders/BlurVS.hlsl");
	}
	//モザイク
	else if (Input::GetInstance()->TriggerKey(DIK_4)/*ここにGetterを書くつもり*/) {
		postEffect->CreateGraphicsPipeline(L"Resources/shaders/mosaicPS.hlsl", L"Resources/shaders/mosaicVS.hlsl");
	}
	//ゲームシーンの毎フレーム処理
	gameScene->Update();
}

void NMGame::Draw()
{
	//描画
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
	// 各種解放
	Framework::Finalize();
	safe_delete(gameScene);
}
