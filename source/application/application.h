
#ifndef LDGAME_APPLICATION_APPLICATION_H_
#define LDGAME_APPLICATION_APPLICATION_H_

#include <iostream>

#include <window.h>

class Application
{
public:
    Application();
    ~Application();
    
    void Run();

private:
    Application(Application &&) = delete;
    Application &operator=(Application &&) = delete;

    Window *window;
};

#endif // LDGAME_APPLICATION_APPLICATION_H_