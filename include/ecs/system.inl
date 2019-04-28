template <typename C>
void BaseSystem::getMemory()
{
    Array<uint8>& componentMemory = ComponentManager::getComponentMemory<C>();
    C* cIterator = (C*)&componentMemory[0];
    size_t size = componentMemory.size() / C::SIZE;
    for(size_t i = 0; i < size; ++i)
        components[(cIterator + i)->entity].push_back(cIterator + i);
}

MovementSystem::MovementSystem() : BaseSystem()
{
    getMemory<Transform>();
    getMemory<TestComponent>();
}

void MovementSystem::printComponents()
{
    std::cout << "Entities in the Movement System: " << std::endl;
    Map<EntityID, Array<BaseComponent*>>::iterator i;
    for(i = components.begin(); i != components.end(); ++i)
        std::cout << "Entity " << i->first << " has " << i->second.size() << " components" << std::endl;
}
