#pragma once
#include "globalheader.h"
#include "D2DRender.h"

class RenderSystem
{
public:
	RenderSystem() {}
	~RenderSystem() {}

	void Render(ID2D1HwndRenderTarget* target);

private:

};

