#include "FBX.hlsli"

VSOutput main(VSInput input)
{
	// �@���Ƀ��[���h�s��ɂ��X�P�[�����O�E��]��K�p
	float4 wnormal = normalize(mul(world, float4(input.normal, 0)));
	VSOutput output; // �s�N�Z���V�F�[�_�[�ɓn���l
	output.svpos = mul(mul(viewproj, world), input.pos);// �s��ɂ����W�ϊ�
	output.normal = wnormal.xyz;// ���[���h�@�������̃X�e�[�W�ɓn��
	output.uv = input.uv;// ���͒l�����̂܂܎��̃X�e�[�W�ɓn��
	return output;
}