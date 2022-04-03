#ifndef LDGAME_ECS_RENDERINGSYSTEM_H_
#define LDGAME_ECS_RENDERINGSYSTEM_H_

#include <glm.hpp>

#include <world.h>
#include <components/camera/camera.h>
#include <components/model/square-model.h>

class RenderingSystem
{
public:
    static void RenderScene(World *world)
    {
        Camera *world_camera = world->get_entity_with_component<Camera>()->get_component<Camera>();

        std::vector<Entity *> squares_to_render = world->get_entities_with_component<SquareModel>();

        glm::mat4 projection_matrix = world_camera->GetProjectionMatrix();
        glm::mat4 view_matrix = world_camera->GetViewMatrix();

        for (Entity* square_to_render : squares_to_render)
        {
            Transform* square_transform = square_to_render->get_component<Transform>();
            SquareModel* square_model = square_to_render->get_component<SquareModel>();

            Shader* square_shader = square_model->get_shader();

            square_shader->setMat4("MVP", projection_matrix * view_matrix * square_transform->get_model_matrix());
            square_shader->setVec3("color", square_model->color_);

            square_model->Render();
        }
    }
};

#endif // LDGAME_ECS_RENDERINGSYSTEM_H_