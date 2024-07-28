#include "pch.h"
#include "TextComponent.h"
#include "Components.h"
#include "ResourceSystem.h"

TextComponent::TextComponent() : _text(L"Text"), _font(L"Cooper"), _fontSize(15.0f)
{
}

void TextComponent::Update(float dt)
{
}

void TextComponent::Render(ID2D1HwndRenderTarget* target)
{
	UITransform* uitf = componentManager->GetComponent<UITransform>(_owner);

	uitf->_localTransform =
		D2D1::Matrix3x2F::Scale(uitf->_scale.x, uitf->_scale.y, D2D1::Point2F(_textAreaSize.x / 2.0f, _textAreaSize.y / 2.0f)) *
		D2D1::Matrix3x2F::Rotation(uitf->_rotation.z, D2D1::Point2F(_textAreaSize.x / 2.0f, _textAreaSize.y / 2.0f)) *
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

	target->DrawText(
		_text.c_str(),
		_text.size(),
		ResourceSystem::GetInstance()->GetTextFormat(_font, _fontSize, _textAlignment, _paragraphAlignemt),
		D2D1::RectF(
			0, 0,
			_textAreaSize.x, _textAreaSize.y
		),
		ResourceSystem::GetInstance()->GetBrush(BLACK)
	);
}
