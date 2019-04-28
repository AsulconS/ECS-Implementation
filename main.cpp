#define ECS_IMPLEMENTATION
#include "ecs.hpp"

int main()
{
    CharStruct::ID;

    ComponentManager::addComponent<Transform>(0);
    ComponentManager::addComponent<Transform>(1);
    ComponentManager::addComponent<Transform>(2);
    ComponentManager::addComponent<TestComponent>(0);

    Transform* transform = ComponentManager::getComponent<Transform>(0);
    TestComponent* test  = ComponentManager::getComponent<TestComponent>(0);

    std::cout << "Position:\t";
    std::cout << transform->position.x << ' ' << transform->position.y << ' ' << transform->position.z << std::endl;
    std::cout << "Rotation:\t";
    std::cout << transform->rotation.x << ' ' << transform->rotation.y << ' ' << transform->rotation.z << std::endl;
    std::cout << "Scale:\t\t";
    std::cout << transform->scale.x    << ' ' << transform->scale.y    << ' ' << transform->scale.z    << std::endl;

    std::cout << "Value:\t\t" << test->x << '\n' << std::endl;

    transform->position = { 2.5f, 1360.0f, 17.5f };
    transform->rotation = { 3.5f, 2360.0f, 18.5f };
    transform->scale    = { 4.5f, 3360.0f, 19.5f };
    test->x = 0.5f;

    std::cout << "Position:\t";
    std::cout << transform->position.x << ' ' << transform->position.y << ' ' << transform->position.z << std::endl;
    std::cout << "Rotation:\t";
    std::cout << transform->rotation.x << ' ' << transform->rotation.y << ' ' << transform->rotation.z << std::endl;
    std::cout << "Scale:\t\t";
    std::cout << transform->scale.x    << ' ' << transform->scale.y    << ' ' << transform->scale.z    << std::endl;

    std::cout << "Value:\t\t" << test->x << '\n' << std::endl;

    MovementSystem movementSystem;
    movementSystem.printComponents();

    return 0;
}
