#pragma once
#include"Framework.h"
class NMGame :public Framework
{
public:
	// ������
	void Initialize() override;
	//�I��
	void Finalize() override;
	// ���t���[������
	void Update() override;
	// �`��
	void Draw() override;
private:


};

