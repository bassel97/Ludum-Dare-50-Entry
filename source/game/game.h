#ifndef LDGAME_GAME_GAME_H_
#define LDGAME_GAME_GAME_H_

#include <gtc/type_ptr.hpp>

#include <application.h>
#include <ui.h>
#include <world.h>
#include <rendering-system.h>

class Game : public Application
{
public:
    Game(int width, int height);
    ~Game();
    void Run();

protected:
    void OnGameStart();
    void OnGameUpdate();
    void OnGameEnd();

    void UIUpdate();

    // bool show_demo_window = true;
    World *world_;

    Camera *main_camera_component_;
    Entity *camera_entity_;

    SquareModel *square_component;
    Transform *square_transform_component;
    Entity *square_entity;
};

#endif // LDGAME_GAME_GAME_H_