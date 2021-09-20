#pragma once
#include "gameNode.h"
#include <vector>

struct tagBullet
{
	image*	img;				//�Ѿ� �̹���
	RECT	rc;					//�Ѿ� ��Ʈ
	SHAPE	rotateCollsion;		//ȸ�� �浹 üũ�� shape����
	float	x, y;				//�Ѿ� ������ǥ
	float	angle;				//�Ѿ� ȸ�� �ޱ�
	float	width, height;		//�Ѿ� ��, ���� (��Ʈ)
	float	radiusX;			//�Ѿ� ������(������ ��)
	float	radiusY;
	float	speed;				//�Ѿ� ���ǵ�
	int		frameCount;
	int		currentFrameX;
	int		currentFrameY;
	int		currentHP, maxHP;	//(icePillar) ü��
	bool	ready;				//�����Ǵ� �������� �����°�..
	bool	destroy;			//�ı��Ǿ��°�
	bool	hp0;
};

#define MAXICEPILLAR 4
#define MAXICEBULLET 40
class niflheimIcePillar : public gameNode
{
	vector<tagBullet>			_vIcePillar;	//�������
	vector<tagBullet>			_vBullet;		//��տ��� �߻�Ǵ� �Ѿ�

	int icePillar1, icePillar2;

public :
	virtual HRESULT init();
	virtual void release(int index);
	void dieRelease(int index);
	virtual void update(float niflheimX, float niflheimY);
	virtual void render();

	void seticePillar(float niflheimX, float niflheimY);
	void icePillarMove(float niflheimX, float niflheimY);

	void fireBullet1(float x, float y, int icePillar);
	void fireBullet2(float x, float y, int icePillar);
	void bulletMove();
	void releaseBullet(int index);
	void bulletRender();

	vector<tagBullet> getVIcePillar() { return _vIcePillar; }
	void setCurrentHP(int index, int hp) { _vIcePillar[index].currentHP = hp; }

	vector<tagBullet> getVbullet() { return _vBullet; }
};

#define MAXICESPEAR 2
class niflheimIceSpear : public gameNode
{
	vector <tagBullet>		_vIceSpear;

public :
	virtual HRESULT init();
	virtual void release(int index);
	virtual void update();
	virtual void render();

	void iceSpearFire(float x, float y);
	void iceSpearMove();

	vector<tagBullet> getVIceSpear() { return _vIceSpear; }
};

#define MAXICICLE 12
class niflheimIcicle : public gameNode
{
	vector<tagBullet>		_vIcicle;

	bool	_isSceond;

public:
	virtual HRESULT init();
	virtual void release(int index);
	virtual void update();
	virtual void render();

	void firstIcicleFire();
	void sceondIcicleFire();
	void icicleMove();

	vector<tagBullet> getVIcicle() { return _vIcicle; }
};