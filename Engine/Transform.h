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

	// set
	void SetPosition	(Vector3& position)		{ _position = position; }
	void SetRotation	(Vector3& rotation)		{ _rotation = rotation; }
	void SetScale		(Vector3& scale)		{ _scale = scale; }


	// get
	const Vector3 GetPosition() const { return _position; }
	const Vector3 GetRotation() const { return _rotation; }
	const Vector3 GetScale()	const { return _scale; }

private:
	Vector3 _position;
	Vector3 _rotation;
	Vector3 _scale;

	D2D1::Matrix3x2F _localTransform;
	D2D1::Matrix3x2F _worldTransform;

};

