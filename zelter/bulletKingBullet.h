#pragma once
#include "gameNode.h"
#include <vector>
#define BULLETMAX 60

struct tagBulletKingBullet
{
	image* img;				//�Ѿ� �̹���
	RECT rc;				//�Ѿ� ��Ʈ
	float x, y;				//�Ѿ� x, y
	float width, height;	//�Ѿ� ���α���, ���α���
	float centerX, centerY; //�Ѿ� �߾�
	float fireX, fireY;		//�Ѿ� ��Ʈ �߾Ӱ�
	int currentX;			//�Ѿ� ���� x�� ������
	float speed;			//�Ѿ� �ӵ�
	float angle;			//�Ѿ� ����(����)
	bool isFire;			//�Ѿ� �߻� ����
};

class bulletKingBullet : public gameNode
{
private:
	//����1 �Ѿ�
	vector<tagBulletKingBullet>			  _vBulletKingBullet1;
	vector<tagBulletKingBullet>::iterator _viBulletKingBullet1;
	//����2 �Ѿ�
	vector<tagBulletKingBullet>			  _vBulletKingBullet2;
	vector<tagBulletKingBullet>::iterator _viBulletKingBullet2;
	//����3 �Ѿ�
	vector<tagBulletKingBullet>			  _vBulletKingBullet3;
	vector<tagBulletKingBullet>::iterator _viBulletKingBullet3;

	//�̹��� ������ ī��Ʈ��
	int _count;
	

public:
	bulletKingBullet();
	~bulletKingBullet();

	void release();
	void update();
	void render();

	void bulletFire1(float x, float y);
	void bulletMove1();
	void bulletFire2(float x, float y, float playerX, float playerY);
	void bulletMove2();
	void bulletFire3(float x, float y);
	void bulletMove3();

	vector<tagBulletKingBullet>			    getvBulletKingBullet1() { return _vBulletKingBullet1; }
	vector<tagBulletKingBullet>::iterator   getviBulletKingBullet1() { return  _viBulletKingBullet1; }

	vector<tagBulletKingBullet>				getvBulletKingBullet2() { return _vBulletKingBullet2; }
	vector<tagBulletKingBullet>::iterator   getviBulletKingBullet2() { return _viBulletKingBullet2; }

	vector<tagBulletKingBullet>				getvBulletKingBullet3() { return _vBulletKingBullet3; }
	vector<tagBulletKingBullet>::iterator   getviBulletKingBullet3() { return _viBulletKingBullet3; }
};

