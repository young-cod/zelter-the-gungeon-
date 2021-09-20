#include "stdafx.h"
#include "playerJump.h"
#include "playerStateIdle.h"
#include "playerDie.h"
#include "playerHit.h"
#include "playerAttack.h"
#include "playerRun.h"
#include "playerDash.h"
#include "playerFall.h"

playerState * playerJump::inputHandle(player * player)
{
	
	
	if (_jumpPower <= 0)
	{
		player->setPlayerisEnd(true);
		player->setIsjump(false);
		return new playerFall;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) return new playerAttack();
	if (player->getPlayer().isHit == true) return new playerHit();
	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON)) return new playerDash;
	if (player->getPlayer().currentHP <= 0)
	{
		player->setPlayerisDeath(true);
		return new playerDie();
	}
	return nullptr;
}

void playerJump::update(player * player)
{
	_mapMouse.x = _ptMouse.x + CAMERAMANAGER->getX();
	_mapMouse.y = _ptMouse.y + CAMERAMANAGER->getY();

	player->setPlayerY(player->getPlayer().y - _jumpPower);
	_jumpPower -= _gravity;


	if (KEYMANAGER->isStayKeyDown('D'))
	{
		player->setPlayerX(player->getPlayer().x + player->getPlayer().speed*2);
	}

	if (KEYMANAGER->isStayKeyDown('A'))
	{
		player->setPlayerX(player->getPlayer().x - player->getPlayer().speed*2);
	}




	
	_count++;
	if (_count % 7 == 0)
	{
		player->setPlayerCurrentFrameX(player->getPlayer().currentFrameX + 1);
		if (player->getPlayer().currentFrameX >= player->getPlayer().img->getMaxFrameX()) player->setPlayerCurrentFrameX(0);
		_count = 0;
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

void playerJump::enter(player * player)
{
	_jumpPower = 15.0f;
	_gravity = 0.5f;
	if (player->getPlayer().direction == 0) player->setPlayerImage(IMAGEMANAGER->findImage("gunner_right_jump"));
	if (player->getPlayer().direction == 1) player->setPlayerImage(IMAGEMANAGER->findImage("gunner_left_jump"));
	player->setIsjump(true);
	player->setPlayerisEnd(false);
	player->setPlayerIscollde(false);
}

void playerJump::exit(player * player)
{
}

