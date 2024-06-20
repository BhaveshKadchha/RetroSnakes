#include "Snake.h"
#include "Food.h"
#include "GlobalVars.h"

class Game
{
private:
    double lastUpdateTime = 0;
    const double moveInterval = 0.2;
    int score = 0;
    Sound eatSound;
    Sound hitSound;
    Rectangle rect = Rectangle{
        (float)(g_globalVars.offset - 5),
        (float)(g_globalVars.offset - 5),
        (float)(g_globalVars.cellSize *g_globalVars.cellCount + 10),
        (float)(g_globalVars.cellSize *g_globalVars.cellCount + 10)};

public:
    Game();
    Snake snake = Snake();
    Food food = Food(snake.body);
    void Draw();

    void Update();
    void SnakeMovementUpdater();
    void CheckCollision();

    void GameOver();
    ~Game();
};