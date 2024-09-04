#pragma once
#include "pch.h"
#include "EntityHandleTable.h"
#include "FamilyTypeId.h"
#include "ComponentManager.h"
#include "EventListener.h"

using EntityTypeId = TypeId;
using ChildEntities = std::vector<EntityId>;

static const ULL INVALID_ENTITY_ID = (std::numeric_limits<ULL>::max)();

class IEntity : public EventListener
{
public:
	IEntity();
	virtual ~IEntity() {}

	template<class T>
	T* GetComponent() const { return _componentManagerInstance->GetComponent<T>(_entityId); }

	template<class T, class ...P>
	T* AddComponent(P&&... param) { return _componentManagerInstance->AddComponent<T>(_entityId, std::forward<P>(param)...); }

	template<class T>
	void RemoveComponent() { _componentManagerInstance->RemoveComponent<T>(_entityId); }

	bool operator==(const IEntity& other) const { return _entityId == other._entityId; }
	bool operator!=(const IEntity& other) const { return _entityId != other._entityId; }
	bool operator==(const IEntity* other) const { return _entityId == other->_entityId; }
	bool operator!=(const IEntity* other) const { return _entityId != other->_entityId; }

	virtual const EntityTypeId GetEntityTypeId() const = 0;
	const EntityId GetEntityId() const { return _entityId; }

	void SetParentEntity(EntityId id) { _parentId = id; }
	void AddChildEntity(EntityId id) { _childs.push_back(id); }
	const EntityId GetParentEntityId() const { return _parentId; }
	const ChildEntities& GetChildEntityId() const { return _childs; }

	void SetActive(bool state);
	bool Active() const { return _active; }

	void SetName(std::string name) { _name = name; }
	const std::string GetName() const { return _name; }

	virtual void OnEnable() {}
	virtual void OnDisable() {}

	virtual void Initialize() {}

protected:
	EntityId _entityId;

	EntityId _parentId;
	ChildEntities _childs;

	std::string _name;

	bool _active = false;

private:
	ComponentManager* _componentManagerInstance;

	friend class EntityManager;
};

