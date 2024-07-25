#pragma once
#include "Entity.h"

class Object : public Entity<Object>
{
public:
	Object() {}
	~Object() {}

	void Initialize();
};

