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

void Transform::Rotate(const Vector3& angle)
{
	_rotation += angle;
}

void Transform::Translate(const Vector3& delta)
{
	_position += delta;
}
