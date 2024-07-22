#pragma once
#include "IEntity.h"

template<class E>
class Entity :
    public IEntity
{
public:
    Entity() {}
    virtual ~Entity() {}
    static const EntityTypeId ENTITY_TYPE_ID;

    virtual const EntityTypeId GetEntityTypeId() const override {
        return ENTITY_TYPE_ID;
    }
};

template<class E>
const EntityTypeId Entity<E>::ENTITY_TYPE_ID = FamilyTypeId<IEntity>::Get<E>();