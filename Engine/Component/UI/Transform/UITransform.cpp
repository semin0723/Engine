#include "pch.h"
#include "UITransform.h"

UITransform::UITransform() : _position(Vector3(0, 0, 0)), _scale(Vector3(1.0f, 1.0f, 1.0f)), _rotation(Vector3(0, 0, 0))
{
}

UITransform::UITransform(Vector3 pos, Vector3 scale, Vector3 rotation) : _position(pos), _scale(scale), _rotation(rotation)
{
}

void UITransform::Update(float dt)
{
	EntityId parentId = entityManager->GetEntity(_owner)->GetParentEntityId();
	if (parentId == EntityId() || componentManager->GetComponent<UITransform>(parentId) == nullptr) {
		_worldPosition = _position;
	}
	else {
		Vector3 parentWorldPosition = componentManager->GetComponent<UITransform>(parentId)->_worldPosition;
		_worldPosition = parentWorldPosition + _position;
	}
}

void UITransform::Rotate(const Vector3& angle)
{
	_rotation += angle;
}

void UITransform::Translate(const Vector3& delta)
{
	_position += delta;
}
