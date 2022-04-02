#ifndef LDGAME_ECS_WORLD_H_
#define LDGAME_ECS_WORLD_H_

#include <vector>

#include <json.hpp>

#include "entity.h"

class World
{
public:
    World(std::string name, nlohmann::json data)
    {
        
    }

private:
    std::vector<Entity *> entities_;
};

#endif // LDGAME_ECS_WORLD_H_