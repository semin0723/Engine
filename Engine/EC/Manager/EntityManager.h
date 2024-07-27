#pragma once
#include "pch.h"
#include "IEntity.h"
#include "FamilyTypeId.h"
#include "ComponentManager.h"

class EntityManager
{
	using HandleTable = EntityHandleTable<IEntity, EntityId>;

public:
	EntityManager(ComponentManager* componentManagerInstance);
	~EntityManager();

	template<class T, class... ARGS>
	EntityId CreateEntity(ARGS&&... args) {
		IEntity* newEntity = new T(std::forward<ARGS>(args)...);

		EntityId entityId = MappingEntityId(newEntity);
		newEntity->_entityId = entityId;
		newEntity->_componentManagerInstance = _componentManagerInstance;

		newEntity->Initialize();

		return entityId;
	}

	void DestroyEntity(EntityId id) {
		IEntity* entity = _entityHandleTable[id];

		const EntityTypeId tid = entity->GetEntityTypeId();
		if (_pendingDestroyEntityCount < _pendingDestroyEntities.size()) {
			_pendingDestroyEntities[_pendingDestroyEntityCount++] = id;
		}
		else {
			_pendingDestroyEntities.push_back(id);
			_pendingDestroyEntityCount++;
		}
	}

	IEntity* GetEntity(EntityId id) {
		return _entityHandleTable[id];
	}

	EntityId GetEntityId(ULL idx) {
		return _entityHandleTable[idx];
	}

	void RemoveDestroyEntities();

private:
	EntityManager(const EntityManager&) = delete;
	EntityManager& operator=(EntityManager&) = delete;

	HandleTable _entityHandleTable;

	std::vector<EntityId> _pendingDestroyEntities;
	ULL _pendingDestroyEntityCount;

	ComponentManager* _componentManagerInstance;

	EntityId MappingEntityId(IEntity* entity);
	void ReleaseEntityId(EntityId id);
};

