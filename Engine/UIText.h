#pragma once
#include "Entity.h"

class UIText : public Entity<UIText>
{
public:
	UIText() {}
	~UIText() {}

	void Initialize();
};

