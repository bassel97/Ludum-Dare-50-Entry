#include "application.h"

Application::Application()
{
    window = new Window(1024, 720);
}

Application::~Application()
{
    delete window;
}

void Application::Run()
{
    window->RunLoop();
}