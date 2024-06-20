#include <raylib.h>
#include "Food.h"
#include "GlobalVars.h"
#include <raymath.h>
#include "iostream"

using namespace std;

Food::Food(deque<Vector2> deque)
{
    radius = g_globalVars.cellSize / 2;
    position = GenerateRandomPos(deque);
}

void Food::Draw()
{
    DrawCircle((position.x * g_globalVars.cellSize) + radius + g_globalVars.offset,
               (position.y * g_globalVars.cellSize) + radius + g_globalVars.offset,
               radius, RED);
}

bool Food::ElementInDeque(Vector2 element, deque<Vector2> deque)
{
    for (unsigned int i = 0; i < deque.size(); i++)
    {
        if (Vector2Equals(element, deque[i]))
        {
            return true;
        }
    }
    return false;
}

Vector2 Food::GenerateRandomPos(deque<Vector2> deque)
{
    Vector2 pos = GenerateRandomCell();
    while (ElementInDeque(pos, deque))
    {
        pos = GenerateRandomCell();
    }
    return pos;
}

Vector2 Food::GenerateRandomCell()
{
    float x = GetRandomValue(0, g_globalVars.cellCount - 1);
    float y = GetRandomValue(0, g_globalVars.cellCount - 1);
    return Vector2{x, y};
}