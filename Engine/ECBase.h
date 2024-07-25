#pragma once
#include "EventDelegate.h"
#include "EventHandler.h"
#include "EntityManager.h"
#include "ComponentManager.h"

class EventListener;
class IEvent;
class EventHandler;

class ECBase
{
public:
	ECBase();
	~ECBase();

	template<class E, class ...ARGS>
	void SendEvent(ARGS&&... eventArgs) {
		_eventHandler->Send<E>(std::forward<ARGS>(eventArgs)...);
	}

	void Initialize();
	void MapEnter() {}
	void Begin();
	void FixedUpdate();
	void Update(float dt);
	void End();
	void Render(ID2D1HwndRenderTarget* target);

	void AddMapEntity(EntityId mapId);

	EntityManager* GetEntityManager() const { return _entityManager; }
	ComponentManager* GetComponentManager() const { return _componentManager; }

private:
	EventHandler* _eventHandler;
	EntityManager* _entityManager;
	ComponentManager* _componentManager;

	const std::vector<std::vector<ComponentId>>& _componentMappingTable = _componentManager->GetMappingTable();

	ECBase(const ECBase&) = delete;
	ECBase& operator=(ECBase&) = delete;

	template<class E>
	void SubscribeEvent(IEventDelegate* const eventDelegate) {
		_eventHandler->AddEventCallback<E>(eventDelegate);
	}

	void UnSubscribeEvent(IEventDelegate* eventDelegate) {
		_eventHandler->RemoveEventCallback(eventDelegate);
	}

	// World Entity
	EntityId _worldEntity;

	void CreateWorldEntity();

	void Initialize(EntityId id);
	void MapEnter(EntityId id) {}
	void Begin(EntityId id);
	void FixedUpdate(EntityId id);
	void Update(EntityId id, float dt);
	void End(EntityId id) {}

	void Render(ID2D1HwndRenderTarget* target, EntityId id);


	friend class IEvent;
	friend class EventListener;
	friend class EntityManager;
	friend class IEntity;
	friend class IComponent;
	friend class GameEngine;
};

