#include "pch.h"
#include "RigidBody.h"

void RigidBody::FixedUpdate()
{
	_velocity.y += _gravity;
}
