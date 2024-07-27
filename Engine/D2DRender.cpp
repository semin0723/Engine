#include "../../pch.h"
#include "D2DRender.h"

bool D2DRender::Initialize(HWND hWnd)
{
	HRESULT result = S_OK;

	result = CoInitialize(nullptr);
	if (FAILED(result)) return false;

	result = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &_d2dFactory);
	if (FAILED(result)) return false;

	RECT clientRect;
	GetClientRect(hWnd, &clientRect);

	D2D1_SIZE_U size = D2D1::SizeU(
		clientRect.right - clientRect.left,
		clientRect.bottom - clientRect.top
	);

	result = _d2dFactory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(hWnd, size),
		&_d2dRenderTarget
	);
	if (FAILED(result)) return false;

	return true;
}

void D2DRender::Finalize()
{
	if (_d2dRenderTarget) _d2dRenderTarget->Release();
	if (_d2dFactory) _d2dFactory->Release();

	CoUninitialize();
}
