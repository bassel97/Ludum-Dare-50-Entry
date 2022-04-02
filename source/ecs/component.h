#ifndef LDGAME_ECS_COMPONENT_H_
#define LDGAME_ECS_COMPONENT_H_

#include "components/shader/shader.h"

class Entity;

class Component
{
public:
private:
    Entity *holding_entity_;
};

#endif // LDGAME_ECS_COMPONENT_H_