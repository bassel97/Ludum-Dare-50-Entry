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

    void Render();
    void RenderDrawData();

private:
    UI(UI &&) = delete;
    UI &operator=(UI &&) = delete;

    GLFWwindow *window_;

    bool show_demo_window_ = true;
    bool show_another_window_ = false;
    ImVec4 clear_color_ = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    ImGuiIO* io;
    bool* p_open;
    bool opt_fullscreen = true;
    bool opt_padding = true;
    ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;
};

#endif // LDGAME_UI_UI_H_