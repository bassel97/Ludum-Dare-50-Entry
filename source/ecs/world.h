#ifndef LDGAME_ECS_WORLD_H_
#define LDGAME_ECS_WORLD_H_

#include <vector>

#include <json.hpp>

#include "entity.h"

class World
{
public:
    World(std::string name = "Empty Scene", nlohmann::json data = NULL)
    {
    }

    ~World()
    {
        for (Entity *entity : entities_)
        {
            delete entity;
        }
    }

    void AddEntity(Entity *entity)
    {
        entities_.push_back(entity);
    }

    template <typename T>
    Entity *get_entity_with_component()
    {
        for (Entity *entity : entities_)
        {
            if (entity->get_component<T>() != NULL)
                return entity;
        }
        return NULL;
    }

    template <typename T>
    std::vector<Entity *> get_entities_with_component()
    {
        std::vector<Entity *> entities_with_component;
        for (Entity *entity : entities_)
        {
            if (entity->get_component<T>() != NULL)
                entities_with_component.push_back(entity);
        }
        return entities_with_component;
    }

private:
    std::vector<Entity *> entities_;
};

#endif // LDGAME_ECS_WORLD_H_