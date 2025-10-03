#pragma once
#include "Direct3D.h"

#include <DirectXMath.h>
#include "Camera.h"
#include "Texture.h"

using namespace DirectX;

//�R���X�^���g�o�b�t�@�[

struct CONSTANT_BUFFER
{
	XMMATRIX	matWVP;
	XMMATRIX	matW;
	XMMATRIX	matWorld; // ���[���h�s��
};

//���_���
struct VERTEX
{
	XMVECTOR position;
	XMVECTOR uv;
	XMVECTOR normal;
};

// �O���錾
class Texture; // Texture�N���X���Ă̂��ǂ����ɂ����Ă��Ȃ����Ă����錾

class Quad
{
public:
	Quad();
	virtual ~Quad();
	virtual HRESULT Initialize();
	virtual void Draw(XMMATRIX& worldMatrix);
	void Release();
protected:
	ID3D11Buffer* pVertexBuffer_;	//���_�o�b�t�@
	ID3D11Buffer* pIndexBuffer_;	//�C���f�b�N�X�o�b�t�@
	ID3D11Buffer* pConstantBuffer_;	//�R���X�^���g�o�b�t�@ / �萔�o�b�t�@
	Texture* pTexture_;
};