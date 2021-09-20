#include "stdafx.h"
#include "ammocondaAttack1.h"
#include "ammocondaAttack2.h"
#include "ammocondaIdle.h"
#include "ammocondaRecovery.h"
#include "player.h"
#include "ammocondaDeath.h"

ammocondaState * ammocondaAttack1::InputHandle(ammoconda * ammoconda)
{
	int rand1 = RND->getFromIntTo(0, 2);
	int rand2 = RND->getFromIntTo(0, 3);
	//ī��Ʈ ���������� ���º�ȯ
	if (_changeCount >= 300)
	{
		switch (ammoconda->getIsPotCreate() ? rand2 : rand1)
		{
		case 0:
			return new ammocondaIdle();
			break;
		case 1:
			return new ammocondaAttack2();
			break;
		case 2:
			return new ammocondaRecovery();
			break;
		}
	}
	if (ammoconda->getCurrentHp() <= 3)
	{
		return new ammocondaDeath();
	}
	return nullptr;
}

void ammocondaAttack1::enter(ammoconda * ammoconda)
{
	SOUNDMANAGER->addSound("�Ƹ��ٰܴ���1", "sound/�Ƹ��ٰܴ���1.wav", false, false);

	_changeCount = 0;
	_angleCount = 0;
	ammoconda->getAmmoconda(0).currentFrameY = 0;
	for (int i = 1; i < AMMOCONDAMAX; i++)
	{
		ammoconda->getAmmoconda(i).isAttack = false;
		ammoconda->getAmmoconda(i).currentFrameX = 0;
	}
}

void ammocondaAttack1::update(ammoconda * ammoconda)
{
	//���º�ȯ, �ޱ۰�, �̹����� ���� ī��Ʈ ����
	_changeCount++;
	_angleCount++;
	_count++;

	ammoconda->bossMove(_angleCount, 50, "ammocondaHead");

	_attackRand = RND->getFromIntTo(1, 100);

	//1 ~100������ ������ �� ������ �ε����� ��ġ�ϸ� isAttack��� bool�� true
	if (_attackRand < AMMOCONDAMAX - 1) ammoconda->getAmmoconda(_attackRand + 1).isAttack = true;
	//�� ������ isAttack�̶�� bool�� �� true�� ���� ����
	for (int i = 1; i < AMMOCONDAMAX; i++)
	{
		if (!ammoconda->getAmmoconda(i).isAttack) continue;
		attack(ammoconda, i);
	}
}

void ammocondaAttack1::render(ammoconda * ammoconda)
{
}

void ammocondaAttack1::exit(ammoconda * ammoconda)
{
}

void ammocondaAttack1::attack(ammoconda* ammoconda, int bodyNum)
{
	ammoconda->getAmmoconda(bodyNum).count++;

	//������ ��ȯ
	if (ammoconda->getAmmoconda(bodyNum).count % 20 == 0)
	{
		ammoconda->getAmmoconda(bodyNum).currentFrameX++;
		//�Ѿ� �߻�(�̹��� �������� ��ġ�� ���)
		if (ammoconda->getAmmoconda(bodyNum).currentFrameX == 3)
		{
			SOUNDMANAGER->play("�Ƹ��ٰܴ���1");
			ammoconda->getBAmmocondaBullet()->bulletFire1(ammoconda->getAmmoconda(bodyNum).x, ammoconda->getAmmoconda(bodyNum).y, ammoconda->getPlayer()->getPlayer().x, ammoconda->getPlayer()->getPlayer().y);
		}
		//������ ����ó��
		if (ammoconda->getAmmoconda(bodyNum).currentFrameX >= ammoconda->getAmmoconda(bodyNum).img->getMaxFrameX())
		{
			ammoconda->getAmmoconda(bodyNum).currentFrameX = 0;
			ammoconda->getAmmoconda(bodyNum).isAttack = false;
		}
	}
}

