#include "pch.h"
#include "Object.h"
#include "Components.h"

void Object::Initialize()
{
	Transform*	tf	= entityManager->GetEntity(_entityId)->AddComponent<Transform>();
	Sprite*		sp	= entityManager->GetEntity(_entityId)->AddComponent<Sprite>();
}
