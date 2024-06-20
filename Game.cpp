#include "Game.h"
#include <raymath.h>
#include "GlobalVars.h"

Game::Game()
{
    InitAudioDevice();
    eatSound = LoadSound("Sounds/FoodCollect.wav");
    hitSound = LoadSound("Sounds/Hit.wav");
}

void Game::Draw()
{
    snake.Draw();
    food.Draw();

    DrawRectangleLinesEx(rect, 5, g_globalVars.darkGreen);
    DrawText("Retro Snake", g_globalVars.offset - 5, 20, 40, g_globalVars.darkGreen);
    DrawText(TextFormat("%i",score),
             g_globalVars.offset - 5,
             g_globalVars.offset + g_globalVars.cellSize * g_globalVars.cellCount + 10,
             40,
             g_globalVars.darkGreen);
}

void Game::Update()
{
    snake.InputListener();
    SnakeMovementUpdater();
}

void Game::SnakeMovementUpdater()
{
    float currentTime = GetTime();
    if (currentTime - lastUpdateTime >= moveInterval)
    {
        lastUpdateTime = currentTime;

        snake.SnakeMovementUpdater();
        CheckCollision();
    }
}

void Game::CheckCollision()
{
    if (Vector2Equals(snake.body[0], food.position))
    {
        food.position = food.GenerateRandomPos(snake.body);
        snake.addSegment = true;
        score++;
        PlaySound(eatSound);
    }
    else
    {
        deque<Vector2> headlessBody = snake.body;
        headlessBody.pop_front();
        if (food.ElementInDeque(snake.body[0], headlessBody))
            GameOver();
    }
}

void Game::GameOver()
{
    PlaySound(hitSound); 
    snake.Reset();
    food.position = food.GenerateRandomPos(snake.body);
    score = 0;
}

Game::~Game()
{
    UnloadSound(eatSound);
    UnloadSound(hitSound);
    CloseAudioDevice();
}