#include "pch.h"
#include "ECBase.h"
#include "GameElements.h"
#include "FunctionTimer.h"

// System
#include "ResourceSystem.h"
#include "RenderSystem.h"
#include "InputSystem.h"

// Logger
#include "Log.h"

#include "globalheader.h"

ECBase::ECBase()
{
	_eventHandler = new EventHandler;
	_componentManager = new ComponentManager;
	_entityManager = new EntityManager(_componentManager);
	_renderSystem = new RenderSystem;
	_inputSystem = new InputSystem;
	_log = new Log;

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

void ECBase::SendMovePacket(EntityId eid, Vector3 dir, float speed, float dt)
{
	MoveTest::Move move;
	move.set_objnum(eid._index);
	move.set_objver(eid._version);
	move.set_x(dir.x);
	move.set_y(dir.y);
	move.set_speed(speed);
	move.set_delta(dt);

	std::string msg = move.SerializeAsString();

	Client::SavePacketData(msg, (short)PacketID::Move);
}

void ECBase::SendEnterPacket(EntityId eid, Vector3 pos)
{
	MoveTest::PlayerEnter playerEnter;
	playerEnter.set_objnum(eid._index);
	playerEnter.set_objver(eid._version);

	std::string msg = playerEnter.SerializeAsString();

	Client::SavePacketData(msg, (short)PacketID::RoomEnter);
}

void ECBase::DispatchPacket()
{
	PacketQueue* msgQueue = Client::GetPacketContainer();

	if ((*msgQueue).empty()) {
		bool res = Client::SwapPacketContainer();
		if (res == false) {
			return;
		}
	}

	while (!(*msgQueue).empty()) {
		Packet packet = (*msgQueue).front();
		(*msgQueue).pop();

		switch ((PacketID)packet._packetId) {
		case PacketID::ASyncPlayer:
		{
			MoveTest::AsyncPlayer async;
			async.ParseFromArray(packet._data, packet._packetSize - sizeof(PacketHeader));
			Transform* tf = entityManager->GetEntity({ async.objnum(), async.objver() })->GetComponent<Transform>();
			tf->SetPosition(Vector3(async.x(), async.y(), 0.0f));

			break;
		}

		default:
			break;
		}
	}
}

bool ECBase::Initialize()
{
	bool res = true;
	res = Client::Initialize();
	if (res == false) {
		return false;
	}
	res = Client::ConnectToServer();
	if (res == false) {
		return false;
	}


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
	//Client::SendUpdate();
	DispatchPacket();

	_inputSystem->Update(dt);

	Update(entityManager->GetEntity(_worldEntity)->GetChildEntityId()[_curMapIdx], dt);
	Update(_baseUIEntity, dt);

	FunctionTimer::GetInstance()->Update(dt);

	_eventHandler->DispatchEvents();
	_entityManager->RemoveDestroyEntities();
	_eventHandler->DispatchEvents();

	Client::SendUpdate();
}

void ECBase::End()
{
	//End(_worldEntity);
	End(entityManager->GetEntity(_worldEntity)->GetChildEntityId()[_curMapIdx]);
	End(_baseUIEntity);
}

void ECBase::Render(ID2D1HwndRenderTarget* target)
{
	// 여기서 world내의 map중에 현재 위치한 map을 랜더링 하도록 해줍니다.
	//Render(target, _worldEntity);
	//Render(target, _baseUIEntity);

	_renderSystem->SpriteRender(target, entityManager->GetEntity(_worldEntity)->GetChildEntityId()[_curMapIdx]);
	_renderSystem->UIRender(target, _baseUIEntity);
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

void ECBase::RecordLog(std::string message, std::source_location sourceLocation)
{
	_log->RecordLog(message, sourceLocation);
}

void ECBase::InitializeObject()
{
	// 여기서 현재 위치한 map의 Entity들을 전부 초기화 해줍니다.
//Initialize(_worldEntity);
	Initialize(entityManager->GetEntity(_worldEntity)->GetChildEntityId()[_curMapIdx]);
	Initialize(_baseUIEntity);
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

//void ECBase::Render(ID2D1HwndRenderTarget* target, EntityId id)
//{
//	ComponentId spriteComponent = _componentManager->GetMappingTable()[id._index][Sprite::COMPONENT_TYPE_ID];
//	ComponentId uiSpriteComponent = _componentManager->GetMappingTable()[id._index][UISprite::COMPONENT_TYPE_ID];
//	ComponentId uiTextComponent = _componentManager->GetMappingTable()[id._index][TextComponent::COMPONENT_TYPE_ID];
//
//	if (spriteComponent != INVALID_COMPONENT_ID) {
//		static_cast<Sprite*>(_componentManager->GetComponent(spriteComponent))->Render(target);
//	}
//
//	if(uiSpriteComponent != INVALID_COMPONENT_ID){
//		static_cast<UISprite*>(_componentManager->GetComponent(uiSpriteComponent))->Render(target);
//	}
//
//	if (uiTextComponent != INVALID_COMPONENT_ID) {
//		static_cast<TextComponent*>(_componentManager->GetComponent(uiTextComponent))->Render(target);
//	}
//	
//
//	ChildEntities child = _entityManager->GetEntity(id)->GetChildEntityId();
//	for (auto& i : child) {
//		Render(target, i);
//	}
//}
