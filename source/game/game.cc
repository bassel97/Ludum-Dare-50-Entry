#include "game.h"

Game::Game(int width, int height) : Application(width, height)
{
    glfwSetWindowTitle(window_, "Main Game");
}

Game::~Game()
{
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
}

void Game::OnGameEnd()
{
}

void Game::UIUpdate()
{
    ImGui::Begin("Hello UI"); // Create a window called "Hello, world!" and append into it.

    if (ImGui::Button("Start")) // Buttons return true when clicked (most widgets return true when edited/activated)
        std::cout << "Start" << std::endl;

    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    ImGui::End();
}