#pragma once
#include "gameNode.h"
#include "bulletKingState.h"
#include "bulletKingIdle.h"
#include "bulletKingBullet.h"
#include "progressBar.h"
#include "playerBullet.h"

class player;

struct tagBulletKing
{
	image* img;							//��źŷ �̹���

	RECT rc;							//��źŷ ��Ʈ
	float speed;						//��źŷ �ӵ�
	float angle;						//��źŷ ����(����)
	float x, y;							//��źŷ x, y
	int width, height;					//��źų ���� ����, ���� ����
	int currentFrameX;					//��źŷ x�� ���� ������
	int maxHp, currentHp;				//��źŷ �ִ� ü��, ���� ü��
	bool isAttack3;						//3���� ���� �߻� ����
};

class bulletKing : public gameNode
{
private:
	//��źŷ ��ü �� ���� ����ü
	tagBulletKing _bulletKing;
	tagBulletKing _bulletKingChair;

	//ü��
	progressBar* _hp;
	image* _bulletKing_hp;

	//�Ѿ� Ŭ����
	bulletKingBullet* _bullet;

	//��źŷ ��������
	bulletKingState* _state;


	player* _player;

public:
	bulletKing();
	~bulletKing();

	HRESULT init();
	void release();
	void update();
	void render();
	void InputHandle();
	void setBoss();
	void collision();

	tagBulletKing& getBulletKing() { return _bulletKing; }
	void setBulletKingX(int x) { _bulletKing.x = x; }
	void setBulletKingY(int y) { _bulletKing.y = y; }
	void setBulletKingCurrentFrameX(int currentX) { _bulletKing.currentFrameX = currentX; }
	void setBulletKingImg(image* bulletKingImg) { _bulletKing.img = bulletKingImg; }
	void setBulletKingIsAttack3(bool bulletKingIsAttack3) { _bulletKing.isAttack3 = bulletKingIsAttack3; }

	tagBulletKing& getBulletKingChair() { return _bulletKingChair; }
	void setBulletKingChairX(int x) { _bulletKingChair.x = x; }
	void setBulletKingChairY(int y) { _bulletKingChair.y = y; }
	void setBulletKingChairCurrentFrameX(int currentX) { _bulletKingChair.currentFrameX = currentX; }
	void setBulletKingAttack3(bool bulletKingChairAttack3) { _bulletKingChair.isAttack3 = bulletKingChairAttack3; }

	//�Ѿ� get
	bulletKingBullet* getBulletKingBullet() { return _bullet; }


	void linkPlayer(player* player) { _player = player; }
	player* getPlayer() { return _player; }
};

