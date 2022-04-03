#include "camera.h"

#include <entity.h>

Camera::~Camera()
{
    
}

glm::mat4 Camera::GetViewMatrix()
{
    return glm::lookAt(holding_entity_->get_transform()->position_,
                       holding_entity_->get_transform()->position_ + glm::vec3(0, 0, -1),
                       glm::vec3(0, 1, 0));
}

glm::mat4 Camera::GetProjectionMatrix()
{
    // TODO(Bassel): remove hard coded
    return glm::perspective(glm::radians(45.0f), (float)1024 / (float)720, 0.1f, 100.0f);
}