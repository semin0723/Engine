#pragma once
#include "IComponent.h"
#include "FamilyTypeId.h"
#include "EventListener.h"

template <class T>
class Component :
    public IComponent
{
public:
    static const ComponentTypeId COMPONENT_TYPE_ID;

    Component() {}
    virtual ~Component() {}

	ComponentTypeId GetComponentTypeId() const { return COMPONENT_TYPE_ID; }

	virtual void OnInitialize()		final {		static_cast<T*>(this)->Initialize();	}
	virtual void OnBegin()			final {		static_cast<T*>(this)->Begin();			}
	virtual void OnFixedUpdate()	final {		static_cast<T*>(this)->FixedUpdate();	}
	virtual void OnUpdate(float dt) final {		static_cast<T*>(this)->Update(dt);		}
	virtual void OnEnd()			final {		static_cast<T*>(this)->End();			}
	virtual void OnDestroy()		final {		static_cast<T*>(this)->Destroy();		}

	void Initialize()		{}
	void Begin()			{}
	void FixedUpdate()		{}
	void Update(float dt)	{}
	void End()				{}
	void Destroy()			{}
};

template <class T>
const ComponentTypeId Component<T>::COMPONENT_TYPE_ID = FamilyTypeId<IComponent>::Get<T>();