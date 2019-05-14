#ifndef ECS_COMPONENT_H
#define ECS_COMPONENT_H

#include "system/common.hpp"

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

struct BoxCollider : public Component<BoxCollider>
{
    bool isTrigger;
    Vec3 center;
    Vec3 size;
};

struct CharStruct : public Component<CharStruct>
{
    char c1;
    char c2;
    char c3;
};

#endif // ECS_COMPONENT_H
