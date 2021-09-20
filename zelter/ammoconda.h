#pragma once
#include "gameNode.h"
#include "ammocondaState.h"
#include "ammocondaBullet.h"
#include "progressBar.h"
#include "playerBullet.h"

#define AMMOCONDAMAX 11
#define PIDIVISION8		float(PI / 8.0f)

class player;

enum POTSTATE
{
	POT_IDLE,
	POT_ATTACK,
	POT_DEATH
};

struct tagAmmoconda
{
	image* img;							//�Ƹ��ܴ� �̹���
	RECT rc;							//�Ƹ��ܴ� ��Ʈ
	float speed;						//�Ƹ��ܴ� �ӵ�
	float angle;						//�Ƹ��ܴ� ����(����)
	float radius;						//�Ƹ��ܴ� ������
	float x, y;							//�Ƹ��ܴ� x, y
	int width, height;					//�Ƹ��ܴ� ���� ����, ���� ����
	int differenceHeight;				//�Ƹ��ܴ� �����Ӻ� ���� ���� ����
	int currentFrameX;					//�Ƹ��ܴ� x�� ���� ������
	int currentFrameY;					//�Ƹ��ܴ� y�� ���� ������
	int maxHp, currentHp;				//�Ƹ��ܴ� �ִ� ü��, ���� ü��
	bool isAttack;						//�Ƹ��ܴ� ���ݿ���
	int count;							//������ī��Ʈ
	int attackCount;					//���� ī��Ʈ
	POTSTATE state;						//�׾Ƹ��� enum��(����)
};

class ammoconda : public gameNode
{
private:
	//�Ƹ��ܴ� ����ü
	tagAmmoconda _ammoconda[AMMOCONDAMAX];
	int _currentHp, _maxHp;
	//�Ƹ��ܴ� �Ѿ�
	ammocondaBullet* _ammocondaBullet;

	//ü��
	progressBar* _hp;
	image* _bulletKing_hp;

	//�Ƹ��ܴ� ��������
	ammocondaState* _state;

	//z-oder�� ����
	vector<tagAmmoconda*>				_vAmmoconda;
	vector<tagAmmoconda*>::iterator		_viAmmoconda;

	//�׾Ƹ� ����ü
	tagAmmoconda _pot;

	//�׾Ƹ� ���忩��
	bool _isPotCreate;
	int _potCount;


	player* _player;

public:
	ammoconda();
	~ammoconda();

	HRESULT init();
	void release();
	void update();
	void render();
	void InputHandle();
	void setBoss();
	void bossMove(int count, int division, string keyValue);
	void bossRecoveryMove(int count, int division, string keyValue, float x, float y, float playerX, float playerY);
	void setPot(int x, int y);
	void potMove();
	void potState();
	void potRender();
	void collision();


	//�Ƹ��ܴ� ������
	tagAmmoconda& getAmmoconda(int index) { return _ammoconda[index]; }

	//�׾Ƹ� ������
	tagAmmoconda& getPot() { return _pot; }
	bool getIsPotCreate() { return _isPotCreate; }

	
	int getCurrentHp() { return _currentHp; }

	//�Ѿ� get
	ammocondaBullet* getBAmmocondaBullet() { return _ammocondaBullet; }

	void linkPlayer(player* player) { _player = player; }

	player* getPlayer() { return _player; }
};

