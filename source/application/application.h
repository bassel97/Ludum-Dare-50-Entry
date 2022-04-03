#ifndef LDGAME_APPLICATION_APPLICATION_H_
#define LDGAME_APPLICATION_APPLICATION_H_

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <ui.h>

class Application
{
public:
    Application(int width, int height);
    ~Application();

    virtual void Run();

protected:
    virtual void OnGameStart() = 0;
    virtual void OnGameUpdate(float) = 0;
    virtual void OnGameEnd() = 0;

    virtual void UIUpdate(float) = 0;

    GLFWwindow *window_;

private:
    Application(Application &&) = delete;
    Application &operator=(Application &&) = delete;

    int width_, height_;
    UI *ui_class_;

    float delta_time_ = 0.0f;
    float last_frame_ = 0.0f;
};

#endif // LDGAME_APPLICATION_APPLICATION_H_