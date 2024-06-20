#include <raylib.h>
#include <deque>
#pragma once

using namespace std;

class Food
{
public:
    Vector2 position;

    Food(deque<Vector2> deque);
    void Draw();
    bool ElementInDeque(Vector2, deque<Vector2>);
    Vector2 GenerateRandomPos(deque<Vector2>);
    Vector2 GenerateRandomCell();

private:
    float radius;
    Texture2D m_texture;
};