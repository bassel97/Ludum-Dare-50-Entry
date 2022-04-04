#include "game.h"

Game::Game(int width, int height) : Application(width, height)
{
    glfwSetWindowTitle(window_, "The Deadline Game");

    world_ = new World();
    Camera *main_camera_component = new Camera();
    Transform *main_camera_transform_component = new Transform();
    camera_entity_ = new Entity();
    camera_entity_->AddComponent(main_camera_component);
    camera_entity_->AddComponent(main_camera_transform_component);
    main_camera_transform_component->position_ = glm::vec3(0, 0, 20);
    world_->AddEntity(camera_entity_);

    /********************************Player************************************/
    player_model_ = new SquareModel(&square_mesh_);
    player_box_collider_ = new BoxCollider2D();
    player_transform_component_ = new Transform();

    player_entity_ = new Entity();
    player_entity_->AddComponent(player_model_);
    player_entity_->AddComponent(player_box_collider_);
    player_entity_->AddComponent(player_transform_component_);

    player_transform_component_->position_ = glm::vec3(2.5f, 0, 0);

    player_box_collider_->tag = "Player";
    player_box_collider_->speed_ = glm::vec3(dead_line_horz_speed, 0, 0);

    player_model_->color_ = glm::vec3(1.0f);

    world_->AddEntity(player_entity_);

    SquareModel *eye_square_component = new SquareModel(&square_mesh_);
    Transform *eye_square_transform_component = new Transform();
    Entity *eye_square_entity = new Entity();
    eye_square_entity->AddComponent(eye_square_component);
    eye_square_entity->AddComponent(eye_square_transform_component);
    eye_square_transform_component->position_ = glm::vec3(0.3f, 0.25f, 0.1f);
    eye_square_transform_component->scale_ = glm::vec3(0.25f, 0.25f, 0.25f);
    eye_square_entity->parent_entity_ = player_entity_;
    eye_square_component->color_ = glm::vec3(0.0f);
    world_->AddEntity(eye_square_entity);

    eye_square_component = new SquareModel(&square_mesh_);
    eye_square_transform_component = new Transform();
    eye_square_entity = new Entity();
    eye_square_entity->AddComponent(eye_square_component);
    eye_square_entity->AddComponent(eye_square_transform_component);
    eye_square_transform_component->position_ = glm::vec3(-0.05f, 0.25f, 0.1f);
    eye_square_transform_component->scale_ = glm::vec3(0.25f, 0.25f, 0.25f);
    eye_square_entity->parent_entity_ = player_entity_;
    eye_square_component->color_ = glm::vec3(0.0f);
    world_->AddEntity(eye_square_entity);
    /********************************Player************************************/

    /********************************Border************************************/
    SquareModel *barrier_model = new SquareModel(&square_mesh_);
    Transform *barrier_transform = new Transform();
    BoxCollider2D *barrier_collider = new BoxCollider2D();
    Entity *barrier_entity = new Entity();
    barrier_collider->static_ = true;
    barrier_entity->AddComponent(barrier_model);
    barrier_entity->AddComponent(barrier_transform);
    barrier_entity->AddComponent(barrier_collider);
    barrier_transform->position_ = glm::vec3(0.0f, 7.8f, 0.0f);
    barrier_transform->scale_ = glm::vec3(10000.0f, 1.0f, 0.0f);
    barrier_model->color_ = glm::vec3(0.15f);
    world_->AddEntity(barrier_entity);

    barrier_model = new SquareModel(&square_mesh_);
    barrier_transform = new Transform();
    barrier_collider = new BoxCollider2D();
    barrier_entity = new Entity();
    barrier_collider->static_ = true;
    barrier_entity->AddComponent(barrier_model);
    barrier_entity->AddComponent(barrier_transform);
    barrier_entity->AddComponent(barrier_collider);
    barrier_transform->position_ = glm::vec3(0.0f, -7.8f, 0.0f);
    barrier_transform->scale_ = glm::vec3(10000.0f, 1.0f, 0.0f);
    barrier_model->color_ = glm::vec3(0.15f);
    world_->AddEntity(barrier_entity);

    /*barrier_model = new SquareModel(&square_mesh_);
    barrier_transform = new Transform();
    barrier_collider = new BoxCollider2D();
    barrier_entity = new Entity();
    barrier_collider->static_ = true;
    barrier_entity->AddComponent(barrier_model);
    barrier_entity->AddComponent(barrier_transform);
    barrier_entity->AddComponent(barrier_collider);
    barrier_transform->position_ = glm::vec3(3.0f, 0.0f, 0.0f);
    barrier_transform->scale_ = glm::vec3(1.0f, 1.0f, 0.0f);
    barrier_model->color_ = glm::vec3(0.15f, 0.55f, 1.0f);
    world_->AddEntity(barrier_entity);*/
    /********************************Border************************************/

    barrier_model = new SquareModel(&square_mesh_);
    barrier_transform = new Transform();
    barrier_collider = new BoxCollider2D();
    deadline_entity_ = new Entity();
    deadline_entity_->AddComponent(barrier_model);
    deadline_entity_->AddComponent(barrier_transform);
    deadline_entity_->AddComponent(barrier_collider);
    barrier_transform->position_ = glm::vec3(-10.0f, 0.0f, 0.2f);
    barrier_transform->scale_ = glm::vec3(1.0f, 14.5f, 0.0f);
    barrier_model->color_ = glm::vec3(0.95f, 0.25f, 0.1f);
    world_->AddEntity(deadline_entity_);

    for (size_t i = 0; i < 10; i++)
    {
        barriers_.push_back(CreateBarrierEntity(glm::vec3((i + 3) * 5, -5 + (rand() % 10), 0.0), glm::vec3(0.2, (rand() % 10) / 10.0, 0.2)));
    }
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
    for (Entity *barrier : barriers_)
    {
        if ((barrier->get_transform()->position_.x - camera_entity_->get_transform()->position_.x) < -13)
        {
            barrier->get_transform()->position_.x += 50;
        }
    }

    score_ += delta_time;

    camera_entity_->get_transform()->position_.x += dead_line_horz_speed * delta_time;

    deadline_entity_->get_transform()->position_.x += dead_line_horz_speed * delta_time;

    RenderingSystem::RenderScene(world_);
    PhysicsSystem::ApplyBoxAABB(world_, delta_time);
}

void Game::OnGameEnd()
{
}

void Game::UIUpdate(float delta_time)
{
    ImGui::Begin("Player"); 

    ImGui::SliderFloat("Dodge Tasks", &glm::value_ptr(player_box_collider_->speed_)[1], -10.0f, 10.0f);

    ImGui::Text("(Score : %.5f)", score_);

    ImGui::End();
}

Entity *Game::CreateBarrierEntity(glm::vec3 position, glm::vec3 color)
{
    SquareModel *model = new SquareModel(&square_mesh_);
    Transform *transform = new Transform();
    BoxCollider2D *collider = new BoxCollider2D();
    Entity *entity = new Entity();
    entity->AddComponent(model);
    entity->AddComponent(transform);
    entity->AddComponent(collider);
    transform->position_ = position;
    transform->scale_ = glm::vec3(1.0f, 8.0f, 0.0f);
    model->color_ = color;
    world_->AddEntity(entity);

    return entity;
}