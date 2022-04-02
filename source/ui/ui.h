#ifndef LDGAME_UI_UI_H_
#define LDGAME_UI_UI_H_
#include <iostream>

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

#include <GLFW/glfw3.h>

class UI
{
public:
    UI(GLFWwindow *window);
    ~UI();

    void StartImGUIFrame();
    void RenderImGUIFrame();

private:
    UI(UI &&) = delete;
    UI &operator=(UI &&) = delete;

    GLFWwindow *window_;
    ImGuiIO *io_;
};

#endif // LDGAME_UI_UI_H_