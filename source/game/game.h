#ifndef LDGAME_GAME_GAME_H_
#define LDGAME_GAME_GAME_H_

#include <gtc/type_ptr.hpp>

#include <application.h>
#include <ui.h>
#include <world.h>
#include <rendering-system.h>
#include <components/camera/camera.h>
#include <physics-system.h>

class Game : public Application
{
public:
    Game(int width, int height);
    ~Game();
    void Run();

protected:
    void OnGameStart();
    void OnGameUpdate(float);
    void OnGameEnd();

    void UIUpdate(float);

    Entity *CreateBarrierEntity(glm::vec3 position = glm::vec4(0.0f), glm::vec3 color = glm::vec4(1.0f));

    const float dead_line_horz_speed = 4.0f;

    SquareMesh square_mesh_;

    // bool show_demo_window = true;
    World *world_;

    Camera *main_camera_component_;
    Entity *camera_entity_;

    SquareModel *player_model_;
    BoxCollider2D *player_box_collider_;
    Transform *player_transform_component_;
    Entity *player_entity_, *deadline_entity_;

    std::vector<Entity*> barriers_;
    
    float score_ = 0;
};

#endif // LDGAME_GAME_GAME_H_