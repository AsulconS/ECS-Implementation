#include "ecs/component.hpp"

uint32 ComponentManager::componentID = 0;
Array<Array<uint8>> ComponentManager::componentMemory;

uint32 ComponentManager::registerComponent()
{
    componentMemory.push_back(Array<uint8>(0, 0));
    return componentID++;
}
