#pragma once
#include "gameNode.h"
#include "bulletKing.h"
#include "player.h"
#include "bulletKingMap.h"

class bulletKingBattle : public gameNode
{
private:
	bulletKing* _bulletKing;
	player* _player;

	//�ʰ���
	bulletKingMap* _bulletKingMap;
	POINT _mapMouse;
public:
	bulletKingBattle();
	~bulletKingBattle();

	HRESULT init();
	void release();
	void update();
	void render();

};

