#pragma once
#include "gameNode.h"
#define BULLETMAX 100

struct tagAmmocondaBullet
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
	int isWave;			//�Ѿ� ���̺�ȿ����
};

class ammocondaBullet : public gameNode
{
private:
	//����1 �Ѿ�
	vector<tagAmmocondaBullet>				_vAmmocondaBullet1;
	vector<tagAmmocondaBullet>::iterator	_viAmmocondaBullet1;
	//����2 �Ѿ�
	vector<tagAmmocondaBullet>				_vAmmocondaBullet2;
	vector<tagAmmocondaBullet>::iterator	_viAmmocondaBullet2;
	//�׾Ƹ� �Ѿ�
	vector<tagAmmocondaBullet>				_vPotBullet;
	vector<tagAmmocondaBullet>::iterator	_viPotBullet;

	//�̹��� ������ ī��Ʈ��
	int _count;

public:
	ammocondaBullet();
	~ammocondaBullet();

	HRESULT init();
	void release();
	void update();
	void render();

	void bulletFire1(float x, float y, float playerX, float playerY);
	void bulletMove1();
	void bulletFire2(float x, float y, float playerX, float playerY);
	void bulletMove2();
	void bulletFirePot(float x, float y, float playerX, float playerY);
	void bulletMovePot();

	//����1 �Ѿ�
	vector<tagAmmocondaBullet>				getVammoCondaBullet1() {return _vAmmocondaBullet1;}
	vector<tagAmmocondaBullet>::iterator	getVIammoCondaBullet1() { return _viAmmocondaBullet1; }
	//����2 �Ѿ�
	vector<tagAmmocondaBullet>				getVammoCondaBullet2() {return _vAmmocondaBullet2;}
	vector<tagAmmocondaBullet>::iterator	getViammoCondaBullet2() {return _viAmmocondaBullet2;}
	//�׾Ƹ� �Ѿ�
	vector<tagAmmocondaBullet>				getVpotBullet() { return _vPotBullet;}
	vector<tagAmmocondaBullet>::iterator	getVipotBullet() { return _viPotBullet; }
	
};

