#ifndef ECS_ENTITY_MANAGER_H
#define ECS_ENTITY_MANAGER_H

#include "ecs/entity.hpp"

class EntityManager
{
public:
    template <typename E>
    static EntityID createEntity();

    static void printEntities();

private:
    static uint32 entityID;
    static Array<Entity*> entities;
};

#endif // ECS_ENTITY_MANAGER_H
