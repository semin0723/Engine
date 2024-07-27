#pragma once
#include "ECBase.h"

#define Engine EC::_ec
#define entityManager Engine->GetEntityManager()
#define componentManager Engine->GetComponentManager()

class ECBase;

namespace EC {
	extern ECBase* _ec;
	void Initialize();
	void Finalize();

}

