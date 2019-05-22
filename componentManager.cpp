#include "ecs/componentManager.hpp"

uint32 ComponentManager::componentID = 0;
Vector<List<BaseComponent*>> ComponentManager::componentMemory;

uint32 ComponentManager::registerComponent()
{
    componentMemory.push_back(List<BaseComponent*>());
    return componentID++;
}
