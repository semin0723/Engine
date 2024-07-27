#include "pch.h"
#include "EntityManager.h"

EntityManager::EntityManager(ComponentManager* componentManagerInstance) :
	_pendingDestroyEntities(1024),
	_pendingDestroyEntityCount(0),
	_componentManagerInstance(componentManagerInstance)
{
}

EntityManager::~EntityManager()
{

}

void EntityManager::RemoveDestroyEntities()
{
	for (size_t i = 0; i < _pendingDestroyEntityCount; i++)
	{
		EntityId id = _pendingDestroyEntities[i];
		IEntity* entity = _entityHandleTable[id];

		if (entity == nullptr) continue;

		ReleaseEntityId(id);
	}
	_pendingDestroyEntityCount = 0;
}

EntityId EntityManager::MappingEntityId(IEntity* entity)
{
	return _entityHandleTable.MappingHandle(entity);
}

void EntityManager::ReleaseEntityId(EntityId id)
{
	_entityHandleTable.ReleaseHandle(id);
}
