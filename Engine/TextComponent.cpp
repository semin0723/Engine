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

	target->SetTransform(uitf->_screenTransform);

	target->DrawText(
		_text.c_str(),
		_text.size(),
		ResourceSystem::GetInstance()->GetTextFormat(_font, _fontSize, _textAlignment, _paragraphAlignemt),
		D2D1::RectF(
			0, 0,
			uitf->_size.x, uitf->_size.y
		),
		ResourceSystem::GetInstance()->GetBrush(BLACK)
	);
}
