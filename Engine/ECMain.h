#pragma once
#include "ECBase.h"

#ifndef _MAIN_ENGINE_
	#define Engine EC::_ec
	#define EntityManager Engine->GetEntityManager()
	#define ComponentManager Engine->GetComponentManager()
#endif

class ECBase;

namespace EC {
	extern ECBase* _ec;
	void Initialize();
	void Finalize();

}

