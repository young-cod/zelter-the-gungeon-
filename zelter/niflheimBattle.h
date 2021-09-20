#pragma once
#include "gameNode.h"
#include "niflheim.h"
#include "player.h"
#include "niflheimMap.h"

class niflheimBattle : public gameNode
{
	niflheim*	_niflheim;
	player*		_player;

	niflheimMap* _niflheimMap;

	image*	_backGround;

	RECT _rc[9];
	
	float _gravity;

	int tempW, tempH;
public :
	niflheimBattle() {};
	~niflheimBattle() {};

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setRect();
};

