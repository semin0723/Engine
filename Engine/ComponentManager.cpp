#include "pch.h"
#include "ComponentManager.h"

using EntityComponentMap = std::vector<std::vector<ComponentId>>;

ComponentManager::ComponentManager()
{
    const size_t componentCount{ FamilyTypeId<IComponent>::Get() };
    _entityComponentMap.resize(_expandSize);
    for (auto i = 0; i < _expandSize; i++) {
        _entityComponentMap[i].resize(componentCount, INVALID_COMPONENT_ID);
    }
}

ComponentManager::~ComponentManager()
{
    for (auto componentContainer : _componentContainerRegistry) {
        delete componentContainer.second;
        componentContainer.second = nullptr;
    }
}

EntityComponentMap& ComponentManager::GetMappingTable()
{
    return _entityComponentMap;
}

ComponentId ComponentManager::MappingComponentId(IComponent* component)
{
    int i = 0;
    for (; i < _componentTable.size(); i++) {
        if (_componentTable[i] == nullptr) {
            _componentTable[i] = component;
            return i;
        }
    }

    _componentTable.resize(_componentTable.size() + _expandSize, nullptr);
    _componentTable[i] = component;

    return i;
}

void ComponentManager::ReleaseComponentId(ComponentId id)
{
    _componentTable[id] = nullptr;
}

void ComponentManager::MapEntityComponent(EntityId entityId, ComponentId componentId, ComponentTypeId componentTypeId)
{
    static const size_t NUM_COMPONENTS{ FamilyTypeId<IComponent>::Get() };
    if ((_entityComponentMap.size() - 1) < entityId._index) {
        size_t oldSize = _entityComponentMap.size();

        size_t newSize = oldSize + _expandSize;
        _entityComponentMap.resize(newSize);
        for (size_t i = oldSize; i < newSize; i++) {
            _entityComponentMap[i].resize(NUM_COMPONENTS, INVALID_COMPONENT_ID);
        }
    }
    _entityComponentMap[entityId._index][componentTypeId] = componentId;
}

void ComponentManager::UnMapEntityComponent(EntityId entityId, ComponentId componentId, ComponentTypeId componentTypeId)
{
    _entityComponentMap[entityId._index][componentTypeId] = INVALID_COMPONENT_ID;
    ReleaseComponentId(componentId);
}

