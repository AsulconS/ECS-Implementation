#ifndef ECS_SYSTEM_H
#define ECS_SYSTEM_H

#include "ecs/component.hpp"

class BaseSystem
{
public:
    BaseSystem() {}

protected:
    Map<EntityID, Array<BaseComponent*>> components;

    template <typename C>
    void getMemory();
};

class MovementSystem : public BaseSystem
{
public:
    MovementSystem();

    void printComponents();
};

#endif // ECS_SYSTEM_H
