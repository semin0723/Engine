#include "pch.h"
#include "UIText.h"
#include "Components.h"

void UIText::Initialize()
{
	entityManager->GetEntity(_entityId)->AddComponent<UITransform>();
	entityManager->GetEntity(_entityId)->AddComponent<TextComponent>();

}
