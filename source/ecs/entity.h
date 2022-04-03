#ifndef LDGAME_ECS_Entity_H_
#define LDGAME_ECS_Entity_H_

#include <json.hpp>

#include "component.h"
#include "components/camera/camera.h"
#include "components/transform/transform.h"

class Entity
{
public:
    Entity(nlohmann::json entity_data = NULL)
    {
    }

    ~Entity()
    {
        for (Component *component : components_)
        {
            delete component;
        }
    }

    Transform *get_transform()
    {
        return transform_;
    }

    void AddComponent(Component *component)
    {
        component->holding_entity_ = this;
        components_.push_back(component);

        Transform *transform_component = dynamic_cast<Transform *>(component);
        if (transform_component != NULL)
        {
            transform_ = transform_component;
        }
    }

    template <typename T>
    T *get_component()
    {
        for (Component *component : components_)
        {
            T *childComponent = dynamic_cast<T *>(component);
            if (childComponent)
                return childComponent;
        }
        return NULL;
    }

private:
    Transform *transform_;
    std::vector<Component *> components_;
};

#endif // LDGAME_ECS_Entity_H_