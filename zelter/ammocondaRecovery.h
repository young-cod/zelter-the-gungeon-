#pragma once
#include "ammocondaState.h"
#include "ammoconda.h"

class ammocondaRecovery : public ammocondaState
{
private:
	//���º�ȯ ī��Ʈ
	int _changeCount;
	//�̹��� �����ӿ�
	int _count;
	//�ޱ۰� ī��Ʈ
	int _angleCount;
	//���ݿ� ������
	int _attackRand;

	bool _isYum;

public:

	virtual ammocondaState* InputHandle(ammoconda* ammoconda);
	virtual void enter(ammoconda* ammoconda);
	virtual void update(ammoconda* ammoconda);
	virtual void render(ammoconda* ammoconda);
	virtual void exit(ammoconda* ammoconda);

};

