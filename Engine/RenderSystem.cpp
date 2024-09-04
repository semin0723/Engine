#include "pch.h"
#include "RenderSystem.h"
#include "ResourceSystem.h"

void RenderSystem::SpriteRender(ID2D1HwndRenderTarget* target, EntityId eid)
{
	Transform*	tf	= componentManager->GetComponent<Transform>(eid);
	Sprite*		sp	= componentManager->GetComponent<Sprite>(eid);

	// TODO: Add Camera and mul inverse matrix to transform
	target->SetTransform(tf->GetWorldTransform());

	SpriteIdSet spSet = ResourceSystem::GetInstance()->GetSpriteSet(sp->_spriteId)->GetSpriteIdSet();
	auto bitmap = ResourceSystem::GetInstance()->GetSprite(spSet[sp->_curAnimationIdx]);

	D2D1_RECT_F dest = { 0, 0, sp->_size.x, sp->_size.y };

	target->DrawBitmap(bitmap, dest);
}

void RenderSystem::UIRender(ID2D1HwndRenderTarget* target, EntityId eid)
{

}

