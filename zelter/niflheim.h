#pragma once
#include "gameNode.h"
#include "state.h"

#include "progressBar.h"
#include "niflheimBullet.h"

#include "playerBullet.h"

class player;

struct tagNiflheim
{
	image*	img;				//���������̹���
	RECT	rc;					//��Ʈ�ڽ�
	float	x, y;				//��ǥ
	float	currentHP, maxHP;	//����hp, �ִ�hp
	int		direction;			//����
	int		inPattern;			//�����������
	int		outPattern;			//������������
	bool	isDie;				//�����Ǿ���

	niflheimIcePillar*	icePillar;	//������, �⺻�Ѿ�
	niflheimIceSpear*	iceSpear;	//����â
	niflheimIcicle*		iceicle;	//��帧
	progressBar*		progressBar;
};
enum DIRECTION
{
	RIGHT,
	LEFT
};
enum NIFLHEIMPATTERN
{
	ICICLE,
	ICESPEAR,
};
class niflheim : public gameNode
{
	player* _player;

	state*	_state;

	tagNiflheim	_niflheim;

	int _bulletFireCount;
	bool _invincibility;
	float _timeCount;
	float _timeCountEnd;

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	void inPutHandle();
	void hitNifleheim();

	void bulletUpdate();
	void bulletRender();

	void imageAdd();

	void linkPlayer(player* player) { _player = player; }
	player* getPlayer() { return _player; }

	tagNiflheim getNiflheim() { return _niflheim; }
	void setImg(image* img) { _niflheim.img = img; }

	void setX(float x) { _niflheim.x = x; }
	void setY(float y) { _niflheim.y = y; }
};

