#include <raylib.h>
#include <deque>
#include "DirectionEnum.h"

#pragma once

using namespace std;

class Snake
{
private:

public:
    deque<Vector2> body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    Vector2 direction = {1, 0};
    bool addSegment = false;
    bool isRunning = false;

    void Draw();
    void InputListener();
    void SnakeMovementUpdater();
    void ChangeDirection(SnakeMovementDirection);
    int PositiveModulo(int, int);
    void Reset();
};