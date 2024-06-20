#include <raylib.h>
#include "Game.h"
#include "GlobalVars.h"

using namespace std;

int main()
{
    InitWindow(2 * g_globalVars.offset + g_globalVars.cellSize * g_globalVars.cellCount,
               2 * g_globalVars.offset + g_globalVars.cellSize * g_globalVars.cellCount,
               "Retro Snake");
    SetTargetFPS(60);
    
    Game game = Game();

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        game.Update();
        ClearBackground(g_globalVars.green);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}