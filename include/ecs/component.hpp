#ifndef ECS_COMPONENT_H
#define ECS_COMPONENT_H

#include <iostream>

#include "system/common.hpp"
#include "dataStructures.hpp"

typedef uint32 EntityID;

class ComponentManager
{
public:
    static uint32 registerComponent(size_t size);

    template <typename C>
    static C* getComponentInternal(EntityID entityID, bool getting)
    {
        if(componentMemory[C::ID].size() == 0)
        {
            if (getting) std::cerr << "The Entity does'n have this component!" << std::endl;
            return NULL;
        }
        uint8* limit = &componentMemory[C::ID][componentMemory[C::ID].size() - 1]; // This is the address of the last component
        uint8* ptr = &componentMemory[C::ID][0]; // This is the address of the first component
        C* validator = (C*)ptr;
        while(validator->entity != entityID)
        {
            ptr += componentSizes[C::ID];
            if(ptr < limit)
                validator = (C*)ptr;
            else
            {
                if (getting) std::cerr << "The Entity does'n have this component!" << std::endl;
                return NULL;
            }
        }
        return validator;
    }

    template <typename C>
    static C* getComponent(EntityID entityID)
    {
        getComponentInternal<C>(entityID, true);
    }

    template <typename C>
    static void createComponent(EntityID entityID)
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

private:
    static Array<size_t> componentSizes;
    static Array<Array<uint8>> componentMemory;
};

struct BaseComponent
{
    EntityID entity;
};

template <typename T>
struct Component : public BaseComponent
{
    static const uint32 ID;
};

template <typename T>
const uint32 Component<T>::ID(ComponentManager::registerComponent(sizeof(T)));

struct Vec3
{
    float x;
    float y;
    float z;
};

struct Transform : public Component<Transform>
{
    Vec3 position;
    Vec3 rotation;
    Vec3 scale;
};

struct TestComponent2 : public Component<TestComponent2>
{
    float x;
};

struct TestComponent3 : public Component<TestComponent3>
{
    char c1;
    char c2;
    char c3;
};

#endif // ECS_COMPONENT
