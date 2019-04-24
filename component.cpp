#include "ecs/component.hpp"

Array<size_t> ComponentManager::componentSizes;
Array<Array<uint8>> ComponentManager::componentMemory;

uint32 ComponentManager::registerComponent(size_t size)
{
    uint32 componentID = componentSizes.size();
    componentSizes.push_back(size);
    componentMemory.push_back(Array<uint8>(0, 0));
    return componentID;
}
