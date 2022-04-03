#include "game.h"

Game::Game(int width, int height) : Application(width, height)
{
    glfwSetWindowTitle(window_, "Main Game");

    world_ = new World();
    Camera *main_camera_component = new Camera();
    Transform *main_camera_transform_component = new Transform();
    Entity *camera_entity = new Entity();
    camera_entity->AddComponent(main_camera_component);
    camera_entity->AddComponent(main_camera_transform_component);
    main_camera_transform_component->position_ = glm::vec3(0, 0, 20);
    world_->AddEntity(camera_entity);

    player_model_ = new SquareModel(&square_mesh_);
    player_box_collider_ = new BoxCollider2D();
    player_transform_component_ = new Transform();
    player_entity_ = new Entity();
    player_entity_->AddComponent(player_model_);
    player_entity_->AddComponent(player_box_collider_);
    player_entity_->AddComponent(player_transform_component_);
    player_transform_component_->position_ = glm::vec3(0, 0, 0);
    player_transform_component_->position_ = glm::vec3(0, 0, 0);
    player_box_collider_->speed_ = glm::vec3(2.0f, 0.0f, 0.0f);
    player_model_->color_ = glm::vec3(1.0f);
    world_->AddEntity(player_entity_);

    SquareModel *eye_square_component = new SquareModel(&square_mesh_);
    Transform *eye_square_transform_component = new Transform();
    Entity *eye_square_entity = new Entity();
    eye_square_entity->AddComponent(eye_square_component);
    eye_square_entity->AddComponent(eye_square_transform_component);
    eye_square_transform_component->position_ = glm::vec3(0.6f, 0.5f, 0.1f);
    eye_square_transform_component->scale_ = glm::vec3(0.25f, 0.25f, 0.25f);
    eye_square_entity->parent_entity_ = player_entity_;
    eye_square_component->color_ = glm::vec3(0.0f);
    world_->AddEntity(eye_square_entity);

    eye_square_component = new SquareModel(&square_mesh_);
    eye_square_transform_component = new Transform();
    eye_square_entity = new Entity();
    eye_square_entity->AddComponent(eye_square_component);
    eye_square_entity->AddComponent(eye_square_transform_component);
    eye_square_transform_component->position_ = glm::vec3(-0.1f, 0.5f, 0.1f);
    eye_square_transform_component->scale_ = glm::vec3(0.25f, 0.25f, 0.25f);
    eye_square_entity->parent_entity_ = player_entity_;
    eye_square_component->color_ = glm::vec3(0.0f);
    world_->AddEntity(eye_square_entity);

    SquareModel *barrier_model = new SquareModel(&square_mesh_);
    Transform *barrier_transform = new Transform();
    Entity *barrier_entity = new Entity();
    BoxCollider2D* barrier_collider = new BoxCollider2D();
    barrier_collider->static_ = true;
    barrier_entity->AddComponent(barrier_model);
    barrier_entity->AddComponent(barrier_transform);
    barrier_entity->AddComponent(barrier_collider);
    barrier_transform->position_ = glm::vec3(5.0f, 0.0f, 0.0f);
    barrier_model->color_ = glm::vec3(0.65f);
    world_->AddEntity(barrier_entity);
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

void Game::OnGameUpdate(float delta_time)
{
    RenderingSystem::RenderScene(world_);
    PhysicsSystem::ApplyBoxAABB(world_, delta_time);
}

void Game::OnGameEnd()
{
}

void Game::UIUpdate(float delta_time)
{
    ImGui::Begin("Hello UI"); // Create a window called "Hello, world!" and append into it.

    ImGui::SliderFloat3("Square position", glm::value_ptr(player_box_collider_->speed_), -1.0f, 1.0f);
    ImGui::ColorEdit3("Square color", glm::value_ptr(player_model_->color_));

    ImGui::Text("Application average %.3f ms/frame (%.1f FPS) (delta time %.5f)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate, delta_time);
    ImGui::End();
}