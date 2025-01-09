#pragma once
#include "EventDelegate.h"
#include "EventHandler.h"
#include "EntityManager.h"
#include "ComponentManager.h"
#include "MoveTest.pb.h"
#include "../Includes/Server/ClientEntrance.h"
#include "Packet.h"
#include "Vector3.h"

class EventListener;
class IEvent;
class EventHandler;
class RenderSystem;
class InputSystem;
class Log;

class ECBase
{
public:
	ECBase();
	~ECBase();

	// send Event with sender Entity Name
	template<class E, class ...ARGS>
	void SendEvent(std::string sender, ARGS&&... eventArgs) {
		_eventHandler->Send<E>(std::forward<std::string>(sender), std::forward<ARGS>(eventArgs)...);
	}

	void SendMovePacket(EntityId eid, Vector3 dir, float speed, float dt);
	void SendEnterPacket(EntityId eid, Vector3 pos);
	void DispatchPacket();

	void RecordLog(std::string message, std::source_location sourceLocation = std::source_location::current());
	void InitializeObject();
	bool Initialize();
	void MapEnter() {}
	void Begin();
	void FixedUpdate();
	void Update(float dt);
	void End();
	void Render(ID2D1HwndRenderTarget* target);

	// Map은 0번부터 1번씬 입니다.
	void AddMapEntity(EntityId mapId);
	void AddUIEntity(EntityId uiId);

	const EntityId GetUIEntity() const { return _baseUIEntity; }

	EntityManager* GetEntityManager() const { return _entityManager; }
	ComponentManager* GetComponentManager() const { return _componentManager; }

private:
	EventHandler* _eventHandler;
	EntityManager* _entityManager;
	ComponentManager* _componentManager;

	// system
	RenderSystem* _renderSystem;
	InputSystem* _inputSystem;

	// logger
	Log* _log;


	ECBase(const ECBase&) = delete;
	ECBase& operator=(ECBase&) = delete;

	template<class E>
	void SubscribeEvent(std::string sender, IEventDelegate* const eventDelegate) {
		_eventHandler->AddEventCallback<E>(sender, eventDelegate);
	}

	void UnSubscribeEvent(std::string sender, IEventDelegate* eventDelegate) {
		_eventHandler->RemoveEventCallback(sender, eventDelegate);
	}

	// World Entity
	EntityId _worldEntity;
	EntityId _baseUIEntity;

	//  == curScene
	int _curMapIdx = 0;

	void CreateWorldEntity();
	void CreateBaseUIEntity();

	void Initialize(EntityId id);
	void MapEnter(EntityId id) {}
	void Begin(EntityId id);
	void FixedUpdate(EntityId id);
	void Update(EntityId id, float dt);
	void End(EntityId id) {}

	//void Render(ID2D1HwndRenderTarget* target, EntityId id);


	friend class IEvent;
	friend class EventListener;
	friend class EntityManager;
	friend class IEntity;
	friend class IComponent;
	friend class GameEngine;
};

