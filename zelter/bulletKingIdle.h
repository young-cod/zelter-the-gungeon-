#pragma once
#include "bulletKingState.h"
#include "bulletKing.h"
#include "bulletKingHit.h"
#include "bulletKingDeath.h"
#include "bulletKingAttack1.h"
#include "bulletKingAttack2.h"
#include "bulletKingAttack3.h"

class bulletKingIdle : public bulletKingState
{
private:
	//�̹��� �����ӿ�
	int _count;
	
	//�̵� ����
	int _randCount;
	int _rand;

	//���� ���º��� ����
	int _changeCount;
	int _changeRand;
public:
	virtual bulletKingState* InputHandle(bulletKing* bulletKing);
	virtual void enter(bulletKing* bulletKing);
	virtual void update(bulletKing* bulletKing);
	virtual void render(bulletKing* bulletKing);
	virtual void exit(bulletKing* bulletKing);

};

