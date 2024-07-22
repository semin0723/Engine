#include "FamilyTypeId.h"

class IEntity;
class IComponent;

ULL FamilyTypeId<IEntity>::_typeCount = 0u;
ULL FamilyTypeId<IComponent>::_typeCount = 0u;

template class FamilyTypeId<IEntity>;
template class FamilyTypeId<IComponent>;