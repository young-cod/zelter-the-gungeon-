#pragma once
#include "eggNyangStateBase.h"
#include "player.h"

class eggNyang;

class eggNyangAttack2 : public eggNyangStateBase
{
	int _eggNyangPositionPattern;	//�̵� ������ ���� ����, ���, �ߴ�, ����, �Ͽ�

public:
	virtual eggNyangStateBase* inputHandle(eggNyang* eggNyang);
	virtual void update(eggNyang* eggNyang);
	virtual void enter(eggNyang* eggNyang);
	virtual void render(eggNyang* eggNyang);
	virtual void exit(eggNyang* eggNyang);

	void movePosition(eggNyang* eggNyang, int eggNyangPositionPattern);
	void eggNyangMove(eggNyang* eggNyang, int eggNyangPositionPattern);
};

