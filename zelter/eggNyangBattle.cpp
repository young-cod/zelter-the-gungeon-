#include "stdafx.h"
#include "eggNyangBattle.h"

HRESULT eggNyangBattle::init()
{
	SOUNDMANAGER->addSound("eggNyangBGM", "sound/에그냥 보스 배경음악.wav", true, true);

	IMAGEMANAGER->addImage("eggNyangBackGround", L"eggNyang/eggNyangBackGround.png");
	_backGround = IMAGEMANAGER->findImage("eggNyangBackGround");
	CAMERAMANAGER->setX(0);
	CAMERAMANAGER->setY(0);

	
	_eggNyangMap = new eggNyangMap;
	_eggNyangMap->init();
	_eggNyang = new eggNyang;
	_eggNyang->init();
	_player = new player;
	_player->init();
	
	_eggNyang->linkPlayer(_player);
	_player->linkEggNyang(_eggNyang);
	_player->linkEggNyangMap(_eggNyangMap);

	SOUNDMANAGER->play("eggNyangBGM");

	return S_OK;
}

void eggNyangBattle::release()
{
}

void eggNyangBattle::update()
{
	_player->setKeyType(true);
	_eggNyangMap->update();
	_eggNyang->update();
	_player->update();

	_rc[0] = RectMake(0, 0, 40, WINSIZEY);
	_rc[1] = RectMake(0, 0, WINSIZEX, 40);
	_rc[2] = RectMake(WINSIZEX - 50, 0, 50, WINSIZEY);
	_rc[3] = RectMake(0, WINSIZEY - 50, WINSIZEX, 50);


	if (IsCollision(_rc[0], _player->getPlayer().rc))_player->setPlayerX(_player->getPlayer().x + _player->getPlayer().speed * 2);
	if (IsCollision(_rc[3], _player->getPlayer().rc))_player->setPlayerIscollde(true);
	else { _player->setPlayerIscollde(false); }
	if (IsCollision(_rc[2], _player->getPlayer().rc))_player->setPlayerX(_player->getPlayer().x - _player->getPlayer().speed * 2);
	
	/*for (int i = 0; i < WINSIZEY / 32; i++)
	{
		for (int j = 0; j < WINSIZEX / 32; j++)
		{
			if (_eggNyangMap->getTileAttribute()[i * TILEX + j] == NONEMOVE &&
				IsCollision(_eggNyangMap->getTile()[i * TILEX + j].rc, _player->getPlayer().rc))_player->setPlayerIscollde(true);
		}
	}*/

}

void eggNyangBattle::render()
{
	_backGround->render(0, 0);

	_eggNyangMap->render();
	_eggNyang->render();
	_player->render();
	for (int i = 0; i < 9; i++)
	{
		D2DRENDER->DrawRectangle(_rc[i], D2DRenderer::DefaultBrush::Black);
	}
}
