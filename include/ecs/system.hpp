#ifndef ECS_SYSTEM_H
#define ECS_SYSTEM_H

#include "ecs/entityManager.hpp"

class MovementSystem
{
public:
    static void init();
    static void update();
    static void destroy();

private:
    static EntityManager<EmptyEntity> entities;
};

#endif // ECS_SYSTEM_H
