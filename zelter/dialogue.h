#pragma once
#include "gameNode.h"
#include <vector>

enum ENEMYNAME
{
	FISHMAN,
	DINOSAUR
};
struct tagSpeech
{
	image*			img;		//��ǳ�� �̹���
	RECT			rc;			//�� �� �˾Ҵµ� �Ⱦ��� ��Ʈ
	const char*		enemyName;	//int ���� �޾Ƽ� char�� �� �̸� ����
	const char*		speech;		//��� (���⿡ ��簡 ��)
	int				rndSpeech;	//������ ��縦 ���� ������
	float			x, y;		//��µ� ��ġ
	float			maxWidth;	//�� �� �˾Ҵµ� �Ⱦ��� �ִ� ���� ��
	int				speechCount;//��簡 ����� �ð� ī��Ʈ��
	int				speechEnd;	//�� ������ count���� Ŀ���� ���Ϳ� �� ��� ������
};
class dialogue : public gameNode
{
	vector<tagSpeech>		_vSpeech;	//speechCreate���� ��簡 �����Ǹ� ���Ϳ� ���� ����

public :
	virtual HRESULT init();
	virtual void release(int index);
	virtual void update();
	virtual void render();

	void speechCreate(int enemyName, float x, float y);

};

