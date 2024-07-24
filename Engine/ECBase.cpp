#include "pch.h"
#include "ECBase.h"


ECBase::ECBase()
{
	_eventHandler = new EventHandler;
	_componentManager = new ComponentManager;
	_entityManager = new EntityManager(_componentManager);
}

ECBase::~ECBase()
{
	delete _entityManager;
	_entityManager = nullptr;

	delete _componentManager;
	_componentManager = nullptr;

	delete _eventHandler;
	_eventHandler = nullptr;
}

void ECBase::Initialize()
{
	// eid : EntityId     ,     ctid : ComponentTypeId;
	for (int eid = 0; eid < _componentMappingTable.size(); eid++) {
		for (int ctid = 0; ctid < _componentMappingTable[eid].size(); ctid++) {
			if (_componentMappingTable[eid][ctid] == INVALID_COMPONENT_ID) continue;
			ComponentId cid = _componentMappingTable[eid][ctid];
			_componentManager->GetComponent(cid)->OnInitialize();
		}
	}
}

void ECBase::Begin()
{
	for (int eid = 0; eid < _componentMappingTable.size(); eid++) {
		for (int ctid = 0; ctid < _componentMappingTable[eid].size(); ctid++) {
			if (_componentMappingTable[eid][ctid] == INVALID_COMPONENT_ID) continue;
			ComponentId cid = _componentMappingTable[eid][ctid];
			_componentManager->GetComponent(cid)->OnBegin();
		}
	}
}

void ECBase::FixedUpdate()
{
	for (int eid = 0; eid < _componentMappingTable.size(); eid++) {
		for (int ctid = 0; ctid < _componentMappingTable[eid].size(); ctid++) {
			if (_componentMappingTable[eid][ctid] == INVALID_COMPONENT_ID) continue;
			ComponentId cid = _componentMappingTable[eid][ctid];
			_componentManager->GetComponent(cid)->OnFixedUpdate();
		}
	}
}

void ECBase::Update(float dt)
{
	for (int eid = 0; eid < _componentMappingTable.size(); eid++) {
		for (int ctid = 0; ctid < _componentMappingTable[eid].size(); ctid++) {
			if (_componentMappingTable[eid][ctid] == INVALID_COMPONENT_ID) continue;
			ComponentId cid = _componentMappingTable[eid][ctid];
			_componentManager->GetComponent(cid)->OnUpdate(dt);
		}
	}
}

void ECBase::End()
{
	for (int eid = 0; eid < _componentMappingTable.size(); eid++) {
		for (int ctid = 0; ctid < _componentMappingTable[eid].size(); ctid++) {
			if (_componentMappingTable[eid][ctid] == INVALID_COMPONENT_ID) continue;
			ComponentId cid = _componentMappingTable[eid][ctid];
			_componentManager->GetComponent(cid)->OnEnd();
		}
	}
}
