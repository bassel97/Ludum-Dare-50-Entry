#include <Windows.h>
#include <game.h>

int wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    Game(1024, 720).Run();
}