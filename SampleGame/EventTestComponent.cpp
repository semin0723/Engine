#include "EventTestComponent.h"

void EventTestComponent::Initialize()
{
	entityManager->GetEntity(GetOwner())->RegisterCallback("Input", &EventTestComponent::OnButtonDown);
}

void EventTestComponent::OnButtonDown(const KeyDown* event)
{
	if (event->keyCode == 'a') {
		componentManager->GetComponent<Transform>(GetOwner())->SetPosition(Vector3(500.f, 500.f, 0));
	}
}
