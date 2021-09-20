#include "stdafx.h"
#include "bulletKing.h"
#include "player.h"

bulletKing::bulletKing()
{
}

bulletKing::~bulletKing()
{
}

HRESULT bulletKing::init()
{
	//�������� �Ҵ�
	_state = new bulletKingIdle();
	_state->enter(this);

	//�Ѿ� �Ҵ�
	_bullet = new bulletKingBullet;

	//hp �Ҵ�
	_hp = new progressBar;
	_hp->init(650, WINSIZEY - 100, 600, 50);
	//���� �ʱ�ȭ
	setBoss();


	return S_OK;
}

void bulletKing::release()
{
}

void bulletKing::update()
{
	collision();
	//��������
	InputHandle();
	_state->update(this);
	//hp
	_hp->update();
	_hp->setGauge(_bulletKing.currentHp, _bulletKing.maxHp);
	if (_bulletKing.currentHp <= 3) _bulletKing.currentHp = 3;


	//��ü ��Ʈ
	_bulletKing.rc = RectMakeCenter(_bulletKing.x, _bulletKing.y, _bulletKing.img->getWidth() / _bulletKing.img->getMaxFrameX(), _bulletKing.img->getHeight());
	_bulletKingChair.rc = RectMakeCenter(_bulletKingChair.x, _bulletKingChair.y, _bulletKingChair.img->getWidth() / _bulletKingChair.img->getMaxFrameX(), _bulletKingChair.img->getHeight());

	//�Ѿ� ������
	_bullet->update();


	//���� �̵� ����ó��
	if (_bulletKingChair.rc.left <= 0)
	{
		_bulletKingChair.x = _bulletKingChair.width / 2;
		_bulletKing.x = _bulletKingChair.width / 2;
	}
	if (_bulletKingChair.rc.right >= WINSIZEX)
	{
		_bulletKingChair.x = WINSIZEX - _bulletKingChair.width / 2;
		_bulletKing.x = WINSIZEX - _bulletKingChair.width / 2;
	}
	if (_bulletKingChair.rc.top <= 0)
	{
		_bulletKingChair.y = _bulletKingChair.height / 2;
		_bulletKing.y = _bulletKingChair.height / 2;
	}
	if (_bulletKingChair.rc.bottom >= WINSIZEY)
	{
		_bulletKingChair.y = WINSIZEY - _bulletKingChair.height / 2;
		_bulletKing.y = WINSIZEY - _bulletKingChair.height / 2;
	}
}

void bulletKing::render()
{
	_hp->render();
	//�������� ����
	
	_bullet->render();

	//��ü, ���� ����(3���� ���� �� ���� �����)
	if (!_bulletKingChair.isAttack3) _bulletKingChair.img->
		frameRender2(
			_bulletKingChair.rc.left ,
			_bulletKingChair.rc.top ,
			_bulletKingChair.currentFrameX, 0);
	_bulletKing.img->
		frameRender2(
			_bulletKing.rc.left,
			_bulletKing.rc.top ,
			_bulletKing.currentFrameX, 0);

	
	//���ʱ� Ȯ��
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		D2DRENDER->DrawRectangle(_bulletKing.rc, D2DRenderer::DefaultBrush::White);
		D2DRENDER->DrawRectangle(_bulletKingChair.rc, D2DRenderer::DefaultBrush::White);
	}

	_state->render(this);
}

void bulletKing::InputHandle()
{
	bulletKingState* newState = _state->InputHandle(this);
	if (newState != nullptr)
	{
		SAFE_DELETE(_state);
		_state = newState;
		_state->enter(this);
	}
}

void bulletKing::setBoss()
{
	IMAGEMANAGER->addFrameImage("bulletKingChair", L"bulletKing/bulletKing_chair_71_80_2.png", 2, 1);
	IMAGEMANAGER->addFrameImage("bulletKingIdle", L"bulletKing/bulletKing_walk_36_40_2.png", 2, 1);
	IMAGEMANAGER->addFrameImage("bulletKingAttack1", L"bulletKing/bulletKing_attack1_36_40_2.png", 2, 1);
	IMAGEMANAGER->addFrameImage("bulletKingAttack2", L"bulletKing/bulletKing_attack2_36_40_2.png", 2, 1);
	IMAGEMANAGER->addFrameImage("bulletKingAttack3", L"bulletKing/bulletKing_attack3_60_72_2.png", 2, 1);
	IMAGEMANAGER->addFrameImage("bulletKingHit", L"bulletKing/bulletKing_hit_36_40_2.png", 2, 1);
	IMAGEMANAGER->addFrameImage("bulletKingDeath", L"bulletKing/bulletKing_death_36_40_8.png", 8, 1);

	IMAGEMANAGER->addImage("bulletKingBullet1", L"bulletKing/bullet1_16_16.png");
	IMAGEMANAGER->addFrameImage("bulletKingBullet2", L"bulletKing/bullet2_23_12_8.png", 8, 1);
	IMAGEMANAGER->addImage("bulletKingBullet3", L"bulletKing/bullet1_16_16.png");
	//ȿ�� �̹���
	IMAGEMANAGER->addFrameImage("boom", L"effect/boom.png", 4, 1);
	//��źŷ ��ü �ʱ�ȭ
	_bulletKing.img = IMAGEMANAGER->findImage("bulletKingIdle");
	_bulletKing.x = WINSIZEX / 2;
	_bulletKing.y = WINSIZEY / 2 - 100;
	_bulletKing.width = 36;
	_bulletKing.height = 40;
	_bulletKing.speed = 2.0f;
	_bulletKing.angle = PI / 2;
	_bulletKing.maxHp = _bulletKing.currentHp = 1000;
	_bulletKing.currentFrameX = 0;
	_bulletKing.rc = RectMakeCenter(_bulletKing.x, _bulletKing.y, _bulletKing.img->getWidth() / _bulletKing.img->getMaxFrameX(), _bulletKing.img->getHeight());

	//��źŷ ���� �ʱ�ȭ
	_bulletKingChair.img = IMAGEMANAGER->findImage("bulletKingChair");
	_bulletKingChair.x = WINSIZEX / 2;
	_bulletKingChair.y = WINSIZEY / 2 - 100;
	_bulletKingChair.width = 71;
	_bulletKingChair.height = 80;
	_bulletKingChair.speed = 2.0f;
	_bulletKingChair.currentFrameX = 0;
	_bulletKingChair.rc = RectMakeCenter(_bulletKingChair.x, _bulletKingChair.y, _bulletKingChair.img->getWidth() / _bulletKingChair.img->getMaxFrameX(), _bulletKingChair.img->getHeight());

}

void bulletKing::collision()
{
	if (_bulletKing.currentHp > 3)
	{
		for (int i = 0; i < _player->getPlayerBullet()->getVBulletN().size(); ++i)
		{
			if (IsCollision(_bulletKing.rc, _player->getPlayerBullet()->getVBulletN()[i].rc))
			{
				_bulletKing.currentHp--;
				_player->getPlayerBullet()->releaseBullet(i);
			}
		}
		for (int i = 0; i < _player->getPlayerBullet()->getVBulletF().size(); ++i)
		{
			if (IsCollision(_bulletKing.rc, _player->getPlayerBullet()->getVBulletF()[i].rc))
			{
				_bulletKing.currentHp--;
				_player->getPlayerBullet()->releaseF(i);
			}
		}
		for (int i = 0; i < _player->getPlayerBullet()->getvGrenadeBullet().size(); ++i)
		{
			if (IsCollision(_bulletKing.rc, _player->getPlayerBullet()->getvGrenadeBullet()[i].rc))
			{
				_bulletKing.currentHp--;
				_player->getPlayerBullet()->releaseGrenadeBullet(i);
			}
		}
		for (int i = 0; i < _player->getPlayerBullet()->getVBulletH().size(); ++i)
		{
			if (IsCollision(_bulletKing.rc, _player->getPlayerBullet()->getVBulletH()[i].rc))
			{
				_bulletKing.currentHp--;
				_player->getPlayerBullet()->releaseH(i);
			}
		}
		for (int i = 0; i < _player->getPlayerBullet()->getVBulletS().size(); ++i)
		{
			if (IsCollision(_bulletKing.rc, _player->getPlayerBullet()->getVBulletS()[i].rc))
			{
				_bulletKing.currentHp--;
				_player->getPlayerBullet()->releaseS(i);
			}
		}
	}


}

