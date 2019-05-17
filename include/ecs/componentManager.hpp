#ifndef ECS_COMPONENT_MANAGER_H
#define ECS_COMPONENT_MANAGER_H

#include <iostream>

#include "system/common.hpp"
#include "dataStructures.hpp"

#include "ecs/component.hpp"

/* Component Manger:
 * The Component Manager handles how to treat
 * the data into the component containers.
 * 
 * It doesn't has to know the specific type
 * of the component due to it's a Generic Templated
 * class, so C is the Component Type
 */
class ComponentManager
{
public:
    static uint32 registerComponent();

    template <typename C>
    static C* getComponent(EntityID entityID);

    template <typename C>
    static C* createComponent(EntityID entityID);
    template <typename C>
    static void deleteComponent(EntityID entityID);

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

#endif // ECS_COMPONENT_MANAGER_H
