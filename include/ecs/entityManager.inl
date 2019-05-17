std::ostream& operator<<(std::ostream& o, Vec3& v)
{
    o << '(' << v.x << ", " << v.y << ", " << v.z << ')';
    return o;
}

uint32 EntityManager::entityID = 0;
Array<Entity*> EntityManager::entities;

void EmptyEntity::init(const uint32 _ID)
{
    ID = _ID;
    Transform* transform = ComponentManager::createComponent<Transform>(ID);
    components.push_back(transform);
}

void EmptyEntity::destroy()
{
    //
}

void EmptyEntity::printComponents()
{
    Transform* transform = (Transform*)components[0];
    std::cout << "TRANSFORM COMPONENT:\n--------------------" << std::endl;
    std::cout << "Position:\t";
    std::cout << transform->position << std::endl;
    std::cout << "Rotation:\t";
    std::cout << transform->rotation << std::endl;
    std::cout << "Scale:\t\t";
    std::cout << transform->scale << std::endl;
    std::cout << std::endl;
}

template <typename E>
EntityID EntityManager::createEntity()
{
    // Ensure The Type is actually an Entity
    static_assert(std::is_base_of<Entity, E>::value, "The T type MUST be an Entity");

    E* entity = new E;
    entity->init(entityID);

    entities.push_back(entity);

    return entityID++;
}

void EntityManager::printEntities()
{
    for(size_t i = 0; i < entities.size(); ++i)
    {
        std::cout << "--------------------------------\n";
        std::cout << "ENTITY NR. " << i << " PRINTING!\n";
        std::cout << "--------------------------------\n";
        entities[i]->printComponents();
    }
}
