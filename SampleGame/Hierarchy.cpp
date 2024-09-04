#include "Hierarchy.h"

//----------------------------------
//-------------- Map1 --------------
//----------------------------------

EntityId Map1() {
	EntityId map = entityManager->CreateEntity<Map>();

	EntityId	sampleObject	= entityManager->CreateEntity<Object>();
	Transform*	tf				= componentManager->GetComponent<Transform>(sampleObject);
	Sprite*		sp				= componentManager->GetComponent<Sprite>(sampleObject);

	entityManager->GetEntity(sampleObject)->SetName("Sample");

	componentManager->AddComponent<EventTestComponent>(sampleObject);

	sp->SetSpriteId(L"TestSprite");
	sp->SetSize(Vector3(40.0f, 40.0f, 0));

	tf->SetPosition(Vector3(100.0f, 100.0f, 0));

	//RigidBody* rb = componentManager->AddComponent<RigidBody>(sampleObject);



	entityManager->GetEntity(map)->AddChildEntity(sampleObject);

	entityManager->GetEntity(sampleObject)->SetParentEntity(map);

	return map;
}

EntityId UItestGroup()
{
	EntityId uipannel = entityManager->CreateEntity<UIPannel>();

	EntityId textTest = entityManager->CreateEntity<UIText>();
	UITransform* uitf = componentManager->GetComponent<UITransform>(textTest);
	TextComponent* uitc = componentManager->GetComponent<TextComponent>(textTest);

	entityManager->GetEntity(textTest)->SetName("testText");

	uitf->SetPosition(Vector3(500.0f, 500.0f, 0));
	uitc->SetTextAreaSize(Vector3(300.0f, 100.0f, 0));
	uitc->SetText(L"Test Text");
	uitc->SetTextAlignment(TEXT_CENTER);

	entityManager->GetEntity(uipannel)->AddChildEntity(textTest);

	entityManager->GetEntity(textTest)->SetParentEntity(uipannel);

	return uipannel;
}
