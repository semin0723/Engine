#include "pch.h"
#include "Transform.h"
#include "Components.h"
#include "ECMain.h"
#include "FunctionTimer.h"

Transform::Transform() : _position(Vector3(0, 0, 0)), _scale(Vector3(1.0f, 1.0f, 1.0f)), _rotation(Vector3(0, 0, 0))
{
}

Transform::Transform(Vector3 pos, Vector3 scale, Vector3 rotation) : _position(pos), _scale(scale), _rotation(rotation)
{
}

void Transform::Begin()
{
	FunctionTimer::GetInstance()->SetTimer(std::bind(&Transform::MoveAmount, this), 1.0f, true);
}

void Transform::Update(float dt)
{
	EntityId parentId = entityManager->GetEntity(_owner)->GetParentEntityId();
	if (parentId == EntityId() || componentManager->GetComponent<Transform>(parentId) == nullptr) {
		_worldPosition = _position;
	}
	else {
		Vector3 parentWorldPosition = componentManager->GetComponent<Transform>(parentId)->_worldPosition;
		_worldPosition = parentWorldPosition + _position;
	}

	Sprite* sp = componentManager->GetComponent<Sprite>(_owner);
	_worldTransform =
		D2D1::Matrix3x2F::Scale(_scale.x, _scale.y, D2D1::Point2F(sp->_size.x / 2.0f, sp->_size.y / 2.0f)) *
		D2D1::Matrix3x2F::Rotation(_rotation.z, D2D1::Point2F(sp->_size.x / 2.0f, sp->_size.y / 2.0f)) *
		D2D1::Matrix3x2F::Translation(_worldPosition.x, _worldPosition.y)
		;
}
void Transform::Rotate(const Vector3& angle)
{
	_rotation += angle;
}

void Transform::Translate(const Vector3& delta)
{
	_position += delta;
}

void Transform::MoveAmount()
{
	_position += Vector3(10.0f, 0, 0);
}
