void MovementSystem::init()
{
    for(size_t i = 0; i < 10; ++i)
        entities.createEntity();
}

void MovementSystem::update()
{
    entities.printEntities();

    std::cout << "MEMORY:" << std::endl;
    List<BaseComponent*>& memory = ComponentManager::getComponentMemory<Transform>();
    List<BaseComponent*>::iterator i;
    for(i = memory.begin(); i != memory.end(); ++i)
        std::cout << ((Transform*)(*i))->position << std::endl;
}

void MovementSystem::destroy()
{
    entities.clear();
}
