#pragma once
#include "Component.h"
#include "globalheader.h"

class RigidBody : public Component<RigidBody>
{
public:
	RigidBody() {}
	~RigidBody() {}

	void Initialize() {}
	void Begin() {}
	void FixedUpdate();
	void Update(float dt) {}
	void End() {}
	void Destroy() {}

	void AddForce(const Vector3& power) { _velocity += power; }

	// set
	void SetGravityScale(float scale) { _gravityScale = scale; }

	// get
	const float GetGravityScale() const { return _gravityScale; }
	const Vector3 GetVelocity() const { return _velocity; }

private:
	Vector3 _velocity;
	float _gravityScale = 1.f;

	float _gravity = 9.8f;
};

