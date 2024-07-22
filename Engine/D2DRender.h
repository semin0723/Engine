#pragma once
#include <d2d1.h>

class D2DRender
{
public:
	D2DRender() = default;
	~D2DRender() = default;

	bool Initialize(HWND hWnd);
	void Finalize();

	ID2D1HwndRenderTarget* GetRenderTarget() { return _d2dRenderTarget; }

private:
	ID2D1Factory* _d2dFactory = { 0 };
	ID2D1HwndRenderTarget* _d2dRenderTarget = { 0 };
};

