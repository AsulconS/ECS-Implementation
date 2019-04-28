#include "ecs/component.hpp"

uint32 ComponentManager::componentIDs = 0;
Array<Array<uint8>> ComponentManager::componentMemory;

uint32 ComponentManager::registerComponent(size_t size)
{
    componentMemory.push_back(Array<uint8>(0, 0));
    return componentIDs++;
}
