#pragma once
#include "playerState.h"
#include "player.h"

class playerHit : public playerState
{
	
	int _blink;
	
	int _blinkTime = 0;
	int _blinkTimeEnd = 0;
	int _blinkCount = 0;

	float _jumpPower = 0.f;
	float _gravity = 50.f;

public:
	virtual playerState* inputHandle(player* player);
	virtual void update(player* player);
	virtual void enter(player* player);
	virtual void exit(player* player);


	virtual int getFrameCount() { return _count; }
	virtual int getFrameX() { return _currentFrameX; }
	virtual int getFrameY() { return _currentFrameY; }
};

