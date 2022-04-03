#include "transform.h"
#include <entity.h>

glm::mat4 Transform::get_model_matrix() const
{
    glm::mat4 parent_model_matrix = glm::mat4(1.0f);
    if (holding_entity_->parent_entity_)
        parent_model_matrix = holding_entity_->parent_entity_->get_transform()->get_model_matrix();

    glm::mat4 transform = glm::translate(parent_model_matrix, position_);
    transform = glm::scale(transform, scale_);
    return transform;
}
