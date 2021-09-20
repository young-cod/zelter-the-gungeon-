#include "stdafx.h"
#include "niflheimBattle.h"

HRESULT niflheimBattle::init()
{
	SOUNDMANAGER->addSound("niflheimBGM", "sound/니플헤임 보스 배경음악.wav", true, true);

	IMAGEMANAGER->addImage("niflheimBackGround", L"niflheim/niflheimBackGround.png");
	_backGround = IMAGEMANAGER->findImage("niflheimBackGround");

	_niflheimMap = new niflheimMap;
	_niflheimMap->init();
	CAMERAMANAGER->setX(0);
	CAMERAMANAGER->setY(0);


	_player = new player;
	_player->init();
	_player->setKeyType(true);

	_niflheim = new niflheim;
	_niflheim->init();

	_player->linkNiflheimMap(_niflheimMap);
	_player->linkNiflheim(_niflheim);
	_niflheim->linkPlayer(_player);


	SOUNDMANAGER->play("niflheimBGM");

	return S_OK;
}

void niflheimBattle::release()
{

}

void niflheimBattle::update()
{
	setRect();

	_player->setKeyType(true);

	_niflheimMap->update();
	_niflheim->update();
	_player->update();


		
	if (SCENEMANAGER->isCurrentScene("niflheim"))
	{
		if (IsCollision(_rc[3], _player->getPlayer().rc))_player->setPlayerIscollde(true);
		else if (IsCollision(_rc[4], _player->getPlayer().rc))_player->setPlayerIscollde(true);
		else if (IsCollision(_rc[5], _player->getPlayer().rc))_player->setPlayerIscollde(true);
		else if (IsCollision(_rc[6], _player->getPlayer().rc))_player->setPlayerIscollde(true);
		else if (IsCollision(_rc[7], _player->getPlayer().rc))_player->setPlayerIscollde(true);
		else if (IsCollision(_rc[8], _player->getPlayer().rc))_player->setPlayerIscollde(true);
		else { _player->setPlayerIscollde(false); }



		if (_player->getPlayer().y <= 84)
		{
			_player->setPlayerJumpPower(0);
			_player->setPlayerisEnd(true);
			_player->setIsjump(false);
			_player->setPlayerY(84);
		}


		if (IsCollision(_rc[0], _player->getPlayer().rc))_player->setPlayerX(_player->getPlayer().x + _player->getPlayer().speed * 2);
		if (IsCollision(_rc[2], _player->getPlayer().rc))_player->setPlayerX(_player->getPlayer().x - _player->getPlayer().speed * 2);
	}
	
}

void niflheimBattle::render()
{
	_backGround->render(0, 0);

	_niflheimMap->render();
	_niflheim->render();
	_player->render();


	for (int i = 0; i < 9; i++)
	{
		D2DRENDER->DrawRectangle(_rc[i], D2DRenderer::DefaultBrush::Black);
	}
}

void niflheimBattle::setRect()
{
	_rc[0] = RectMake(0, 0, 50, WINSIZEY);
	_rc[1] = RectMake(0, 0, WINSIZEX, 50);
	_rc[2] = RectMake(WINSIZEX - 50, 0, 50, WINSIZEY);
	_rc[3] = RectMake(0, WINSIZEY - 50, WINSIZEX, 50);

	_rc[4] = RectMake(WINSIZEX / 2 + 100, WINSIZEY / 2 - 170, 290, 70);
	_rc[5] = RectMake(WINSIZEX / 2 - 413, WINSIZEY / 2 - 170, 290, 70);
	_rc[6] = RectMake(WINSIZEX / 2 + 227, WINSIZEY / 2 + 55, 290, 30);
	_rc[7] = RectMake(WINSIZEX / 2 - 540, WINSIZEY / 2 + 55, 290, 30);
	_rc[8] = RectMake(WINSIZEX / 2 - 187, WINSIZEY / 2 + 215, 352, 30);
}
