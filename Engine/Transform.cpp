#include "pch.h"
#include "Transform.h"
#include "Components.h"
#include "ECMain.h"

Transform::Transform() : _position(Vector3(0, 0, 0)), _scale(Vector3(1.0f, 1.0f, 1.0f)), _rotation(Vector3(0, 0, 0))
{
}

Transform::Transform(Vector3 pos, Vector3 scale, Vector3 rotation) : _position(pos), _scale(scale), _rotation(rotation)
{
}

void Transform::Begin()
{

}

void Transform::Update(float dt)
{
	RigidBody* rb = componentManager->GetComponent<RigidBody>(_owner);
	Sprite* sp = componentManager->GetComponent<Sprite>(_owner);
	if (rb != nullptr) {
		_position += rb->_velocity * dt;
	}

	_localTransform =
		D2D1::Matrix3x2F::Scale(_scale.x, _scale.y, D2D1::Point2F(sp->_size.x / 2.0f, sp->_size.y / 2.0f)) *
		D2D1::Matrix3x2F::Rotation(_rotation.z, D2D1::Point2F(sp->_size.x / 2.0f, sp->_size.y / 2.0f)) *
		D2D1::Matrix3x2F::Translation(_position.x, _position.y)
		;

	EntityId parentId = entityManager->GetEntity(_owner)->GetParentEntityId();
	if (parentId == EntityId() || componentManager->GetComponent<Transform>(parentId) == nullptr) {
		_worldTransform = _localTransform;
	}
	else {
		D2D1::Matrix3x2F parentWorldTransform = componentManager->GetComponent<Transform>(parentId)->_worldTransform;
		_worldTransform = _localTransform * parentWorldTransform;
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
