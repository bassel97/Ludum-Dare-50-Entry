#ifndef LDGAME_ECS_TRANSFORM_H_
#define LDGAME_ECS_TRANSFORM_H_

#include <glad/glad.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

#include <component.h>

class Transform : public Component
{
public:
    Transform(glm::vec3 position = glm::vec3(0.0f), glm::vec3 rotation_euler = glm::vec3(0.0f), glm::vec3 scale = glm::vec3(1.0f))
        : position_(position), rotation_euler_(rotation_euler), scale_(scale)
    {
    }

    glm::mat4 get_model_matrix() const
    {
        glm::mat4 transform = glm::translate(glm::mat4(1.0), position_);
        transform = glm::scale(transform, scale_);
        return transform;
    }

    glm::vec3 position_;
    glm::vec3 rotation_euler_;
    glm::vec3 scale_;
};

#endif // LDGAME_ECS_TRANSFORM_H_