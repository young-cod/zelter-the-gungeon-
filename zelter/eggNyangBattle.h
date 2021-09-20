#pragma once
#include "gameNode.h"
#include "eggNyang.h"
#include "player.h"
#include "eggNyangMap.h"

class eggNyangBattle : public gameNode
{
	eggNyang*	_eggNyang;
	player*		_player;

	eggNyangMap* _eggNyangMap;

	image*	_backGround;

	RECT _rc[4];
public :
	eggNyangBattle() {};
	~eggNyangBattle() {};

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

