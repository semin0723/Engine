#pragma once
#include "Entity.h"

class World : public Entity<World>
{
public:
	World() {}
	~World() {}

	void Initialize() {}
};

