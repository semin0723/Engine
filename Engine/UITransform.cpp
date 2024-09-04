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
	RigidBody* rb = componentManager->GetComponent<RigidBody>(_owner);
	UISprite* sp = componentManager->GetComponent<UISprite>(_owner);
	if (rb != nullptr) {
		_position += rb->GetVelocity() * dt;
	}

	_localTransform =
		D2D1::Matrix3x2F::Scale(_scale.x, _scale.y, D2D1::Point2F(sp->GetSize().x / 2.0f, sp->GetSize().y / 2.0f)) *
		D2D1::Matrix3x2F::Rotation(_rotation.z, D2D1::Point2F(sp->GetSize().x / 2.0f, sp->GetSize().y / 2.0f)) *
		D2D1::Matrix3x2F::Translation(_position.x, _position.y)
		;

	EntityId parentId = entityManager->GetEntity(_owner)->GetParentEntityId();
	if (parentId == EntityId() || componentManager->GetComponent<Transform>(parentId) == nullptr) {
		_screenTransform = _localTransform;
	}
	else {
		D2D1::Matrix3x2F parentWorldTransform = componentManager->GetComponent<UITransform>(parentId)->_screenTransform;
		_screenTransform = _localTransform * parentWorldTransform;
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
