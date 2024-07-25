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
	D2D1::Matrix3x2F transform =
		D2D1::Matrix3x2F::Scale(tf->_scale.x, tf->_scale.y, D2D1::Point2F(_size.x / 2.0f, _size.y / 2.0f)) *
		D2D1::Matrix3x2F::Rotation(tf->_rotation.z, D2D1::Point2F(_size.x / 2.0f, _size.y / 2.0f)) *
		D2D1::Matrix3x2F::Translation(tf->_worldPosition.x, tf->_worldPosition.x)
		;
	// TODO: Add Camera and mul inverse matrix to transform
	target->SetTransform(transform);

	SpriteIdSet spSet = ResourceSystem::GetInstance()->GetSpriteSet(_spriteId)->GetSpriteIdSet();
	auto bitmap = ResourceSystem::GetInstance()->GetSprite(spSet[_startAnimationIdx]);

	D2D1_RECT_F dest = { 0, 0, _size.x, _size.y };

	target->DrawBitmap(bitmap, dest);
}
