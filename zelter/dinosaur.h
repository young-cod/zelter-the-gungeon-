#pragma once
#include <vector>
#include "bulletKing.h"
#include "gameNode.h"
#include "dialogue.h"
#include "inGameMap.h"

enum DINOSAURDIRECTION
{
	DINOSAUR_RIGHT,
	DINOSAUR_LEFT
};
enum DINOSAURSTATE
{
	DINOSAUR_IDLE,
	DINOSAUR_WALK,
	DINOSAUR_RUN,
	DINOSAUR_ATTACK,
	DINOSAUR_DEATH,
};

struct tagDinosaur
{
	image* img;							//���� �̹���
	RECT rc;							//���� ��Ʈ
	float speed;						//���� �ӵ�
	float angle;						//���� ����(����)
	float x, y;							//���� x, y
	int width, height;					//���� ���� ����, ���� ����
	int currentFrameX;					//���� x�� ���� ������
	int currentFrameY;					//���� y�� ���� ������
	int maxHp, currentHp;				//���� �ִ� ü��, ���� ü��
	int count;							//�̹��� ������ ī��Ʈ
	int changeCount;					//���º�ȯ�� ī��Ʈ
	int direction;
	RECT tileIdx[2];
	DINOSAURDIRECTION direction_img;
	DINOSAURSTATE state;
};

class dinosaur : public gameNode
{
private:
	//���̾�α�
	dialogue*	_dialogue;

	//�ǽ��� ����ü
	tagDinosaur _dinosaur;

	//�ǽ��� ����
	vector<tagDinosaur> _vDinosaur;
	vector<tagDinosaur>::iterator _viDinosaur;

	//�׽�Ʈ �÷��̾�
	bulletKing* _bulletKing;

	////Ÿ�ϰ���
	inGameMap* _inGame;


public:
	dinosaur();
	~dinosaur();

	HRESULT init();
	void release();
	void update();
	void render();
	void setEnemy();
	void dinoMove(float x, float y);
	void dinoState();
	void tileCheck();

	void linkOpenWorldMap(inGameMap* map) { _inGame = map; }

	vector<tagDinosaur>& getVDinosaur() { return _vDinosaur; }
	vector<tagDinosaur>::iterator& getViDinosaur() { return _viDinosaur; }
};

