#include "pch.h"
#include "UISprite.h"
#include "ResourceSystem.h"

void UISprite::Update(float dt)
{
}

void UISprite::Render(ID2D1HwndRenderTarget* target)
{
	UITransform* tf = componentManager->GetComponent<UITransform>(_owner);

	target->SetTransform(tf->_screenTransform);

	SpriteIdSet spSet = ResourceSystem::GetInstance()->GetSpriteSet(_spriteId)->GetSpriteIdSet();
	auto bitmap = ResourceSystem::GetInstance()->GetSprite(spSet[_startAnimationIdx]);

	D2D1_RECT_F dest = { 0, 0, _size.x, _size.y };

	target->DrawBitmap(bitmap, dest);

	_startAnimationIdx++;
	if (_startAnimationIdx == spSet.size()) _startAnimationIdx = 0;
}
