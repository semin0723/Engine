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
		// �ڽ��� Entity�̸����� sender�Ѵ�.
		Engine->SendEvent<KeyDown>(entityManager->GetEntity(GetOwner())->GetName(), 'H', event->delta);
	}
	else if (event->keyCode == 'H') {
		// ������ �ڽ��� Entity�̸����� Send�ߴµ� �ش��ϴ� �Լ��� Input������ �̺�Ʈ�� �ޱ� ������ H�� ������ ���� �̺�Ʈ�� �߻����� ����.
		componentManager->GetComponent<Transform>(GetOwner())->SetPosition(Vector3(100.f, 100.f, 0));
	}
}
