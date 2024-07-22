#pragma once
#include "IComponent.h"
#include "FamilyTypeId.h"

template <class T>
class Component :
    public IComponent
{
public:
    static const ComponentTypeId COMPONENT_TYPE_ID;

    Component() {}
    virtual ~Component() {}

	ComponentTypeId GetComponentTypeId() const { return COMPONENT_TYPE_ID; }

	virtual void OnInitialize() {}
	virtual void OnBegin() {}
	virtual void OnFixedUpdate() {}
	virtual void OnUpdate(float dt) {}
	virtual void OnEnd() {}
	virtual void OnDestroy() {}

};

template <class T>
const ComponentTypeId Component<T>::COMPONENT_TYPE_ID = FamilyTypeId<IComponent>::Get<T>();