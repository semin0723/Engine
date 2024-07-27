#include "../Engine/GameElements.h"
#include "Hierarchy.h"

//----------------------------------
//-------------- Map1 --------------
//----------------------------------

EntityId Map1() {
	EntityId map = entityManager->CreateEntity<Map>();

	EntityId sampleObject = entityManager->CreateEntity<Object>();
	Transform* tf = componentManager->GetComponent<Transform>(sampleObject);
	Sprite* sp = componentManager->GetComponent<Sprite>(sampleObject);

	sp->_spriteId = L"TestSprite";
	sp->_size = Vector3(40.0f, 40.0f, 0);

	tf->_position = Vector3(100.0f, 100.0f, 0);

	RigidBody* rb = componentManager->AddComponent<RigidBody>(sampleObject);



	entityManager->GetEntity(map)->AddChildEntity(sampleObject);

	entityManager->GetEntity(sampleObject)->SetParentEntity(map);

	return map;
}