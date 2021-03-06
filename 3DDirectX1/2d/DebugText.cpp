#include "DebugText.h"


//DebugText::~DebugText()
//{
//	for (int i = 0; i < _countof(sprite); i++) {
//		delete sprite[i];
//	}
//}


DebugText* DebugText::GetInstance()
{
	static DebugText instance;

	return &instance;
}

void DebugText::Initialize(UINT texnumber)
{
	// 全てのスプライトデータについて
	for (int i = 0; i < _countof(sprite); i++)
	{
		// スプライトを生成する
		sprite[i] = Sprite::CreateSprite(texnumber, { 0,0 });
	}
}

void DebugText::Print(int len, const std::string& text, float x, float y, float scale = 1.0f)
{
	// 全ての文字について
	for (int i = 0; i < len; i++)
	{
		// 最大文字数超過
		if (spriteIndex >= maxCharCount) {
			break;
		}

		// 1文字取り出す(※ASCIIコードでしか成り立たない)
		const unsigned char& character = text[i];

		// ASCIIコードの2段分飛ばした番号を計算
		int fontIndex = character - 32;
		if (character >= 0x7f) {
			fontIndex = 0;
		}

		int fontIndexY = fontIndex / fontLineCount;
		int fontIndexX = fontIndex % fontLineCount;

		// 座標計算
		sprite[spriteIndex]->SetPosition({ x + fontWidth * scale * i, y });
		sprite[spriteIndex]->SetTextureRect({ (float)fontIndexX * fontWidth, (float)fontIndexY * fontHeight }

		, { (float)fontWidth ,(float)fontHeight });
		sprite[spriteIndex]->SetSize({ fontWidth * scale, fontHeight * scale });
		// 文字を１つ進める
		spriteIndex++;
	}
}


void DebugText::Printf(float x, float y, float scale, const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	int w = vsnprintf(buffer, bufferSize - 1, fmt, args);
	Print(w, buffer, x, y, scale);
	va_end(args);
}

// まとめて描画
void DebugText::DrawAll(ID3D12GraphicsCommandList* cmdList)
{
	// 全ての文字のスプライトについて
	for (int i = 0; i < spriteIndex; i++)
	{
		// スプライト描画
		sprite[i]->Draw();
	}

	spriteIndex = 0;
}




