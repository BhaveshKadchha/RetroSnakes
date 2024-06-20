#include "Snake.h"
#include "GlobalVars.h"
#include <raymath.h>
#include "DirectionEnum.h"
#include "Food.h"

void Snake::Draw()
{
    for (unsigned int i = 0; i < body.size(); i++)
    {
        Rectangle segment = Rectangle{(body[i].x * g_globalVars.cellSize) + g_globalVars.offset,
                                      (body[i].y * g_globalVars.cellSize) + g_globalVars.offset,
                                      g_globalVars.cellSize,
                                      g_globalVars.cellSize};

        DrawRectangleRounded(segment, 0.5, 6, g_globalVars.darkGreen);
    }
}

void Snake::InputListener()
{
    if (IsKeyPressed(KEY_UP) && direction.y != 1)
        ChangeDirection(Up);
    else if (IsKeyPressed(KEY_DOWN) && direction.y != -1)
        ChangeDirection(Down);
    else if (IsKeyPressed(KEY_LEFT) && direction.x != 1)
        ChangeDirection(Left);
    else if (IsKeyPressed(KEY_RIGHT) && direction.x != -1)
        ChangeDirection(Right);
}

void Snake::SnakeMovementUpdater()
{
    if (isRunning)
    {
        Vector2 nextStep = Vector2Add(body[0], direction);
        nextStep.x = PositiveModulo((int)nextStep.x, g_globalVars.cellCount);
        nextStep.y = PositiveModulo((int)nextStep.y, g_globalVars.cellCount);
        body.push_front(nextStep);

        if (!addSegment)
            body.pop_back();
        else
            addSegment = false;
    }
}

void Snake::ChangeDirection(SnakeMovementDirection dir)
{
    isRunning = true;

    switch (dir)
    {
    case Left:
        direction = {-1, 0};
        break;
    case Right:
        direction = {1, 0};
        break;
    case Up:
        direction = {0, -1};
        break;
    case Down:
        direction = {0, 1};
        break;
    }
}

inline int Snake::PositiveModulo(int i, int n)
{
    return (i % n + n) % n;
}

void Snake::Reset()
{
    body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    direction = {1, 0};
    isRunning = false;
}