
#ifndef LDGAME_GAME_GAME_H_
#define LDGAME_GAME_GAME_H_

#include <application.h>
#include <ui.h>
#include <world.h>

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

    bool show_demo_window = true;
};

#endif // LDGAME_GAME_GAME_H_