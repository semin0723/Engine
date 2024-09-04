#pragma once
#include "IEntity.h"
#include "EventListener.h"

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

    virtual void Initialize() {}
};

template<class E>
const EntityTypeId Entity<E>::ENTITY_TYPE_ID = FamilyTypeId<IEntity>::Get<E>();