#define ECS_IMPLEMENTATION
#include "ecs.hpp"

int main()
{
    CharStruct::ID;

    EntityID id = EntityManager::createEntity<EmptyEntity>();

    Transform* transform = ComponentManager::getComponent<Transform>(id);

    std::cout << "TRANSFORM COMPONENT OUTSIDE:\n----------------------------" << std::endl;
    std::cout << "Position:\t";
    std::cout << transform->position << std::endl;
    std::cout << "Rotation:\t";
    std::cout << transform->rotation << std::endl;
    std::cout << "Scale:\t\t";
    std::cout << transform->scale << std::endl;
    std::cout << std::endl;

    EntityManager::printEntities();

    return 0;
}
