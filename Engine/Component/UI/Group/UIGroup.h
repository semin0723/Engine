#pragma once
#include "Component.h"

class UIGroup : public Component<UIGroup>
{
	static UINT orderIdx;
public:
	UIGroup() : _groupOrder(orderIdx++) {}
	~UIGroup() {}

	void Initialize() {}
	void Begin() {}
	void FixedUpdate() {}
	void Update(float dt) {}
	void End() {}
	void Destroy() {}

	UINT _groupOrder;
};

