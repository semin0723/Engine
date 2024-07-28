#include "pch.h"
#include "UIButton.h"
#include "Components.h"

void UIButton::Initialize()
{
	entityManager->GetEntity(_entityId)->AddComponent<UITransform>();
	entityManager->GetEntity(_entityId)->AddComponent<ButtonComponent>();
}
