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


	virtual void Initialize();
	virtual void Begin();
	virtual void FixedUpdate();
	virtual void Update(float dt);
	virtual void End();
	
	const EntityManager* GetEntityManager() const { return _entityManager; }
	const ComponentManager* GetComponentManager() const { return _componentManager; }

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

	friend class IEvent;
	friend class EventListener;
	friend class EntityManager;
	friend class IEntity;
	friend class IComponent;
};

