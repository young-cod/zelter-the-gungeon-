#pragma once
#include "gameNode.h"
#include <vector>

class eggNyang;


class eggNyangStateBase : public gameNode
{
	
protected:
	eggNyang*	_eggNyang;

	string	_stateName;							//�����̸�

	int		_count;								//������ī��Ʈ
	int		_currentFrameX, _currentFrameY;		//������ �迭 x,yī��Ʈ
	int		_randomPatternCount;				//���� ���� ī��Ʈ
	bool	_stateEnd;							//���°� ������
	float	_angle;								//�̵��ҽ� �ޱ�
	bool	_isMove;							//�̵��϶�� ��ȣ �Լ�

public:
	virtual eggNyangStateBase* inputHandle(eggNyang* eggNyang) = 0;
	virtual void update(eggNyang* eggNyang) = 0;
	virtual void enter(eggNyang* eggNyang) = 0;
	virtual void exit(eggNyang* eggNyang) = 0;
	virtual void render(eggNyang* eggNyang) = 0;

	string getStateName() { return _stateName; }
	float getAngle() { return _angle; }
	bool getIsMove() { return _isMove; }
};

