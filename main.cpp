#include "ecs/component.hpp"

int main()
{
    TestComponent3::ID;

    ComponentManager::createComponent<Transform>(0);
    ComponentManager::createComponent<TestComponent2>(0);

    Transform* transform = ComponentManager::getComponent<Transform>(0);
    TestComponent2* test = ComponentManager::getComponent<TestComponent2>(0);

    std::cout << transform->position.x << ' ' << transform->position.y << ' ' << transform->position.z << std::endl;
    std::cout << transform->rotation.x << ' ' << transform->rotation.y << ' ' << transform->rotation.z << std::endl;
    std::cout << transform->scale.x    << ' ' << transform->scale.y    << ' ' << transform->scale.z    << std::endl;

    std::cout << test->x << std::endl;

    transform->position = { 2.5f, 1360.0f, 17.5f };
    transform->rotation = { 3.5f, 2360.0f, 18.5f };
    transform->scale    = { 4.5f, 3360.0f, 19.5f };
    test->x = 0.5f;

    std::cout << transform->position.x << ' ' << transform->position.y << ' ' << transform->position.z << std::endl;
    std::cout << transform->rotation.x << ' ' << transform->rotation.y << ' ' << transform->rotation.z << std::endl;
    std::cout << transform->scale.x    << ' ' << transform->scale.y    << ' ' << transform->scale.z    << std::endl;

    std::cout << test->x << std::endl;

    return 0;
}
