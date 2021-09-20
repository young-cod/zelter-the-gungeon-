#pragma once
#include "gameNode.h"

#include "progressBar.h"
#include "eggNyangStateBase.h"
#include "eggNyangBullet.h"

#include "playerBullet.h"

class player;

struct tagEggNyang
{
	image*	img;						//�̹���
	RECT	rc;							//���� ��Ʈ (��Ʈ�ڽ�)
	float	x, y;						//x,y��ǥ
	int		currentHp, maxHp;			//ü��
	int		direction;					//���� (���� ������)
	bool	isDie;
	float	speed;						//���ǵ�
	int		inPattern;					//���� �������� ��� (�ߺ��� ���� ������ �ʵ���)
	int		outPattern;

	eggNyangBullet*		bullet;
	eggNyangLazer*		lazer;
	eggNyangSword*		sword;
	progressBar*		progressBar;
};
enum EGGNYANGPATTERN
{
	BULLET = 1,
	LAZER,
	SWORD
};
class eggNyang : public gameNode
{
	player*	_player;

	eggNyangStateBase* _eggNyangState;

	tagEggNyang _eggNyang;

	int _bulletFireCount;
	bool _isFire;

	bool _invincibility;
	float _timeCount;
	float _timeCountEnd;

	

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	void inPutHandle();

	void hitEggNyang();

	void imageAdd();
	void move();
	void attackPatternSign();

	void linkPlayer(player* player) { _player = player; }
	player* getPlayer() { return _player; }

	tagEggNyang getEggNyang() { return _eggNyang; }
	void setImage(image* eggNyangImage) { _eggNyang.img = eggNyangImage; }

	void setEggNyangX(float x) { _eggNyang.x = x; }
	void setEggNyangY(float y) { _eggNyang.y = y; }
	int getBulletFireCount() { return _bulletFireCount; }
	void setBulletFireCount(int bulletCount) { _bulletFireCount = bulletCount; }
};

