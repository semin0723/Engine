#include "pch.h"
#include "UISprite.h"
#include "ResourceSystem.h"

void UISprite::Update(float dt)
{
}

void UISprite::Render(ID2D1HwndRenderTarget* target)
{
	UITransform* uitf = componentManager->GetComponent<UITransform>(_owner);

	uitf->_localTransform =
		D2D1::Matrix3x2F::Scale(uitf->_scale.x, uitf->_scale.y, D2D1::Point2F(_size.x / 2.0f, _size.y / 2.0f)) *
		D2D1::Matrix3x2F::Rotation(uitf->_rotation.z, D2D1::Point2F(_size.x / 2.0f, _size.y / 2.0f)) *
		D2D1::Matrix3x2F::Translation(uitf->_position.x, uitf->_position.y)
		;

	EntityId parentId = entityManager->GetEntity(_owner)->GetParentEntityId();

	if (parentId == EntityId() || componentManager->GetComponent<Transform>(parentId) == nullptr) {
		uitf->_screenTransform = uitf->_localTransform;
	}
	else {
		D2D1::Matrix3x2F parentWorldTransform = componentManager->GetComponent<Transform>(parentId)->_worldTransform;
		uitf->_screenTransform = uitf->_localTransform * parentWorldTransform;
	}

	target->SetTransform(uitf->_screenTransform);

	SpriteIdSet spSet = ResourceSystem::GetInstance()->GetSpriteSet(_spriteId)->GetSpriteIdSet();
	auto bitmap = ResourceSystem::GetInstance()->GetSprite(spSet[_startAnimationIdx]);

	D2D1_RECT_F dest = { 0, 0, _size.x, _size.y };

	target->DrawBitmap(bitmap, dest);

	_startAnimationIdx++;
	if (_startAnimationIdx == spSet.size()) _startAnimationIdx = 0;
}
