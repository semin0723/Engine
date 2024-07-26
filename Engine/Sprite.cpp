#include "pch.h"
#include "Sprite.h"
#include "Transform.h"
#include "ResourceSystem.h"
#include "d2d1_1helper.h"

void Sprite::Update(float dt)
{
}

void Sprite::Render(ID2D1HwndRenderTarget* target)
{
	Transform* tf = componentManager->GetComponent<Transform>(_owner);
	
	// TODO: Add Camera and mul inverse matrix to transform
	target->SetTransform(tf->_worldTransform);

	SpriteIdSet spSet = ResourceSystem::GetInstance()->GetSpriteSet(_spriteId)->GetSpriteIdSet();
	auto bitmap = ResourceSystem::GetInstance()->GetSprite(spSet[_startAnimationIdx]);

	D2D1_RECT_F dest = { 0, 0, _size.x, _size.y };

	target->DrawBitmap(bitmap, dest);

	_startAnimationIdx++;
	if (_startAnimationIdx == spSet.size()) _startAnimationIdx = 0;
}
