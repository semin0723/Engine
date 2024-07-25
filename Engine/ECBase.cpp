#include "pch.h"
#include "ECBase.h"
#include "GameElements.h"
#include "ResourceSystem.h"

ECBase::ECBase()
{
	_eventHandler = new EventHandler;
	_componentManager = new ComponentManager;
	_entityManager = new EntityManager(_componentManager);

	CreateWorldEntity();

	ResourceSystem::GetInstance()->LoadSpriteData();
}

ECBase::~ECBase()
{
	delete _entityManager;
	_entityManager = nullptr;

	delete _componentManager;
	_componentManager = nullptr;

	delete _eventHandler;
	_eventHandler = nullptr;
}

void ECBase::Initialize()
{
	Initialize(_worldEntity);
}

void ECBase::Begin()
{
	Begin(_worldEntity);
}

void ECBase::FixedUpdate()
{
	FixedUpdate(_worldEntity);
}

void ECBase::Update(float dt)
{
	Update(_worldEntity, dt);
	_eventHandler->DispatchEvents();
	_entityManager->RemoveDestroyEntities();
	_eventHandler->DispatchEvents();
}

void ECBase::End()
{
	End(_worldEntity);
}

void ECBase::Render(ID2D1HwndRenderTarget* target)
{
	Render(target, _worldEntity);
}

void ECBase::AddMapEntity(EntityId mapId)
{
	_entityManager->GetEntity(_worldEntity)->AddChildEntity(mapId);
	_entityManager->GetEntity(mapId)->SetParentEntity(_worldEntity);
}

void ECBase::CreateWorldEntity()
{
	_worldEntity = _entityManager->CreateEntity<World>();
}

void ECBase::Initialize(EntityId id)
{
	std::vector<ComponentId> cids = _componentManager->GetMappingTable()[id._index];
	for (int i = 0; i < cids.size(); i++) {
		if (cids[i] == INVALID_COMPONENT_ID) continue;
		_componentManager->GetComponent(cids[i])->OnInitialize();
	}

	ChildEntities child = _entityManager->GetEntity(id)->GetChildEntityId();
	for (auto& i : child) {
		Initialize(i);
	}
}

void ECBase::Begin(EntityId id)
{
	std::vector<ComponentId> cids = _componentManager->GetMappingTable()[id._index];
	for (int i = 0; i < cids.size(); i++) {
		if (cids[i] == INVALID_COMPONENT_ID) continue;
		_componentManager->GetComponent(cids[i])->OnBegin();
	}

	ChildEntities child = _entityManager->GetEntity(id)->GetChildEntityId();
	for (auto& i : child) {
		Begin(i);
	}
}

void ECBase::FixedUpdate(EntityId id)
{
	std::vector<ComponentId> cids = _componentManager->GetMappingTable()[id._index];
	for (int i = 0; i < cids.size(); i++) {
		if (cids[i] == INVALID_COMPONENT_ID) continue;
		_componentManager->GetComponent(cids[i])->OnFixedUpdate();
	}

	ChildEntities child = _entityManager->GetEntity(id)->GetChildEntityId();
	for (auto& i : child) {
		FixedUpdate(i);
	}
}

void ECBase::Update(EntityId id, float dt)
{
	std::vector<ComponentId> cids = _componentManager->GetMappingTable()[id._index];
	for (int i = 0; i < cids.size(); i++) {
		if (cids[i] == INVALID_COMPONENT_ID) continue;
		if (i == Sprite::COMPONENT_TYPE_ID) continue;
		_componentManager->GetComponent(cids[i])->OnUpdate(dt);
	}

	ChildEntities child = _entityManager->GetEntity(id)->GetChildEntityId();
	for (auto& i : child) {
		Update(i, dt);
	}
}

void ECBase::Render(ID2D1HwndRenderTarget* target, EntityId id)
{
	ComponentId spriteComponent = _componentManager->GetMappingTable()[id._index][Sprite::COMPONENT_TYPE_ID];
	if (spriteComponent != INVALID_COMPONENT_ID) {
		static_cast<Sprite*>(_componentManager->GetComponent(spriteComponent))->Render(target);
	}

	ChildEntities child = _entityManager->GetEntity(id)->GetChildEntityId();
	for (auto& i : child) {
		Render(target, i);
	}
}
