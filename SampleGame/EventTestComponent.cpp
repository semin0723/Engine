#include "EventTestComponent.h"

void EventTestComponent::Initialize()
{
	RegisterCallback("Input", &EventTestComponent::OnButtonDown);
}

void EventTestComponent::OnButtonDown(const KeyDown* event)
{
	float speed = 300.0f;

	Vector3 dir(0.0f, 0.0f, 0.0f);

	if (event->keyCode == 'A') {
		dir += Vector3(-1.f, 0.f, 0.f);
	}
	else if (event->keyCode == 'D') {
		dir += Vector3( 1.f, 0.f, 0.f);
	}
	else if (event->keyCode == 'W') {
		dir += Vector3(0.f, -1.f, 0.f);
	}
	else if (event->keyCode == 'S') {
		dir += Vector3(0.f,  1.f, 0.f);
	}
	Vector3 curPos = componentManager->GetComponent<Transform>(GetOwner())->GetPosition();

	Engine->SendMovePacket(GetOwner(), dir, speed, event->delta);
	//componentManager->GetComponent<Transform>(GetOwner())->SetPosition(curPos + (dir * speed * event->delta));
}
