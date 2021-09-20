#pragma once

#define PI 3.141592f
#define PI2 PI*2

#define RECT_WIDTH(rc) static_cast<float>(rc.right - rc.left)
#define RECT_HEIGHT(rc) static_cast<float>(rc.bottom - rc.top)
#define RECT_CENTER_X(rc) static_cast<float>((rc.left + rc.right) * 0.5f)
#define RECT_CENTER_Y(rc) static_cast<float>((rc.top + rc.bottom) * 0.5f)

namespace UJN_UTIL
{
	//�Ÿ��������� �Լ�
	float GetDistance(float startX, float startY, float endX, float endY);

	float GetAngle(float x1, float y1, float x2, float y2);

	
	//�簢�� ����ü
	typedef struct tagENEMYRECT
	{
		float left;
		float top;
		float right;
		float bottom;

		tagENEMYRECT() : left(0.0f), top(0.0f), right(0.0f), bottom(0.0f) {}
		tagENEMYRECT(float _left, float _top, float _right, float _bottom) :
			left(_left), top(_top), right(_right), bottom(_bottom) {}

		void Move(float dx, float dy)
		{
			left += dx;
			right += dx;
			top += dy;
			bottom += dy;
		}

		void Set(float _left, float _top, float _right, float _bottom)
		{
			left = _left;
			top = _top;
			right = _right;
			bottom = _bottom;
		}

		//����Ʈ ž���� ����
		void SetLeftTopPos(float _left, float _top)
		{
			float width = getWidth();
			float height = getHeight();

			left = _left;
			top = _top;
			right = _left + width;
			bottom = _top + height;
		}

		void SetCenterPos(float centerX, float centerY)
		{
			float halfW = getWidth() * 0.5f;
			float halfH = getHeight() * 0.5f;

			left = centerX - halfW;
			top = centerY - halfH;
			right = centerX + halfW;
			bottom = centerY + halfH;
		}

		float getWidth(void) { return right - left; }
		float getHeight(void) { return bottom - top; }
	}ENEMYRECT, * LPENEMYRECT;

	//�簢���� �簢���� �浹�ߴ�?
	bool IsCollision(const RECT& rc1, const ENEMYRECT& rc2);
	bool IsCollision(const RECT& rc1, const RECT& rc2);

	//wchar_t ���� char ���� ����ȯ �Լ�
	char * ConvertWCtoC(wchar_t * str);
	const char * ConvertWCtoC(const wchar_t * str);
	//char ���� wchar_t ���� ����ȯ �Լ�
	wchar_t *ConvertCtoWC(char * str);
	const wchar_t *ConvertCtoWC(const char * str);
	//stirng ���� wstring ���� �� ��ȯ �Լ�
	wstring ConvertStoWS(string str);
	string ConvertWStoS(wstring w_str);

	// OBB�浹
	// ���������� ������ִ� �� SHAPE �� OBB�Դϴ�.
	// interSectRect�� ���� rect�� ������ִ� ��ó�� SHAPE�� �����
	// OBB�� üũ�ϸ� �˴ϴ�.
	typedef struct VECTOR
	{
		double x, y;
	};

	typedef struct SHAPE //ȸ���浹::������ ���
	{
		double left, top, width, height, degreeAngle;
	};

	VECTOR addVector(VECTOR& a, VECTOR& b);
	float absDotVector(VECTOR& a, VECTOR& b);
	float degreeToRadian(float degreeAngle);
	float radianToDegree(float radianAngle);
	VECTOR getDistanceVector(SHAPE& a, SHAPE& b);
	VECTOR getHeightVector(SHAPE& a);
	VECTOR getWidthVector(SHAPE& a);
	VECTOR getUnitVector(VECTOR& a);
	bool OBB(SHAPE& a, SHAPE& b); //ȸ���浹::������ ���
}