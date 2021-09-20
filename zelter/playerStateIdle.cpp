#include "stdafx.h"
#include "playerStateIdle.h"

#include "player.h"
#include "playerRoll.h" //������
#include "playerJump.h" // ����
#include "playerDonwJump.h"
#include "playerRun.h" // �޸���
#include "playerAttack.h"
#include "playerHit.h"
#include "playerDie.h"
#include "playerDash.h"
#include "playerFall.h"


playerState * playerStateIdle::inputHandle(player * player)
{
	if ((player->getPlayer().x < WINSIZEX - CAMERAMANAGER->getX()|| player->getPlayer().x>0 - CAMERAMANAGER->getX() ) && (player->getPlayer().y < WINSIZEY - CAMERAMANAGER->getY() || player->getPlayer().y>0 - CAMERAMANAGER->getY()))
	{
		if (player->getPlayer().isDunGreed == true)
		{
			if (KEYMANAGER->isStayKeyDown('S') && KEYMANAGER->isOnceKeyDown(VK_SPACE)) return new playerDonwJump();

			if(player->getPlayer().y >= 84)
			{
				if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) return new playerJump();
			}
			
			if (KEYMANAGER->isStayKeyDown('A') || KEYMANAGER->isStayKeyDown('D'))return new playerRun();
			if (!player->getPlayer().isEnd&&KEYMANAGER->isOnceKeyDown(VK_RBUTTON)) return new playerDash;

			if(player->getPlayer().y <=84)
			{
				if (!player->getPlayer().isCollide) return new playerFall;
			}
			
		}
		else
		{
			if (KEYMANAGER->isStayKeyDown('A') || KEYMANAGER->isStayKeyDown('D') ||
				KEYMANAGER->isStayKeyDown('W') || KEYMANAGER->isStayKeyDown('S'))
			{
				return new playerRun();
			}
		}

	}
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) return new playerAttack();

	if (player->getPlayer().isHit == true) return new playerHit();

	if (player->getPlayer().currentHP <= 0)
	{
		player->setPlayerisDeath(true);
		return new playerDie();
	}
	return nullptr;
}

void playerStateIdle::update(player * player)
{
	_mapMouse.x = _ptMouse.x + CAMERAMANAGER->getX();
	_mapMouse.y = _ptMouse.y + CAMERAMANAGER->getY();

	if (player->getPlayer().isDunGreed)
	{
		switch (player->getPlayer().direction)
		{
		case 0:
			player->setPlayerImage(IMAGEMANAGER->findImage("gunner_right_idle"));
			break;
		case 1:
			player->setPlayerImage(IMAGEMANAGER->findImage("gunner_left_idle"));
			break;
		case 2:
			player->setPlayerImage(IMAGEMANAGER->findImage("gunner_right_idle"));
			break;
		case 3:
			player->setPlayerImage(IMAGEMANAGER->findImage("gunner_left_idle"));
			break;
		case 4:
			player->setPlayerImage(IMAGEMANAGER->findImage("gunner_left_idle"));
			break;
		case 5:
			player->setPlayerImage(IMAGEMANAGER->findImage("gunner_right_idle"));
			break;
		case 6:
			player->setPlayerImage(IMAGEMANAGER->findImage("gunner_right_idle"));
			break;
		case 7:
			player->setPlayerImage(IMAGEMANAGER->findImage("gunner_left_idle"));
			break;
		}
	}


	else
	{
		switch (player->getPlayer().direction)
		{
		case 0:
			player->setPlayerImage(IMAGEMANAGER->findImage("gunner_right_idle"));
			break;
		case 1:
			player->setPlayerImage(IMAGEMANAGER->findImage("gunner_left_idle"));
			break;
		case 2:
			player->setPlayerImage(IMAGEMANAGER->findImage("gunner_back_idle"));
			break;
		case 3:
			player->setPlayerImage(IMAGEMANAGER->findImage("gunner_idle"));
			break;
		case 4:
			player->setPlayerImage(IMAGEMANAGER->findImage("gunner_left-up_idle"));
			break;
		case 5:
			player->setPlayerImage(IMAGEMANAGER->findImage("gunner_right-up_idle"));
			break;
		case 6:
			player->setPlayerImage(IMAGEMANAGER->findImage("gunner_right_idle"));
			break;
		case 7:
			player->setPlayerImage(IMAGEMANAGER->findImage("gunner_left_idle"));
			break;
		}
	}
	


	_count++;
	if (_count % 7 == 0)
	{
		player->setPlayerCurrentFrameX(player->getPlayer().currentFrameX + 1);

		if (player->getPlayer().currentFrameX >= player->getPlayer().img->getMaxFrameX()) player->setPlayerCurrentFrameX(0);
		_count = 0;
	}

	if (player->getPlayer().isDunGreed)
	{
		if (!player->getPlayer().isCollide)
		{
			_jumpPower -= _gravity;

			player->setPlayerY(player->getPlayer().y - _jumpPower);

		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	{
		if (player->getPlayerGuntype() == FLAMETHROWER)
		{
			player->getPlayerBullet()->fire(player->getPlayer().x, player->getPlayer().y,
				RND->getFromFloatTo(GetAngle(player->getPlayer().x, player->getPlayer().y, _mapMouse.x, _mapMouse.y) + 0.15,
					GetAngle(player->getPlayer().x, player->getPlayer().y, _mapMouse.x, _mapMouse.y) - 0.15), 10, player->getPlayerGuntype(), 0);
		}
	}

	return;
}

void playerStateIdle::enter(player * player)
{
	switch (player->getPlayer().direction)
	{
	case 0:
		player->setPlayerImage(IMAGEMANAGER->findImage("gunner_right_idle"));
		break;
	case 1:
		player->setPlayerImage(IMAGEMANAGER->findImage("gunner_left_idle"));
		break;
	case 2:
		player->setPlayerImage(IMAGEMANAGER->findImage("gunner_back_idle"));
		break;
	case 3:
		player->setPlayerImage(IMAGEMANAGER->findImage("gunner_idle"));
		break;
	case 4:
		player->setPlayerImage(IMAGEMANAGER->findImage("gunner_left-up_idle"));
		break;
	case 5:
		player->setPlayerImage(IMAGEMANAGER->findImage("gunner_right-up_idle"));
		break;
	case 6:
		player->setPlayerImage(IMAGEMANAGER->findImage("gunner_right_idle"));
		break;
	case 7:
		player->setPlayerImage(IMAGEMANAGER->findImage("gunner_left_idle"));
		break;
	}
}

void playerStateIdle::exit(player * player)
{
	_gravity = 0;
}