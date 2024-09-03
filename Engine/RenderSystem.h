#pragma once
#include "globalheader.h"
#include "D2DRender.h"

class RenderSystem
{
public:
	RenderSystem() {}
	~RenderSystem() {}

	void Render();

	void SpriteRender(ID2D1HwndRenderTarget* target);
	void UISpriteRender(ID2D1HwndRenderTarget* target);
	void TextRender(ID2D1HwndRenderTarget* target);

private:

};

