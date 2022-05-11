#include"Collision.h"
using namespace DirectX;

bool Collision::CheackSphere2Plane(const Sphere& sphere, const Plane& plane, DirectX::XMVECTOR* inter)
{
	XMVECTOR distV = XMVector3Dot(sphere.center, plane.normal);
	float dist = distV.m128_f32[0] - plane.distance;
	if (fabsf(dist) > sphere.radius) return false;
	if (inter) {
		*inter = -dist * plane.normal + sphere.center;
	}
	return true;
}


	void Collision::ClosestPtPoint2Triangle(const DirectX::XMVECTOR & point, const Triangle & triangle, DirectX::XMVECTOR * closest)
	{
		// point��p0�̊O���̒��_�̈�̒��ɂ��邩�ǂ����`�F�b�N
		XMVECTOR p0_p1 = triangle.p1 - triangle.p0;
		XMVECTOR p0_p2 = triangle.p2 - triangle.p0;
		XMVECTOR p0_pt = point - triangle.p0;

		XMVECTOR d1 = XMVector3Dot(p0_p1, p0_pt);
		XMVECTOR d2 = XMVector3Dot(p0_p2, p0_pt);

		if (d1.m128_f32[0] <= 0.0f && d2.m128_f32[0] <= 0.0f)
		{
			// p0���ŋߖT
			*closest = triangle.p0;
			return;
		}

		// point��p1�̊O���̒��_�̈�̒��ɂ��邩�ǂ����`�F�b�N
		XMVECTOR p1_pt = point - triangle.p1;

		XMVECTOR d3 = XMVector3Dot(p0_p1, p1_pt);
		XMVECTOR d4 = XMVector3Dot(p0_p2, p1_pt);

		if (d3.m128_f32[0] >= 0.0f && d4.m128_f32[0] <= d3.m128_f32[0])
		{
			// p1���ŋߖT
			*closest = triangle.p1;
			return;
		}

		// point��p0_p1�̕ӗ̈�̒��ɂ��邩�ǂ����`�F�b�N���A�����point��p0_p1��ɑ΂���ˉe��Ԃ�
		float vc = d1.m128_f32[0] * d4.m128_f32[0] - d3.m128_f32[0] * d2.m128_f32[0];
		if (vc <= 0.0f && d1.m128_f32[0] >= 0.0f && d3.m128_f32[0] <= 0.0f)
		{
			float v = d1.m128_f32[0] / (d1.m128_f32[0] - d3.m128_f32[0]);
			*closest = triangle.p0 + v * p0_p1;
			return;
		}

		// point��p2�̊O���̒��_�̈�̒��ɂ��邩�ǂ����`�F�b�N
		XMVECTOR p2_pt = point - triangle.p2;

		XMVECTOR d5 = XMVector3Dot(p0_p1, p2_pt);
		XMVECTOR d6 = XMVector3Dot(p0_p2, p2_pt);
		if (d6.m128_f32[0] >= 0.0f && d5.m128_f32[0] <= d6.m128_f32[0])
		{
			*closest = triangle.p2;
			return;
		}

		// point��p0_p2�̕ӗ̈�̒��ɂ��邩�ǂ����`�F�b�N���A�����point��p0_p2��ɑ΂���ˉe��Ԃ�
		float vb = d5.m128_f32[0] * d2.m128_f32[0] - d1.m128_f32[0] * d6.m128_f32[0];
		if (vb <= 0.0f && d2.m128_f32[0] >= 0.0f && d6.m128_f32[0] <= 0.0f)
		{
			float w = d2.m128_f32[0] / (d2.m128_f32[0] - d6.m128_f32[0]);
			*closest = triangle.p0 + w * p0_p2;
			return;
		}

		// point��p1_p2�̕ӗ̈�̒��ɂ��邩�ǂ����`�F�b�N���A�����point��p1_p2��ɑ΂���ˉe��Ԃ�
		float va = d3.m128_f32[0] * d6.m128_f32[0] - d5.m128_f32[0] * d4.m128_f32[0];
		if (va <= 0.0f && (d4.m128_f32[0] - d3.m128_f32[0]) >= 0.0f && (d5.m128_f32[0] - d6.m128_f32[0]) >= 0.0f)
		{
			float w = (d4.m128_f32[0] - d3.m128_f32[0]) / ((d4.m128_f32[0] - d3.m128_f32[0]) + (d5.m128_f32[0] - d6.m128_f32[0]));
			*closest = triangle.p1 + w * (triangle.p2 - triangle.p1);
			return;
		}

		float denom = 1.0f / (va + vb + vc);
		float v = vb * denom;
		float w = vc * denom;
		*closest = triangle.p0 + p0_p1 * v + p0_p2 * w;
	}

	bool Collision::CheackSphere2Triangle(const Sphere& sphere, const Triangle& triangle, DirectX::XMVECTOR* inter)
	{
		XMVECTOR p;
		ClosestPtPoint2Triangle(sphere.center, triangle, &p);
		XMVECTOR v = p - sphere.center;
		v = XMVector3Dot(v, v);
		if (v.m128_f32[0]> sphere.radius* sphere.radius) return false;
		if (inter) {
			*inter = p;
		}
		return true;
	}

	bool Collision::CheackRay2Plane(const Ray& ray, const Plane& plane, float* distance, DirectX::XMVECTOR* inter)
	{
		const float epsilon = 1.0e-5f;//�덷�z���p�̔����Ȓl
		//�ʂƃ��C�̕����x�N�g���̓���
		float d1 = XMVector3Dot(plane.normal, ray.dir).m128_f32[0];
		//���ʂɂ͓�����Ȃ�
		if (d1 > epsilon) { return false; }
		//�n�_�ƌ��_�̋���
		//�ʖ@���ƃ��C�̎n�_���W(�ʒu�x�N�g��)�̓���
		float d2 = XMVector3Dot(plane.normal, ray.start).m128_f32[0];
		//�n�_�ƕ��ʂ̋���(���ʂ̖@���̕���)
		float dist = d2 - plane.distance;
		//�n�_�ƕ��ʂ̋���(���C����)
		float t = dist / -d1;
		//��_���n�_�����ɂ���̂ŁA������Ȃ�
		if (t < 0) return false; 
		//��������������
		if (distance) { *distance = t; }
		//��_���v�Z
		if (inter) { *inter = ray.start + t * ray.dir; }
		return true;

	}

	bool Collision::CheackRay2Triangle(const Ray& ray, const Triangle& triangle, float* distance, DirectX::XMVECTOR* inter)
	{
		//�O�p�`������Ă��镽�ʂ��Z�o
		Plane plane;
		XMVECTOR interPlane;
		plane.normal = triangle.normal;
		plane.distance = XMVector3Dot(triangle.normal, triangle.p0).m128_f32[0];
		//���C�ƕ��ʂ��������ĂȂ���Γ������Ă��Ȃ�
		if (!CheackRay2Plane(ray, plane, distance, &interPlane)) { return false; }
		//���C�ƕ��ʂ��������Ă����̂ŋ����ƌ�_���������܂ꂽ
		//���C�ƕ��ʂ̌�_���O�p�`�̓����ɂ��邩����
		const float epsilon = 1.0e-5f;//�덷�z���p�̔����Ȓl
		XMVECTOR m;
		//��p0_p1�ɂ���
		XMVECTOR pt_p0 = triangle.p0 - interPlane;
		XMVECTOR p0_p1 = triangle.p1 - triangle.p0;
		m = XMVector3Cross(pt_p0, p0_p1);
		//�ӂ̊O���ł���Γ������Ă��Ȃ��̂Ŕ����ł��؂�
		if (XMVector3Dot(m, triangle.normal).m128_f32[0] < -epsilon) { return false; }
		//��p1_p2�ɂ���
		XMVECTOR pt_p1 = triangle.p1 - interPlane;
		XMVECTOR p1_p2 = triangle.p2 - triangle.p1;
		m = XMVector3Cross(pt_p1, p1_p2);
		//�ӂ̊O���ł���Γ������Ă��Ȃ��̂Ŕ����ł��؂�
		if (XMVector3Dot(m, triangle.normal).m128_f32[1] < -epsilon) { return false; }
		//��p2_p0�ɂ���
		XMVECTOR pt_p2 = triangle.p2 - interPlane;
		XMVECTOR p2_p0 = triangle.p0 - triangle.p2;
		m = XMVector3Cross(pt_p0, p0_p1);
		//�ӂ̊O���ł���Γ������Ă��Ȃ��̂Ŕ����ł��؂�
		if (XMVector3Dot(m, triangle.normal).m128_f32[2] < -epsilon) { return false; }

		if (inter) {
			*inter = interPlane;
		}
		return true;
	}

	bool Collision::CheackRay2Sphere(const Ray& ray, const Sphere& sphere, float* distance, DirectX::XMVECTOR* inter)
	{
		XMVECTOR m = ray.start - sphere.center;
		float b = XMVector3Dot(m, ray.dir).m128_f32[0];
		float c = XMVector3Dot(m, m).m128_f32[0] - sphere.radius * sphere.radius;
		//ray��sphere�̊O���ɂ���(c>0),ray��sphere���痣��Ă��������������Ă���ꍇ(b>0)������Ȃ�
		if (c > 0.0f && b > 0.0f) { return false; }
		float discr = b * b - c;
		//���̔��ʎ��̓��C�������O��Ă��邱�ƂɈ�v
		if (discr < 0.0f) { return false; }
		//���C�Ƌ��͌������Ă���
		//��������ŏ��̒l���v�Z

		return true;
	}

	//���Ƌ��̓����蔻��
	bool Collision::CheckSphere2Sphere(const Sphere& sphereA, const Sphere& sphereB)
	{
		//�Q�̋��̒��S���W�����ԃx�N�g�������߂�
		XMVECTOR vec = sphereA.center - sphereB.center;

		//�x�N�g���̒����̂Q��i�Q�_�Ԃ̋����̂Q��j�����߂�
		float sqLength = vec.m128_f32[0] * vec.m128_f32[0] + vec.m128_f32[1] * vec.m128_f32[1] + vec.m128_f32[2] * vec.m128_f32[2];

		//2�̋��̔��a�̍��v�����߂�
		float r = sphereA.radius + sphereB.radius;

		//�Q�_�Ԃ̋����̂Q�恃���a�̍��v�̂Q��Ȃ�Q�̋��͌������Ă���
		return  sqLength < r* r;
	}

	
	