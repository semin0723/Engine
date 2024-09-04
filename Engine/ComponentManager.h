#pragma once
#include "pch.h"
#include "IComponent.h"
#include "FamilyTypeId.h"

using EntityComponentMap = std::vector<std::vector<ComponentId>>;

class ComponentManager
{
	ComponentManager(const ComponentManager&) = delete;
	ComponentManager& operator=(ComponentManager&) = delete;

	using ComponentTable = std::vector<IComponent*>;

public:
	ComponentManager();
	~ComponentManager();

	template<class T, class ...ARGS>
	T* AddComponent(const EntityId entityId, ARGS&&... args) {
		static constexpr std::hash<ComponentId> ENTITY_COMPONENT_ID_HASHER;
		IComponent* newComponent = new T(std::forward<ARGS>(args)...);

		const ComponentTypeId typeId = T::COMPONENT_TYPE_ID;

		ComponentId cid = MappingComponentId(newComponent);
		newComponent->_componentId = cid;

		newComponent->_owner = entityId;
		newComponent->_hashValue = ENTITY_COMPONENT_ID_HASHER(entityId._index) ^ (ENTITY_COMPONENT_ID_HASHER(cid) << 1);

		MapEntityComponent(entityId, cid, typeId);

		return static_cast<T*>(newComponent);
	}

	template<class T>
	void RemoveComponent(const EntityId id) {
		const ComponentTypeId tid = T::COMPONENT_TYPE_ID;
		const ComponentId cid = _entityComponentMap[id._index][tid];
		IComponent* component = _componentTable[cid];

		UnMapEntityComponent(id, cid, tid);
	}

	void RemoveAllComponents(const EntityId id) {
		static const size_t NUM_COMPONENTS = _entityComponentMap[0].size();
		for (ComponentTypeId tid = 0; tid < NUM_COMPONENTS; tid++) {
			const ComponentId cid = _entityComponentMap[id._index][tid];
			if (cid == INVALID_COMPONENT_ID) continue;

			IComponent* component = _componentTable[cid];
			if (component != nullptr) {
				UnMapEntityComponent(id, cid, tid);
			}
		}
	}

	template<class T>
	T* GetComponent(const EntityId id) {
		const ComponentTypeId tid = T::COMPONENT_TYPE_ID;
		const ComponentId cid = _entityComponentMap[id._index][tid];

		if (cid == INVALID_COMPONENT_ID) return nullptr;
		return static_cast<T*>(_componentTable[cid]);
	}

	EntityComponentMap& GetMappingTable();

	IComponent* GetComponent(ULL cid) {
		return _componentTable[cid];
	}

private:
	ULL _expandSize = 16;
	ComponentTable _componentTable;
	EntityComponentMap _entityComponentMap;

	ComponentId MappingComponentId(IComponent* component);
	void		ReleaseComponentId(ComponentId id);

	void		MapEntityComponent(EntityId entityId, ComponentId componentId, ComponentTypeId componentTypeId);
	void		UnMapEntityComponent(EntityId entityId, ComponentId componentId, ComponentTypeId componentTypeId);

	friend class IComponent;
};