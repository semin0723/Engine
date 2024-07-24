#pragma once
#include "ECBase.h"

#define Engine _ec
#define EntityManager Engine->GetEntityManager();
#define ComponentManager Engine->GetComponentManager();

class ECBase;

extern ECBase* _ec;
void Initialize();
void Finalize();

