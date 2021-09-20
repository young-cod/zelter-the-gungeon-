#pragma once
#include "gameNode.h"
#include <vector>

struct tagEggNyangBullet
{
	image*	image;				//�Ѿ� �̹���
	RECT	rc;					//�Ѿ� ��Ʈ
	//float	left, top;			//�Ѿ� ��Ʈ�� ž
	float	x, y;				//�Ѿ� ������ǥ
	float	angle;				//�Ѿ� ȸ�� �ޱ�
	float	width, height;		//�Ѿ� ��, ���� (��Ʈ)
	float	radiusX;				//�Ѿ� ������(������ ��)
	float	radiusY;
	float	speed;				//�Ѿ� ���ǵ�
	int		frameCount;
	int		currentFrameX;
	int		currentFrameY;
};

#define EGGNYANGBULLETMAX 100
class eggNyangBullet : public gameNode
{
	vector<tagEggNyangBullet>	_vBullet;

	int icePillar1, icePillar2;

public :
	virtual HRESULT init();
	virtual void release(int index);
	virtual void update();
	virtual void render();

	void bulletFire(float x, float y, int bulletCount);
	void bulletMove();

	vector<tagEggNyangBullet> getEggNyangVBullet() { return _vBullet; }
};

//========================================

#define MAXLAZESIZE 40
class eggNyangLazer : public gameNode
{
	vector<tagEggNyangBullet>	_vLazer;

	int _lazerTime;				//������ �غ� �ð�, ������ �߻� �ð� ī��Ʈ��
	bool _lazerFire;			//������ �߻� �ƴ���

public :
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void lazerReady(float x, float y, int direction);
	void lazerFire();
	void lazerMove();

	vector<tagEggNyangBullet> getEggNyangVLazer() { return _vLazer; }
};

//==========================================

#define MAXSOWRD 5
class eggNyangSword : public gameNode
{
	vector<tagEggNyangBullet>	_vSword;

public :
	virtual HRESULT init();
	virtual void release(int index);
	virtual void update();
	virtual void render();

	void setSword(float targetX, float targetY);
	void moveSword(float targetX, float targetY, bool fire);

	vector<tagEggNyangBullet> getEggNyangVSword() { return _vSword; }
};
