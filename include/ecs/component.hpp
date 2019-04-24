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
    static C* getComponent(EntityID entityID);

    template <typename C>
    static void addComponent(EntityID entityID);

private:
    static Array<size_t> componentSizes;
    static Array<Array<uint8>> componentMemory;

    // This template is restricted for inherited Base Coponent Type
    template <typename C>
    static C* getComponentInternal(EntityID entityID, bool getting);
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
