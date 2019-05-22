#define ECS_IMPLEMENTATION
#include "ecs.hpp"

int main()
{
    CharStruct::ID;

    MovementSystem::init();
    MovementSystem::update();
    MovementSystem::destroy();

    return 0;
}
