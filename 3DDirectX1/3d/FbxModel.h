#pragma once
#include <string>

struct Node
{

};
//Fbx�p�̃��f���N���X
class FbxModel
{
public:
	//�t�����h�N���X
	friend class FbxLoader;
private:
	//���f����
	std::string name;
};