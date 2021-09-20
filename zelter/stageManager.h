#pragma once
#include "gameNode.h"
#include "testScene.h"
#include "mapmap.h"
#include "characterPick.h"
#include "inGame.h"
#include "ammocondaBattle.h"
#include "bulletKingBattle.h"
#include "eggNyangBattle.h"
#include "niflheimBattle.h"
#include "loading.h"
#include "startTitle.h"

class player;

class stageManager : public gameNode
{
private:
	player* _player;
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void sceneSet();
};
