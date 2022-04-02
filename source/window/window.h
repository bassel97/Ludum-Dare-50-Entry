#ifndef LDGAME_WINDOW_WINDOW_H_
#define LDGAME_WINDOW_WINDOW_H_

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window
{
public:
    Window(int width, int height);
    ~Window();

    void RunLoop();

private:
    Window(Window &&) = delete;
    Window &operator=(Window &&) = delete;

    int width_, height_;
    GLFWwindow *window;
};

#endif // LDGAME_WINDOW_WINDOW_H_