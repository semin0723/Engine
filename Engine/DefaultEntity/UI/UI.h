#pragma once
#include "Entity.h"

class UI : public Entity<UI>
{
public:
	UI() {}
	~UI() {}

	void Initialize();
};

