#include "stdafx.h"
#include "loading.h"

loading::loading()
{
}

loading::~loading()
{
}

HRESULT loading::init()
{
	IMAGEMANAGER->addFrameImage("����̷ε�", L"UI/�����_11.png", 11, 1);
	_loadingImage = IMAGEMANAGER->findImage("����̷ε�");
	_currentFrameX = _count = 0;
	_loadingTextCount = 0;
	_loadingText = "L O A D I N G . . . . . .";
	_loadingRect = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, WINSIZEX, WINSIZEY);


	CreateThread(
		NULL,			//�������� ���ȼӼ�(�ڽ������찡 �����Ҷ�)
		NULL,			//�������� ����ũ��(NULL�� �θ� ���ξ�����)
		threadFunction,	//����� �Լ�
		this,			//������ �Ű�����(this�� ������ �� Ŭ����)
		NULL,			//������ Ư��(��ٸ��� �ٷν�������(NULL))
		NULL			//������ ���� �� �������� ID �Ѱ���
	);

	return S_OK;
}

void loading::release()
{
}

void loading::update()
{
	_count++;
	if (_count % 10 == 0) 
	{
		_currentFrameX++;
		_loadingTextCount++;
		if (_currentFrameX >= 10) _currentFrameX = 0;
	}
	strncpy_s(_loadingTextCut, sizeof(_loadingTextCut), _loadingText, _loadingTextCount * 2);
	
	if (_loadingTextCount >= strlen(_loadingText)) _loadingTextCount = 0;

	//�ε� �� �� ����
	if (_currentCount == LOADINGMAX)
	{
		SCENEMANAGER->changeScene("openWorld");
	}
}

void loading::render()
{
	D2DRENDER->FillRectangle(_loadingRect, D2DDEFAULTBRUSH::Black);
	_loadingImage->frameRender2(WINSIZEX / 2 - _loadingImage->getFrameWidth() / 2, WINSIZEY / 2 - _loadingImage->getFrameHeight() / 2, _currentFrameX, 0);
	D2DRENDER->RenderTextField(WINSIZEX / 2 - 100, WINSIZEY / 2 + 100, ConvertCtoWC(_loadingTextCut), D2D1::ColorF::White, 25, 500, 200, 1);
}

DWORD CALLBACK threadFunction(LPVOID lpParameter)
{
	loading* loadingHelper = (loading*)lpParameter;


	while (loadingHelper->_currentCount != LOADINGMAX)
	{
		Sleep(1);

		loadingHelper->_currentCount++;

	}

	return 0;
}
