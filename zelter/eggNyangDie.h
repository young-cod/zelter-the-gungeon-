#pragma once
#include "eggNyangStateBase.h"

#define MAXEFFECT 5
class eggNyang;

struct tagBoom
{
	image* img;					//�̹���
	float x, y;						//��ǥ
	int effectFrameX;				//����Ʈ ������
	bool playeEffectEnd;			//����Ʈ ����� ��������
};
class eggNyangDie : public eggNyangStateBase
{
	vector<tagBoom> _vBoom;

	int _effectFrameCount;			//����Ʈ ������
	int _playEffectNum;				//����Ʈ ����� Ƚ��
	int _randomEffect;				//����Ʈ �������� ��
	int	_countEffect;
public :
	virtual eggNyangStateBase* inputHandle(eggNyang* eggNyang);
	virtual void update(eggNyang* eggNyang);
	virtual void enter(eggNyang* eggNyang);
	virtual void render(eggNyang* eggNyang);
	virtual void exit(eggNyang* eggNyang);

	void produceEffect(eggNyang* eggNyang);
	void playEffect(eggNyang* eggNyang);
};

