#pragma once
#include "Component.h"
#include "globalheader.h"

class Transform : public Component<Transform>
{
public:
	Transform();
	Transform(Vector3 pos, Vector3 scale, Vector3 rotation);
	~Transform() {}

	void Initialize() {}
	void Begin();
	void FixedUpdate() {}
	void Update(float dt);
	void End() {}
	void Destroy() {}

	void Rotate(const Vector3& angle);
	void Translate(const Vector3& delta);

	Vector3 _position;
	Vector3 _rotation;
	Vector3 _scale;

	D2D1::Matrix3x2F _localTransform;
	D2D1::Matrix3x2F _worldTransform;

	void MoveAmount();

};

