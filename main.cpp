#define ECS_IMPLEMENTATION
#include "ecs.hpp"

int main()
{
    CharStruct::ID;

    MovementSystem movementSystem;
    movementSystem.init();
    movementSystem.update();
    movementSystem.destroy();

    return 0;
}
