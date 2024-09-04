#include "EventTestComponent.h"

void EventTestComponent::Initialize()
{
	RegisterCallback("Input", &EventTestComponent::OnButtonDown);
}

void EventTestComponent::OnButtonDown(const KeyDown* event)
{
	if (event->keyCode == 'A') {
		componentManager->GetComponent<Transform>(GetOwner())->SetPosition(Vector3(500.f, 500.f, 0));
	}
	else if (event->keyCode == 'V') {
		// 자신의 Entity이름으로 sender한다.
		Engine->SendEvent<KeyDown>(entityManager->GetEntity(GetOwner())->GetName(), 'H', event->delta);
	}
	else if (event->keyCode == 'H') {
		// 위에서 자신의 Entity이름으로 Send했는데 해당하는 함수는 Input에서만 이벤트를 받기 때문에 H를 눌렀을 때의 이벤트는 발생하지 않음.
		componentManager->GetComponent<Transform>(GetOwner())->SetPosition(Vector3(100.f, 100.f, 0));
	}
}
