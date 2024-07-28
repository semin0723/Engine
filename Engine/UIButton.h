#pragma once
#include "Entity.h"

class UIButton : public Entity<UIButton>
{
public:
	UIButton() {}
	~UIButton() {}

	void Initialize();
};

