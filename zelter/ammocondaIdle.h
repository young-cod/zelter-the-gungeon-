#pragma once
#include "ammocondaState.h"
#include "ammoconda.h"

class ammocondaIdle : public ammocondaState
{
private:
	//���º�ȯ��
	int _changeCount;
	//�̹��� �����ӿ�
	int _count;
	//�ޱ۰� ī��Ʈ
	int _angleCount;
	

public:
	virtual ammocondaState* InputHandle(ammoconda* ammoconda);
	virtual void enter(ammoconda* ammoconda);
	virtual void update(ammoconda* ammoconda);
	virtual void render(ammoconda* ammoconda);
	virtual void exit(ammoconda* ammoconda);

};

