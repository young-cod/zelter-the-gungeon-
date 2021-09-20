#pragma once
#include "tileNode.h"
#include "gameNode.h"


struct tagBossDoor
{
	image* img;		//���� ���幮 �̹���
	RECT rc;		//���� ���幮 ��Ʈ
	float x, y;		//���� ���幮 ��ġ	
};

class inGameMap : public gameNode
{
private:

	tagTile _tile[TILEX*TILEY];
	DWORD _attribute[TILEX*TILEY];
	POINT _mapMouse;

	int _pos[2];

	//���� ���� ����ü
	tagBossDoor _bossDoorRect[4];
public:
	inGameMap() {};
	~inGameMap() {};

	HRESULT init();
	void release();
	void update();
	void render();
	void load();
	void setDoor();

	tagTile* getTile() { return _tile; }
	//Ÿ�� �Ӽ��� ���� �����ڵ� �������� �÷��̾� ��ü�� ���ʹ� ��ü�� ���� ����
	DWORD*  getTileAttribute() { return _attribute; }

	int getPosFirst() { return _pos[0]; }
	int getPosSecond() { return _pos[1]; }

	tagBossDoor getBossDoor(int index) { return _bossDoorRect[index]; }

};

