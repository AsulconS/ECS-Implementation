#define ECS_IMPLEMENTATION
#include "ecs.hpp"

std::ostream& operator<<(std::ostream& o, Vec3& v)
{
    o << '(' << v.x << ", " << v.y << ", " << v.z << ')';
    return o;
}

int main()
{
    CharStruct::ID;

    ComponentManager::addComponent<Transform>(0);
    ComponentManager::addComponent<Transform>(1);
    ComponentManager::addComponent<Transform>(2);
    ComponentManager::addComponent<BoxCollider>(0);

    Transform* transform = ComponentManager::getComponent<Transform>(0);
    BoxCollider* collider  = ComponentManager::getComponent<BoxCollider>(0);

    std::cout << "TRANSFORM COMPONENT:\n--------------------" << std::endl;
    std::cout << "Position:\t";
    std::cout << transform->position << std::endl;
    std::cout << "Rotation:\t";
    std::cout << transform->rotation << std::endl;
    std::cout << "Scale:\t\t";
    std::cout << transform->scale << std::endl;
    std::cout << std::endl;

    std::cout << "COLLIDER COMPONENT:\n-------------------" << std::endl;
    std::cout << "Center:\t\t" << collider->center << std::endl;
    std::cout << "Size:\t\t" << collider->size << std::endl;
    std::cout << std::endl;

    transform->position = { 2.5f, 1360.0f, 17.5f };
    transform->rotation = { 3.5f, 2360.0f, 18.5f };
    transform->scale    = { 4.5f, 3360.0f, 19.5f };
    collider->center = { 0.5f, 1.0f, 1.5f };
    collider->size   = { 2.0f, 2.5f, 3.0f };

    std::cout << "TRANSFORM COMPONENT:\n--------------------" << std::endl;
    std::cout << "Position:\t";
    std::cout << transform->position << std::endl;
    std::cout << "Rotation:\t";
    std::cout << transform->rotation << std::endl;
    std::cout << "Scale:\t\t";
    std::cout << transform->scale << std::endl;
    std::cout << std::endl;

    std::cout << "COLLIDER COMPONENT:\n-------------------" << std::endl;
    std::cout << "Center:\t\t" << collider->center << std::endl;
    std::cout << "Size:\t\t" << collider->size << std::endl;
    std::cout << std::endl;

    MovementSystem movementSystem;
    movementSystem.printComponents();

    return 0;
}
