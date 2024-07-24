#pragma once
#include "ECBase.h"

#define Engine EC::_ec
#define EntityManager Engine->GetEntityManager();
#define ComponentManager Engine->GetComponentManager();

class ECBase;

namespace EC {
	extern ECBase* _ec;
	void Initialize();
	void Finalize();

}

