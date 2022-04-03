#include "game.h"

Game::Game(int width, int height) : Application(width, height)
{
    glfwSetWindowTitle(window_, "Main Game");

    world_ = new World();
    Camera *main_camera_component = new Camera();
    Transform *main_transform_component = new Transform();
    Entity *camera_entity = new Entity();

    camera_entity->AddComponent(main_camera_component);
    camera_entity->AddComponent(main_transform_component);

    world_->AddEntity(camera_entity);

    square_component = new SquareModel();
    square_transform_component = new Transform();
    square_entity = new Entity();

    square_entity->AddComponent(square_component);
    square_entity->AddComponent(square_transform_component);

    square_transform_component->position_ = glm::vec3(0, 0, -5);

    world_->AddEntity(square_entity);
}

Game::~Game()
{
    delete world_;
}

void Game::Run()
{
    Application::Run();
}

void Game::OnGameStart()
{
}

void Game::OnGameUpdate()
{
    RenderingSystem::RenderScene(world_);
}

void Game::OnGameEnd()
{
}

void Game::UIUpdate()
{
    ImGui::Begin("Hello UI"); // Create a window called "Hello, world!" and append into it.

    ImGui::SliderFloat3("Square position", glm::value_ptr(square_transform_component->position_), -10.0f, 10.0f);
    ImGui::ColorEdit3("Square color", glm::value_ptr(square_component->color_));

    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    ImGui::End();
}