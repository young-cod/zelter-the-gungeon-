#include "stdafx.h"
#include "playerFall.h"

#include "playerDie.h"
#include "playerAttack.h"
#include "playerDash.h"
#include "playerJump.h"
#include "playerStateIdle.h"
#include "playerHit.h"
#include "player.h"

playerState * playerFall::inputHandle(player * player)
{
	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON)) return new playerDash;
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) return new playerAttack();
	if (player->getPlayer().isCollide) return new playerStateIdle();

	if (player->getPlayer().isHit == true) return new playerHit();

	if (player->getPlayer().currentHP <= 0)
	{
		player->setPlayerisDeath(true);
		return new playerDie();
	}
	return nullptr;
}

void playerFall::update(player * player)
{
	_mapMouse.x = _ptMouse.x + CAMERAMANAGER->getX();
	_mapMouse.y = _ptMouse.y + CAMERAMANAGER->getY();

	if (KEYMANAGER->isStayKeyDown('D'))
	{
		player->setPlayerX(player->getPlayer().x + player->getPlayer().speed*2);
	}

	if (KEYMANAGER->isStayKeyDown('A'))
	{
		player->setPlayerX(player->getPlayer().x - player->getPlayer().speed*2);
	}
	switch (player->getPlayer().direction)
	{
	case 0:
		player->setPlayerImage(IMAGEMANAGER->findImage("gunner_right_run"));
		break;
	case 1:
		player->setPlayerImage(IMAGEMANAGER->findImage("gunner_left_run"));
		break;
	case 2:
		player->setPlayerImage(IMAGEMANAGER->findImage("gunner_right_run"));
		break;
	case 3:
		player->setPlayerImage(IMAGEMANAGER->findImage("gunner_left_run"));
		break;
	case 4:
		player->setPlayerImage(IMAGEMANAGER->findImage("gunner_left_run"));
		break;
	case 5:
		player->setPlayerImage(IMAGEMANAGER->findImage("gunner_right_run"));
		break;
	case 6:
		player->setPlayerImage(IMAGEMANAGER->findImage("gunner_right_run"));
		break;
	case 7:
		player->setPlayerImage(IMAGEMANAGER->findImage("gunner_left_run"));
		break;
	}

	_jumpPower -= _gravity;

	player->setPlayerY(player->getPlayer().y - _jumpPower);

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

void playerFall::enter(player * player)
{
	_jumpPower = 0.0f;
	_gravity = 0.4f;
}

void playerFall::exit(player * player)
{
}
