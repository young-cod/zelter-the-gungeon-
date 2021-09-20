#pragma once
#include "gameNode.h"

class niflheim;

class state : public gameNode
{

protected:
	niflheim*	_niflheim;

	string	_currentStateName;					//�����̸�

	int		_count;								//������ī��Ʈ
	int		_currentFrameX, _currentFrameY;		//������ �迭 x,yī��Ʈ
	int		_randomPatternCount;				//���� ���� ī��Ʈ
	bool	_stateEnd;							//���°� ������
	float	_angle;								//�̵��ҽ� �ޱ�
	bool	_isEnter;							//�̵��϶�� ��ȣ �Լ�

public :
	virtual state* inputHandle(niflheim* eggNyang) = 0;
	virtual void update(niflheim* eggNyang) = 0;
	virtual void enter(niflheim* eggNyang) = 0;
	virtual void exit(niflheim* eggNyang) = 0;
	virtual void render(niflheim* eggNyang) = 0;

	string getStateNamge() { return _currentStateName; }
	bool getEnter() { return _isEnter; }
};

