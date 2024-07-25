#include "pch.h"
#include "Transform.h"
#include "ECMain.h"

Transform::Transform(Vector3 pos, Vector3 scale, Vector3 rotation) : _position(pos), _scale(scale), _rotation(rotation)
{
}

void Transform::Update(float dt)
{
	EntityId parentId = entityManager->GetEntity(_owner)->GetParentEntityId();
	if (parentId == EntityId()) {
		_worldPosition = _position;
	}
	else {
		Vector3 parentWorldPosition = componentManager->GetComponent<Transform>(parentId)->_worldPosition;
		_worldPosition = parentWorldPosition + _position;
	}
}
void Transform::Rotate(const Vector3& angle)
{
	_rotation += angle;
}

void Transform::Translate(const Vector3& delta)
{
	_position += delta;
}
