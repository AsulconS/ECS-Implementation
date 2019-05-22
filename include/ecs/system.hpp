#ifndef ECS_SYSTEM_H
#define ECS_SYSTEM_H

#include "ecs/entityManager.hpp"

class BaseSystem
{
public:
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void destroy() = 0;
};

class MovementSystem : public BaseSystem
{
public:
    virtual void init();
    virtual void update();
    virtual void destroy();

private:
    EntityManager<EmptyEntity> entities;
};

#endif // ECS_SYSTEM_H
