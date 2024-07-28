#include "pch.h"
#include "UIPannel.h"
#include "Components.h"

void UIPannel::Initialize()
{
	entityManager->GetEntity(_entityId)->AddComponent<UITransform>();

	// TODO: Add Pannel Sprite and Add UISprite Component;
}
