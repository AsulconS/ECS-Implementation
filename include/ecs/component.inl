template <typename T>
const uint32 Component<T>::ID(ComponentManager::registerComponent(sizeof(T)));

template <typename C>
C* ComponentManager::getComponent(EntityID entityID)
{
    getComponentInternal<C>(entityID, true);
}

template <typename C>
void ComponentManager::addComponent(EntityID entityID)
{
    if(getComponentInternal<C>(entityID, false) != NULL)
    {
        std::cerr << "This Entity already has this component!" << std::endl;
        return;
    }
    uint32 index = componentMemory[C::ID].size();
    componentMemory[C::ID].resize(index + componentSizes[C::ID]);
    C* component = new(&componentMemory[C::ID][index]) C;
    component->entity = entityID;
}

template <typename C>
C* ComponentManager::getComponentInternal(EntityID entityID, bool getting)
{
    // Checks if there's at least one component of the C Type
    if(componentMemory[C::ID].size() == 0)
    {
        if (getting) std::cerr << "The Entity does'n have this component!" << std::endl;
        return NULL;
    }

    uint8* limit = &componentMemory[C::ID][componentMemory[C::ID].size() - 1]; // This is the address of the last component
    uint8* ptr = &componentMemory[C::ID][0]; // This is the address of the first component
    C* validator = (C*)ptr; // This is the caster
    while(validator->entity != entityID)
    {
        ptr += componentSizes[C::ID]; // Get the offset of the components

        if(ptr < limit)
            validator = (C*)ptr; // Check if gets out of bounds
        else
        {
            if (getting) std::cerr << "The Entity does'n have this component!" << std::endl;
            return NULL;
        }
    }
    return validator;
}
