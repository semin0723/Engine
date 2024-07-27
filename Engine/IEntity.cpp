#include "pch.h"
#include "IEntity.h"

IEntity::IEntity()
{
}

void IEntity::SetActive(bool state)
{
	if (_active == state) return;

	if (state == true) {
		OnEnable();
	}
	else {
		OnDisable();
	}
	_active = state;
}
