#pragma once
#include "pch.h"
#include "IComponent.h"
#include "FamilyTypeId.h"


class ComponentManager
{
	class IComponentContainer {
	public:
		virtual ~IComponentContainer() {}

		virtual const char* GetComponentContainerTypeName() const = 0;
		virtual void CreateComponent(IComponent* component) = 0;
		virtual void DestroyComponent(IComponent* component) = 0;
	};

	template<class T>
	class ComponentContainer : public IComponentContainer {
		ComponentContainer(const ComponentContainer&) = delete;
		ComponentContainer& operator=(ComponentContainer&) = delete;

		using ComponentList = std::vector<IComponent*>;

	public:
		ComponentContainer() {}
		virtual ~ComponentContainer() {}

		// 컴포넌트를 상속받는 클래스의 이름을 가져옵니다.
		virtual const char* GetComponentContainerTypeName() const override {
			static const char* ComponentTypeName{ typeid(T).name() };
			return ComponentTypeName;
		}

		virtual void CreateComponent(IComponent* component) override {
			_components.push_back(component);
		}

		virtual void DestroyComponent(IComponent* component) override {
			ComponentList::iterator it;
			for (ComponentList::iterator i = _components.begin(); i != _components.end(); i++) {
				if (component->_hashValue == (*i)->_hashValue) {
					it = i;
					break;
				}
			}
			_components.erase(it);
			delete component;
		}

	private:
		ComponentList _components;
	};

	ComponentManager(const ComponentManager&) = delete;
	ComponentManager& operator=(ComponentManager&) = delete;

	using ComponentContainerRegistry = std::unordered_map<ComponentTypeId, IComponentContainer*>;

	ComponentContainerRegistry _componentContainerRegistry;

	// 컴포넌트 유형에 따른 컴포넌트 컨테이너를 반환합니다.
	template<class T>
	ComponentContainer<T>* GetComponentContainer() {
		ComponentTypeId componentId = T::COMPONENT_TYPE_ID;

		auto iterator = _componentContainerRegistry.find(componentId);

		ComponentContainer<T>* componentContainer = nullptr;

		if (iterator == _componentContainerRegistry.end()) {
			componentContainer = new ComponentContainer<T>;
			_componentContainerRegistry[componentId] = componentContainer;
		}
		else {
			componentContainer = static_cast<ComponentContainer<T>*>(iterator->second);
		}

		return componentContainer;
	}


	using ComponentTable = std::vector<IComponent*>;
	using EntityComponentMap = std::vector<std::vector<ComponentId>>;

public:

	// ComponentContainer 내부 구조 설정할 때 iterator도 같이 설정해줘야함.
	template<class T>
	using TComponentIterator = typename ComponentContainer<T>::iterator;

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

		GetComponentContainer<T>()->CreateComponent(newComponent);

		MapEntityComponent(entityId, cid, typeId);

		return static_cast<T*>(newComponent);
	}

	template<class T>
	void RemoveComponent(const EntityId id) {
		const ComponentTypeId tid = T::COMPONENT_TYPE_ID;
		const ComponentId cid = _entityComponentMap[id._index][tid];
		IComponent* component = _componentTable[cid];

		GetComponentContainer<T>->DestroyComponent(component);
		UnMapEntityComponent(id, cid, tid);
	}

	void RemoveAllComponents(const EntityId id) {
		static const size_t NUM_COMPONENTS = _entityComponentMap[0].size();
		for (ComponentTypeId tid = 0; tid < NUM_COMPONENTS; tid++) {
			const ComponentId cid = _entityComponentMap[id._index][tid];
			if (cid == INVALID_COMPONENT_ID) continue;

			IComponent* component = _componentTable[cid];
			if (component != nullptr) {
				auto iterator = _componentContainerRegistry.find(tid);
				if (iterator != _componentContainerRegistry.end()) {
					iterator->second->DestroyComponent(component);
				}
				UnMapEntityComponent(id, cid, tid);
			}
		}
	}

	template<class T>
	T* Getcomponent(const EntityId id) {
		const ComponentTypeId tid = T::COMPONENT_TYPE_ID;
		const ComponentId cid = _entityComponentMap[id._index][tid];

		if (cid == INVALID_COMPONENT_ID) return nullptr;
		return static_cast<T*>(_componentTable[cid]);
	}

	EntityComponentMap& GetMappingTable();

	IComponent* GetComponent(ULL cid) {
		return _componentTable[cid];
	}

	template<class T>
	TComponentIterator<T> begin() {
		return GetComponentContainer<T>()->_components.begin();
	}

	template<class T>
	TComponentIterator<T> end() {
		return GetComponentContainer<T>()->_components.end();
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