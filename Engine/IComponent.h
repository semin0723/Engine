#pragma once
#include "pch.h"
#include "EntityHandleTable.h"

using ComponentId		= ObjectId;
using ComponentTypeId	= TypeId;

static const ComponentId INVALID_COMPONENT_ID = INVALID_OBJECT_ID;

template <class T>
class Component;

class IComponent
{
public:
	IComponent() {}
	virtual ~IComponent() {}

	const bool operator==(const IComponent& other) const { return _hashValue == other._hashValue; }
	const bool operator!=(const IComponent& other) const { return _hashValue != other._hashValue; }

	const ComponentId GetComponentId() const { return _componentId; }
	const EntityId GetOwner() const { return _owner; }

	void SetActive(bool state)	{ _enable = state; }
	bool Active() const			{ return _enable; }

	virtual void OnInitialize()		{}
	virtual void OnBegin()			{}
	virtual void OnFixedUpdate()	{}
	virtual void OnUpdate(float dt) {}
	virtual void OnEnd()			{}
	virtual void OnDestroy()		{}

protected:
	ComponentId		_hashValue;
	ComponentId		_componentId	{ INVALID_COMPONENT_ID };
	EntityId		_owner;
	bool			_enable			{ true };

private:
	friend class ComponentManager;
};

