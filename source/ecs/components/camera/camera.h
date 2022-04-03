#ifndef LDGAME_ECS_CAMERA_H_
#define LDGAME_ECS_CAMERA_H_

#include <glad/glad.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

#include <vector>

#include <component.h>

class Camera : public Component
{
public:
    Camera()
    {
    }

    ~Camera();

    glm::mat4 GetViewMatrix();
    glm::mat4 GetProjectionMatrix();
};

#endif // LDGAME_ECS_CAMERA_H_