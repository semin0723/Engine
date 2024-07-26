#pragma once
#include "Component.h"
#include "globalheader.h"

class ColliderComponent : public Component<ColliderComponent>
{
public:
	ColliderComponent() {}
	~ColliderComponent() {}

	void Initialize() {}
	void Begin() {}
	void FixedUpdate() {}
	void Update(float dt) {}
	void End() {}
	void Destroy() {}

	CollisionGroup _collisionGroup = CollisionGroup::Default;
	Vector3 _colliderSize;
	Vector3 _colliderOffset;

};

