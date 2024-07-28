#include "pch.h"
#include "Object.h"
#include "Components.h"

void Object::Initialize()
{
	entityManager->GetEntity(_entityId)->AddComponent<Transform>();
	entityManager->GetEntity(_entityId)->AddComponent<Sprite>();
}
