
#include <iostream>

class Application
{
private:
    Application(Application &&) = delete;
    Application &operator=(Application &&) = delete;

public:
    Application();
    void Run();
};