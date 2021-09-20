#include "stdafx.h"
#include "fishMan.h"

fishMan::fishMan()
{
}

fishMan::~fishMan()
{
}

HRESULT fishMan::init()
{
	IMAGEMANAGER->addFrameImage("fishManIdle", L"fishMan/fishManIdle.png", 3, 2);
	IMAGEMANAGER->addFrameImage("fishManWalk", L"fishMan/fishManWalk.png", 4, 2);
	IMAGEMANAGER->addFrameImage("fishManRun", L"fishMan/fishManRun.png", 2, 2);
	IMAGEMANAGER->addFrameImage("fishManAttack", L"fishMan/fishManAttack.png", 3, 2);
	IMAGEMANAGER->addFrameImage("fishManDie", L"fishMan/fishManDie.png", 4, 2);
	_dialogue = new dialogue;
	return S_OK;
}

void fishMan::release()
{
}

void fishMan::update()
{

}

void fishMan::render()
{

	for (_viFishMan = _vFishMan.begin(); _viFishMan != _vFishMan.end(); ++_viFishMan)
	{
		if (KEYMANAGER->isToggleKey(VK_TAB))
		{
			D2DRENDER->DrawRectangle(_viFishMan->rc, D2DRenderer::DefaultBrush::White);
		}
		_viFishMan->img->frameRender2(_viFishMan->rc.left, _viFishMan->rc.top, _viFishMan->currentFrameX, _viFishMan->currentFrameY);
	}

	_dialogue->render();
}


void fishMan::setEnemy()
{


	for (int i = 0; i < 10; i++)
	{


		tagFishMan fishMan;
		ZeroMemory(&fishMan, sizeof(tagFishMan));
		fishMan.img = IMAGEMANAGER->findImage("fishManIdle");
		fishMan.speed = 2.0f;
		fishMan.angle = RND->getFromFloatTo(0, PI2);
		fishMan.x = RND->getFromIntTo(0, TILEX * TILESIZEX);
		fishMan.y = RND->getFromIntTo(0, TILEY * TILESIZEY);
		fishMan.currentHp = fishMan.maxHp = 100;
		fishMan.currentFrameX = fishMan.currentFrameY = 0;
		fishMan.count = fishMan.changeCount = 0;
		fishMan.state = FISHMAN_IDLE;
		//angle�� ���� ��������
		if (fishMan.angle > 0 && fishMan.angle <= PI / 2 || fishMan.angle >= PI + PI / 2 && fishMan.angle <= PI2)
			fishMan.direction_img = FISHMAN_RIGHT;
		else if (fishMan.angle > PI / 2 && fishMan.angle <= PI + PI / 2)
			fishMan.direction_img = FISHMAN_LEFT;
		fishMan.rc = RectMakeCenter(fishMan.x, fishMan.y, fishMan.img->getWidth() / fishMan.img->getMaxFrameX(), fishMan.img->getHeight() / fishMan.img->getMaxFrameY());

		_vFishMan.push_back(fishMan);
	}
}
//�ǽ��� ������
void fishMan::fishMove(float x, float y)
{
	for (_viFishMan = _vFishMan.begin(); _viFishMan != _vFishMan.end(); ++_viFishMan)
	{
		//�ǽ��� �ޱ۰��� ���� ����
		//������ ����
		if (_viFishMan->angle < PI / 8 && _viFishMan->angle > 0 ||
			PI + (PI / 8) * 7 < _viFishMan->angle && PI2 > _viFishMan->angle)						_viFishMan->direction = 0;
		//���� ����
		if (_viFishMan->angle < (PI / 8) * 5 && (PI / 8) * 3 < _viFishMan->angle)					_viFishMan->direction = 2;
		//���� ����	
		if (_viFishMan->angle < PI + (PI / 8) && (PI / 8) * 7 < _viFishMan->angle)					_viFishMan->direction = 1;
		//�Ʒ��� ����
		if (_viFishMan->angle < PI + (PI / 8) * 5 && PI + (PI / 8) * 3 < _viFishMan->angle)			_viFishMan->direction = 3;
		//������ �밢�� ��
		if (_viFishMan->angle < (PI / 8) * 3 && PI / 8 < _viFishMan->angle)							_viFishMan->direction = 5;
		//���� �밢�� ��
		if (_viFishMan->angle < (PI / 8) * 7 && (PI / 8) * 5 < _viFishMan->angle)					_viFishMan->direction = 4;
		//���� �밢�� �Ʒ�
		if (_viFishMan->angle < PI + (PI / 8) * 3 && PI + (PI / 8) < _viFishMan->angle)				_viFishMan->direction = 7;
		//������ �밢�� �Ʒ�
		if (_viFishMan->angle < PI + (PI / 8) * 7 && PI + (PI / 8) * 5 < _viFishMan->angle)			_viFishMan->direction = 6;

		//�������� ���� IDLE Ȥ�� WALK ���·� ����
		_viFishMan->changeCount++;
		if (_viFishMan->changeCount >= RND->getFromIntTo(100, 200))
		{
			_viFishMan->angle = RND->getFromFloatTo(0, PI2);

			int changeRand = RND->getFromIntTo(0, 2);

			switch (changeRand)
			{
			case 0:
				_viFishMan->state = FISHMAN_IDLE;
				break;
			case 1:
				_viFishMan->state = FISHMAN_WALK;
				break;
			}
			_viFishMan->changeCount = 0;
		}
		//WALK ������ ��� speed ���� ���� �̵�
		if (_viFishMan->state == FISHMAN_WALK)
		{
			_viFishMan->x += cosf(_viFishMan->angle) * _viFishMan->speed;
			_viFishMan->y += -sinf(_viFishMan->angle) * _viFishMan->speed;

		}
		if (GetDistance(_viFishMan->x, _viFishMan->y, x, y) < 300 && GetDistance(_viFishMan->x, _viFishMan->y, x, y) > 30)
		{
			_viFishMan->state = FISHMAN_RUN;
			_viFishMan->angle = GetAngle(_viFishMan->x, _viFishMan->y, x, y);

			_viFishMan->x += cosf(_viFishMan->angle) * _viFishMan->speed;
			_viFishMan->y += -sinf(_viFishMan->angle) * _viFishMan->speed;
		}
		if (GetDistance(_viFishMan->x, _viFishMan->y, x, y) <= 30)
		{
			_viFishMan->state = FISHMAN_ATTACK;
			_viFishMan->angle = GetAngle(_viFishMan->x, _viFishMan->y, x, y);
		}
		if (GetDistance(_viFishMan->x, _viFishMan->y, x, y) > 300)
		{
			_viFishMan->state = FISHMAN_WALK;
		}
		if (_viFishMan->currentHp <= 0)
		{
			_viFishMan->state = FISHMAN_DEATH;

		}
		//angle�� ���� ��������
		if (_viFishMan->angle > 0 && _viFishMan->angle <= PI / 2 || _viFishMan->angle >= PI + PI / 2 && _viFishMan->angle <= PI2)_viFishMan->direction_img = FISHMAN_RIGHT;
		else if (_viFishMan->angle > PI / 2 && _viFishMan->angle <= PI + PI / 2)_viFishMan->direction_img = FISHMAN_LEFT;
		//angle ����ó��
		if (_viFishMan->angle >= PI2)_viFishMan->angle -= PI2;
		if (_viFishMan->angle <= 0) _viFishMan->angle += PI2;
		//ȭ�� �� ����ó��
		if (_viFishMan->rc.left < 0) _viFishMan->x = (_viFishMan->img->getWidth() / _viFishMan->img->getMaxFrameX()) / 2;
		if (_viFishMan->rc.right > TILEX * TILESIZEX) _viFishMan->x = TILEX * TILESIZEX - (_viFishMan->img->getWidth() / _viFishMan->img->getMaxFrameX()) / 2;
		if (_viFishMan->rc.top < 0) _viFishMan->y = (_viFishMan->img->getHeight() / _viFishMan->img->getMaxFrameY()) / 2;
		if (_viFishMan->rc.bottom > TILEY * TILESIZEY) _viFishMan->y = TILEY * TILESIZEY - (_viFishMan->img->getHeight() / _viFishMan->img->getMaxFrameY()) / 2;
		//��Ʈ 
		_viFishMan->rc = RectMakeCenter(_viFishMan->x, _viFishMan->y, _viFishMan->img->getWidth() / _viFishMan->img->getMaxFrameX(), _viFishMan->img->getHeight() / _viFishMan->img->getMaxFrameY());
	}

	_dialogue->update();
	tileCheck();
}
//�ǽ��� ����
void fishMan::fishState()
{
	for (_viFishMan = _vFishMan.begin(); _viFishMan != _vFishMan.end(); ++_viFishMan)
	{
		//�̹��� ������ ��ȯ
		_viFishMan->count++;
		if (_viFishMan->count % 15 == 0)
		{
			switch (_viFishMan->direction_img)
			{
			case FISHMAN_RIGHT:
				_viFishMan->currentFrameY = 0;
				_viFishMan->currentFrameX++;

				break;
			case FISHMAN_LEFT:
				_viFishMan->currentFrameY = 1;
				_viFishMan->currentFrameX--;

				break;
			}
		}
		//���º� ����ó��
		switch (_viFishMan->state)
		{
			//IDLE ������ ���
		case FISHMAN_IDLE:
			_viFishMan->img = IMAGEMANAGER->findImage("fishManIdle");
			switch (_viFishMan->direction_img)
			{
			case FISHMAN_RIGHT:
				if (_viFishMan->currentFrameX > 2)_viFishMan->currentFrameX = 0;
				break;
			case FISHMAN_LEFT:
				if (_viFishMan->currentFrameX < 0) _viFishMan->currentFrameX = 2;
				break;
			}
			break;
			//WALK ������ ���
		case FISHMAN_WALK:
			_viFishMan->img = IMAGEMANAGER->findImage("fishManWalk");
			switch (_viFishMan->direction_img)
			{
			case FISHMAN_RIGHT:
				if (_viFishMan->currentFrameX > 3)_viFishMan->currentFrameX = 0;
				break;
			case FISHMAN_LEFT:
				if (_viFishMan->currentFrameX < 0) _viFishMan->currentFrameX = 3;
				break;
			}
			break;
			//RUN ������ ���
		case FISHMAN_RUN:
			_viFishMan->img = IMAGEMANAGER->findImage("fishManRun");
			switch (_viFishMan->direction_img)
			{
			case FISHMAN_RIGHT:
				if (_viFishMan->currentFrameX > 1)_viFishMan->currentFrameX = 0;
				break;
			case FISHMAN_LEFT:
				if (_viFishMan->currentFrameX < 0) _viFishMan->currentFrameX = 1;
				break;
			}
			break;
			//ATTACK ������ ���
		case FISHMAN_ATTACK:
			_viFishMan->img = IMAGEMANAGER->findImage("fishManAttack");
			switch (_viFishMan->direction_img)
			{
			case FISHMAN_RIGHT:
				if (_viFishMan->currentFrameX > 2)
				{
					_dialogue->speechCreate(FISHMAN, _viFishMan->x - 60, _viFishMan->y - 60);

					_viFishMan->currentFrameX = 0;
				}
				break;
			case FISHMAN_LEFT:
				if (_viFishMan->currentFrameX < 0)
				{
					_dialogue->speechCreate(FISHMAN, _viFishMan->x - 60, _viFishMan->y - 60);

					_viFishMan->currentFrameX = 2;
				}
				break;
			}
			break;
			//DEATH ������ ���
		case FISHMAN_DEATH:
			_viFishMan->img = IMAGEMANAGER->findImage("fishManDie");
			switch (_viFishMan->direction_img)
			{
			case FISHMAN_RIGHT:
				if (_viFishMan->currentFrameX > 3)
				{
					_viFishMan->currentFrameX = 3;
					_viFishMan = _vFishMan.erase(_viFishMan);
				}
				break;
			case FISHMAN_LEFT:
				if (_viFishMan->currentFrameX < 0)
				{
					_viFishMan->currentFrameX = 0;
					_viFishMan = _vFishMan.erase(_viFishMan);
				}
				break;
			}
			break;
		}
	}
}
void fishMan::tileCheck()
{
	RECT rcCollision;	//������ �浹���� ��Ʈ�� �ϳ� ����


	int	tileIndex[2];	//Ÿ�� ���⿡ �ʿ��� �ε���
	int tileX, tileY;	//������ ��� �ִ� Ÿ���� �ε���
	for (_viFishMan = _vFishMan.begin(); _viFishMan != _vFishMan.end(); ++_viFishMan)
	{
		//������ ������Ʈ�� ���� ��Ʈ�� ����������
		rcCollision = _viFishMan->rc;

		rcCollision = RectMakeCenter(_viFishMan->x, _viFishMan->y, _viFishMan->img->getFrameWidth(), _viFishMan->img->getFrameHeight());

		tileX = rcCollision.left / 48;
		tileY = rcCollision.top / 48;

		switch (_viFishMan->direction)
		{
		case 4:
			tileIndex[0] = (tileX - 1) + (tileY*TILEX);
			tileIndex[1] = tileX + (tileY*TILEX);
			break;
		case 2:
			tileIndex[0] = tileX + (tileY * TILEX);
			tileIndex[1] = (tileX + 1) + (tileY * TILEX);
			break;
		case 5:
			tileIndex[0] = tileX + (tileY * TILEX);
			tileIndex[1] = (tileX + 1) + (tileY * TILEX);
			break;
		case 1:
			tileIndex[0] = tileX + tileY * TILEX;
			tileIndex[1] = tileX + (tileY + 1)*TILEX;
			break;
		case 0:
			tileIndex[0] = tileX + 1 + tileY * TILEX;
			tileIndex[1] = (tileX + 1) + (tileY + 1) * TILEX;
			break;
		case 7:
			tileIndex[0] = (tileX - 1) + (tileY * TILEX);
			tileIndex[1] = (tileX - 1) + (tileY + 1) * TILEX;
			break;
		case 3:
			tileIndex[0] = tileX + (tileY + 1) * TILEX;
			tileIndex[1] = (tileX + 1) + (tileY + 1) * TILEX;
			break;
		case 6:
			tileIndex[0] = tileX + 1 + (tileY * TILEX);
			tileIndex[1] = (tileX + 1 + (tileY + 1) * TILEX);
			break;
		}
		for (int i = 0; i < 2; ++i)
		{
			RECT rc;

			if (/*((_inGame->getTileAtt()[tileIndex[i]] == NONEMOVE)) &&*/
				IntersectRect(&rc, &_inGame->getTile()[tileIndex[i]].checkRect, &rcCollision))
			{
				switch (_viFishMan->direction)
				{
				case 1:
					_viFishMan->rc.left = _inGame->getTile()[tileIndex[i]].checkRect.right;
					_viFishMan->rc.right = _viFishMan->rc.left + _viFishMan->img->getFrameWidth();

					_viFishMan->x = (_viFishMan->rc.left + _viFishMan->rc.right) / 2;

					break;
				case 2:
					_viFishMan->rc.top = _inGame->getTile()[tileIndex[i]].checkRect.bottom;
					_viFishMan->rc.bottom = _viFishMan->rc.top + _viFishMan->img->getFrameHeight();

					_viFishMan->y = (_viFishMan->rc.top + _viFishMan->rc.bottom) / 2;
					break;
				case 0:
					_viFishMan->rc.right = _inGame->getTile()[tileIndex[i]].checkRect.left;
					_viFishMan->rc.left = _viFishMan->rc.right - _viFishMan->img->getFrameWidth();

					_viFishMan->x = (_viFishMan->rc.left + _viFishMan->rc.right) / 2;
					break;
				case 3:
					_viFishMan->rc.bottom = _inGame->getTile()[tileIndex[i]].checkRect.top;
					_viFishMan->rc.top = _viFishMan->rc.bottom - _viFishMan->img->getFrameHeight();

					_viFishMan->y = (_viFishMan->rc.top + _viFishMan->rc.bottom) / 2;
					break;
				}
			}
		}
		for (int i = 0; i < 2; ++i)
		{
			_viFishMan->tileIdx[i] = RectMake(_inGame->getTile()[tileIndex[i]].rc.left, _inGame->getTile()[tileIndex[i]].rc.top, 48, 48);
		}

		_viFishMan->rc = RectMakeCenter(_viFishMan->x, _viFishMan->y, _viFishMan->img->getFrameWidth(), _viFishMan->img->getFrameHeight());
	}
}
