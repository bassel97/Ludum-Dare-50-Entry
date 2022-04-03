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

    SquareMesh square_mesh_;

    // bool show_demo_window = true;
    World *world_;

    Camera *main_camera_component_;
    Entity *camera_entity_;

    SquareModel *player_model_;
    BoxCollider2D *player_box_collider_;
    Transform *player_transform_component_;
    Entity *player_entity_;
};

#endif // LDGAME_GAME_GAME_H_