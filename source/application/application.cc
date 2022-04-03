#include "application.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

Application::Application(int width, int height) : width_(width), height_(height)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window_ = glfwCreateWindow(width_, height_, "LD Game", NULL, NULL);
    if (window_ == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window_);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }

    // SET ICON
    GLFWimage images[1];
    images[0].pixels = stbi_load("assets/timer_icon.png", &images[0].width, &images[0].height, 0, 4);
    glfwSetWindowIcon(window_, 1, images);
    stbi_image_free(images[0].pixels);

    ui_class_ = new UI(window_);
}

Application::~Application()
{
    delete ui_class_;

    glfwTerminate();
}

void Application::Run()
{
    OnGameStart();
    // render loop
    // -----------

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    while (!glfwWindowShouldClose(window_))
    {
        float currentFrame = static_cast<float>(glfwGetTime());
        delta_time_ = currentFrame - last_frame_;
        last_frame_ = currentFrame;

        ui_class_->StartImGUIFrame();

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        UIUpdate(delta_time_);
        OnGameUpdate(delta_time_);

        ui_class_->RenderImGUIFrame();

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window_);
        glfwPollEvents();
    }
    OnGameEnd();
}