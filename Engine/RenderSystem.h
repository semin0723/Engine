#pragma once
#include "globalheader.h"
#include "D2DRender.h"

class RenderSystem
{
public:
	RenderSystem() {}
	~RenderSystem() {}

	void SpriteRender(ID2D1HwndRenderTarget* target, EntityId eid);
	void UIRender(ID2D1HwndRenderTarget* target, EntityId eid);


private:
	std::vector<ComponentId> _spriteComponents;
};

