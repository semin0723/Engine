#include "pch.h"
#include "ECBase.h"
#include "GameElements.h"
#include "ResourceSystem.h"
#include "FunctionTimer.h"

ECBase::ECBase()
{
	_eventHandler = new EventHandler;
	_componentManager = new ComponentManager;
	_entityManager = new EntityManager(_componentManager);
	_renderSystem = new RenderSystem;

	CreateWorldEntity();
	CreateBaseUIEntity();

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

	delete _renderSystem;
	_renderSystem = nullptr;
}

void ECBase::Initialize()
{
	// TODO: 여기서 현재 위치한 map의 Entity들을 전부 초기화 해야합니다.
	//Initialize(_worldEntity);
	Initialize(entityManager->GetEntity(_worldEntity)->GetChildEntityId()[_curMapIdx]);
	Initialize(_baseUIEntity);
}

void ECBase::Begin()
{
	//Begin(_worldEntity);
	Begin(entityManager->GetEntity(_worldEntity)->GetChildEntityId()[_curMapIdx]);
	Begin(_baseUIEntity);
}

void ECBase::FixedUpdate()
{
	//FixedUpdate(_worldEntity);
	FixedUpdate(entityManager->GetEntity(_worldEntity)->GetChildEntityId()[_curMapIdx]);
}

void ECBase::Update(float dt)
{
	//Update(_worldEntity, dt);
	Update(entityManager->GetEntity(_worldEntity)->GetChildEntityId()[_curMapIdx], dt);
	Update(_baseUIEntity, dt);

	FunctionTimer::GetInstance()->Update(dt);

	_eventHandler->DispatchEvents();
	_entityManager->RemoveDestroyEntities();
	_eventHandler->DispatchEvents();
}

void ECBase::End()
{
	//End(_worldEntity);
	End(entityManager->GetEntity(_worldEntity)->GetChildEntityId()[_curMapIdx]);
	End(_baseUIEntity);
}

void ECBase::Render(ID2D1HwndRenderTarget* target)
{
	// TODO: 여기서 world내의 map중에 현재 위치한 map을 랜더링 하도록 변경합니다.
	Render(target, _worldEntity);
	Render(target, _baseUIEntity);
}

void ECBase::AddMapEntity(EntityId mapId)
{
	_entityManager->GetEntity(_worldEntity)->AddChildEntity(mapId);
	_entityManager->GetEntity(mapId)->SetParentEntity(_worldEntity);
}

void ECBase::AddUIEntity(EntityId uiId)
{
	_entityManager->GetEntity(_baseUIEntity)->AddChildEntity(uiId);
	_entityManager->GetEntity(uiId)->SetParentEntity(_baseUIEntity);
}

void ECBase::CreateWorldEntity()
{
	_worldEntity = _entityManager->CreateEntity<World>();
}

void ECBase::CreateBaseUIEntity()
{
	_baseUIEntity = _entityManager->CreateEntity<DefaultUI>();
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
	ComponentId uiSpriteComponent = _componentManager->GetMappingTable()[id._index][UISprite::COMPONENT_TYPE_ID];
	ComponentId uiTextComponent = _componentManager->GetMappingTable()[id._index][TextComponent::COMPONENT_TYPE_ID];

	if (spriteComponent != INVALID_COMPONENT_ID) {
		static_cast<Sprite*>(_componentManager->GetComponent(spriteComponent))->Render(target);
	}

	if(uiSpriteComponent != INVALID_COMPONENT_ID){
		static_cast<UISprite*>(_componentManager->GetComponent(uiSpriteComponent))->Render(target);
	}

	if (uiTextComponent != INVALID_COMPONENT_ID) {
		static_cast<TextComponent*>(_componentManager->GetComponent(uiTextComponent))->Render(target);
	}
	

	ChildEntities child = _entityManager->GetEntity(id)->GetChildEntityId();
	for (auto& i : child) {
		Render(target, i);
	}
}
