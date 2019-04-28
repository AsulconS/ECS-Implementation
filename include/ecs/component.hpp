#ifndef ECS_COMPONENT_H
#define ECS_COMPONENT_H

#include <iostream>

#include "system/common.hpp"
#include "dataStructures.hpp"

class ComponentManager
{
public:
    static uint32 registerComponent(size_t size);

    template <typename C>
    static C* getComponent(EntityID entityID);

    template <typename C>
    static void addComponent(EntityID entityID);

    template <typename C>
    static void printComponents();

    template <typename C>
    static Array<uint8>& getComponentMemory();

private:
    static uint32 componentID;
    static Array<Array<uint8>> componentMemory;

    // This template is restricted for inherited Base Coponent Type
    template <typename C>
    static C* getComponentInternal(EntityID entityID, size_t* index, bool prompt);
};

struct BaseComponent
{
    EntityID entity;
};

template <typename T>
struct Component : public BaseComponent
{
    static const uint32 ID;
    static const uint32 SIZE;
};

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

struct TestComponent : public Component<TestComponent>
{
    float x;
};

struct CharStruct : public Component<CharStruct>
{
    char c1;
    char c2;
    char c3;
};

#endif // ECS_COMPONENT
