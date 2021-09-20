#pragma once

class image final
{
public:

	typedef struct tagImageInfo
	{
		int				width;			//�̹��� ��ü ����ũ��
		int				height;			//�̹��� ��ü ����ũ��
		int				currentFrameX;	//���� ������ ��ȣ(����)
		int				currentFrameY;	//���� ������ ��ȣ(����)
		int				maxFrameX;		//�ִ� ������ ��ȣ(����)
		int				maxFrameY;		//�ִ� ������ ��ȣ(����)
		int				frameWidth;		//1������ �� ����ũ��
		int				frameHeight;	//1������ �� ����ũ��
		float				x;
		float				y;

		tagImageInfo()
		{
			width = 0;
			height = 0;
			currentFrameX = 0;
			currentFrameY = 0;
			maxFrameX = 0;
			maxFrameY = 0;
			frameWidth = 0;
			frameHeight = 0;
			x = 0;
			y = 0;
		}
		RECT rc;
	}IMAGE_INFO, *LPIMAGE_INFO;

private:
	LPIMAGE_INFO	_imageInfo;
	CHAR*			_fileName;
		
	ID2D1Bitmap*	_bitmap;			//����� ��Ʈ��
	ID2D1Bitmap*	_backBufferBitmap;	//���� Ÿ�ٿ� ��Ʈ��
		
	float			_alpha;
	float			_scale;
	float			_angle;
	int				_count;

public:	
	image();
	~image();

	HRESULT init(ID2D1Bitmap* const bitmap);
	HRESULT init(int width, int height);
	HRESULT init(ID2D1Bitmap*const bitmap, int width, int height, bool type = false);
	HRESULT init(ID2D1Bitmap*const bitmap, int width, int height, int frameX, int frameY);

	void release();

	void render(const float x, const float y, const float scaleW = 1.f, const float scaleH = 1.f,
		const float degreeAngle = 0.f, const float rotateX = 0.f, const float rotateY = 0.f,
		const float transX = 0.f, const float transY = 0.f);
	void cutRender(const float x, const float y, const float sourX, const float sourY,
		const float sourW, const float sourH, const float alpha = 1.f, const float scaleW = 1.f, const float scaleH = 1.f,
		const float degreeAngle = 0.f, const float rotateX = 0.f, const float rotateY = 0.f,
		const float transX = 0.f, const float transY = 0.f);
	void frameRender(const float x, const float y, const int speed = 10, const bool loop = false,
		const float scaleW = 1.f, const float scaleH = 1.f,
		const float degreeAngle = 0.f, const float rotateX = 0.f, const float rotateY = 0.f,
		const float transX = 0.f, const float transY = 0.f);
	void frameRender2(const float x, const float y, const int frameX, const int frameY,
		const float scaleW = 1.f, const float scaleH = 1.f,
		const float degreeAngle = 0.f, const float rotateX = 0.f, const float rotateY = 0.f,
		const float transX = 0.f, const float transY = 0.f);
	void mainRender(const float x, const float y);
	void miniRender(const float x, const float y,const float sourX, const float sourY, const float sourW , const float sourH);
	//�߰��߽��ϴ�
	void barRender(const float X, const float Y, const float sourX);
	//===========
	/*===============================================================
							������ / ������
	===============================================================*/


	void ResetRenderOption();

	float getAlpha() { return _alpha; }
	void setAlpha(const float alpha) { _alpha = alpha; }
	void setScale(const float scale) { _scale = scale; }
	void setAngle(const float angle) { _angle = angle; }

	float getX() { return _imageInfo->x; }
	void setX(float x) { _imageInfo->x = x; }
	float getY() { return _imageInfo->y; }
	void setY(float y) { _imageInfo->y = y; }

	const int getFrameX() { return _imageInfo->currentFrameX; }
	void setFrameX(int frameX) { _imageInfo->currentFrameX = frameX; }
	const int getFrameY() { return _imageInfo->currentFrameY; }
	void setFrameY(int frameY) { _imageInfo->currentFrameY = frameY; }

	const int getMaxFrameX()const { return _imageInfo->maxFrameX; }
	const int getMaxFrameY()const { return _imageInfo->maxFrameY; }
	const UINT getWidth() const { return _bitmap->GetPixelSize().width;; }		//���� �̹��� ������ ũ�� ��������
	const UINT getHeight()const { return _bitmap->GetPixelSize().height; }		//���� �̹��� ������ ũ�� ��������
	const float getFrameWidth()const { return _imageInfo->frameWidth; }
	const float getFrameHeight()const { return _imageInfo->frameHeight; }
	Vector2 getFrameSize(const int& frame = 0) const { return Vector2(_imageInfo->frameWidth, _imageInfo->height); }
};

