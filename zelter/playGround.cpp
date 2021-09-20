#include "stdafx.h"
#include "playGround.h"

#pragma comment(linker,"/entry:WinMainCRTStartup /subsystem:console")


playGround::playGround()
{

}


playGround::~playGround()
{
}

//�ʱ�ȭ �Լ�
HRESULT playGround::init()
{
	gameNode::init(true);

	_stageManager = new stageManager;
	_stageManager->init();


	return S_OK;
}

//�޸� ����
void playGround::release()
{

}

//����
void playGround::update()
{
	gameNode::update();

	
	_stageManager->update();

}

//�׸��� ����
void playGround::render()
{
	//����� �ʱ�ȭ
	D2DRENDER->BeginRender(D2D1::ColorF::White);


	_stageManager->render();
	CAMERAMANAGER->render();
	TIMEMANAGER->render(_hdc);

	//����ۿ� �׸� ������� ȭ�鿡 �ѷ���~
	D2DRENDER->EndRender();
}
