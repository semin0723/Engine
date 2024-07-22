#pragma once
#include "pch.h"
#include "EntityHandleTable.h"
#include "FamilyTypeId.h"

using EntityTypeId = TypeId;
using ChildEntities = std::vector<EntityId>;

static const ULL INVALID_ENTITY_ID = (std::numeric_limits<ULL>::max)();

class IEntity
{
public:
	IEntity();
	virtual ~IEntity() {}

	template<class T>
	T* GetComponent() const { return _componentManagerInstance->Getcomponent<T>(_entityId); }

	template<class T, class ...P>
	T* AddComponent(P&&... param) { return _componentManagerInstance->AddComponent<T>(_entityId, std::forward<P>(param)...); }

	template<class T>
	void RemoveComponent() { _componentManagerInstance->RemoveComponent<T>(_entityId); }

	bool operator==(const IEntity& other) const { return _entityId == other._entityId; }
	bool operator!=(const IEntity& other) const { return _entityId != other._entityId; }
	bool operator==(const IEntity* other) const { return _entityId == other->_entityId; }
	bool operator!=(const IEntity* other) const { return _entityId != other->_entityId; }

	virtual const EntityTypeId GetEntityTypeId() const {}
	const EntityId GetEntityId() const { return _entityId; }

	void SetParentEntity(EntityId id) { _parentId = id; }
	void AddChildEntity(EntityId id) { _childs.push_back(id); }
	const EntityId GetParentEntityId() const { return _parentId; }
	const ChildEntities& GetChildEntityId() const { return _childs; }

	void SetActive(bool state);
	bool Active() const { return _active; }

	virtual void OnEnable() {}
	virtual void OnDisable() {}

protected:
	EntityId _entityId;

	EntityId _parentId;
	ChildEntities _childs;

	bool _active = false;

private:
	ComponentManager* _componentManagerInstance;

	friend class EntityManager;
};

