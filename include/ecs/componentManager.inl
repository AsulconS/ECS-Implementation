// The Components are registered into the Manager
template <typename T>
const uint32 Component<T>::ID(ComponentManager::registerComponent());

template <typename T>
const uint32 Component<T>::SIZE(sizeof(T));

template <typename C>
C* ComponentManager::getComponent(EntityID entityID)
{
    // Static Assertion: The type must be a component
    static_assert(std::is_base_of<BaseComponent, C>::value, "|| THE C TYPE MUST BE A *COMPONENT* ||");

    size_t index;
    getComponentInternal<C>(entityID, &index, true);
}

template <typename C>
C* ComponentManager::createComponent(EntityID entityID)
{
    // Static Assertion: The type must be a component
    static_assert(std::is_base_of<BaseComponent, C>::value, "|| THE C TYPE MUST BE A *COMPONENT* ||");

    size_t index;
    if(getComponentInternal<C>(entityID, &index, false) != NULL)
    {
        std::cerr << "This Entity already has this component!" << std::endl;
        return NULL;
    }
    if(index == componentMemory[C::ID].size())
        componentMemory[C::ID].resize(index + C::SIZE);
    else
        for(int i = 0; i < C::SIZE; ++i)
            componentMemory[C::ID].insert(componentMemory[C::ID].begin() + index, 0);
    
    C* component = new(&componentMemory[C::ID][index]) C;
    component->entity = entityID;

    return component;
}

template <typename C>
void ComponentManager::deleteComponent(EntityID entityID)
{
    // Static Assertion: The type must be a component
    static_assert(std::is_base_of<BaseComponent, C>::value, "|| THE C TYPE MUST BE A *COMPONENT* ||");

    size_t index;
    if(getComponentInternal<C>(entityID, &index, false) == NULL)
    {
        std::cerr << "This Component doesn't exist" << std::endl;
        return;
    }

    C* component = (C*)&componentMemory[C::ID][index];
    component->entity = -1;

    for(int i = 0; i < C::SIZE; ++i)
        componentMemory[C::ID].insert(componentMemory[C::ID].begin() + index, 0);
}

template <typename C>
Array<uint8>& ComponentManager::getComponentMemory()
{
    // Static Assertion: The type must be a component
    static_assert(std::is_base_of<BaseComponent, C>::value, "|| THE C TYPE MUST BE A *COMPONENT* ||");

    return componentMemory[C::ID];
}

template <typename C>
void ComponentManager::printComponents()
{
    // Static Assertion: The type must be a component
    static_assert(std::is_base_of<BaseComponent, C>::value, "|| THE C TYPE MUST BE A *COMPONENT* ||");

    size_t size = componentMemory[C::ID].size() / C::SIZE;
    C* cptr = (C*)&componentMemory[C::ID][0];
    for(size_t i = 0; i < size; ++i)
        std::cout << (cptr + i)->entity << std::endl;
}

template <typename C>
C* ComponentManager::getComponentInternal(EntityID entityID, size_t* index, bool prompt)
{
    // Static Assertion: The type must be a component
    static_assert(std::is_base_of<BaseComponent, C>::value, "|| THE C TYPE MUST BE A *COMPONENT* ||");

    // Checks if there's at least one component of the C Type
    if(componentMemory[C::ID].size() == 0)
    {
        if (prompt) std::cerr << "The Entity does'n have this component!" << std::endl;
        *index = 0;
        return NULL;
    }

    // The size is equal to the Size in Bytes of the Memory in The Size of the component
    size_t size = componentMemory[C::ID].size() / C::SIZE;
    C* cptr = (C*)&componentMemory[C::ID][0];

    // Here we are a simple Binary Search
    size_t i = 0;
    size_t j = size - 1;
    size_t m = 0;
    while(i <= j)
    {
        m = (i + j) / 2;
        if((cptr + m)->entity == entityID)
        {
            *index = m * C::SIZE; // The actual index where the Component were found
            return cptr + m;
        }
        else if((cptr + m)->entity < entityID)
            i = m + 1;
        else
            j = m - 1;
    }

    if (prompt) std::cerr << "The Entity does'n have this component!" << std::endl;
    *index = i * C::SIZE; // The actual index where the Component could be placed
    return NULL;
}
