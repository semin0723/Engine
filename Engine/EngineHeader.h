#pragma once

#include "framework.h"
#include "STL.h"


#include <d2d1_1helper.h>

#include "../Engine/Base/Render/D2DRender.h"
#include "../Engine/Base/Time/TimeSystem.h"

using ULL = unsigned long long;

using TypeId = size_t;
using ObjectId = size_t;

static const ObjectId	INVALID_OBJECT_ID = (std::numeric_limits<ObjectId>::max)();
static const TypeId		INVALID_TYPE_ID = (std::numeric_limits<TypeId>::max)();

class ComponentManager;
class EntityManager;