MovementSystem::MovementSystem() : BaseSystem()
{
    Array<uint8>& componentMemory = ComponentManager::getComponentMemory<Transform>();
    Transform* cIterator = (Transform*)&componentMemory;
    size_t size = componentMemory.size() / Transform::SIZE;
    std::cout << "THE SIZE IS " << size << std::endl;
    for(size_t i = 0; i < size; ++i)
        components[cIterator->entity].push_back(cIterator++);
}

void MovementSystem::printComponents(EntityID entityID)
{
    for(size_t i = 0; i < components[entityID].size(); ++i)
        std::cout << components[entityID][i]->entity << std::endl;
}
