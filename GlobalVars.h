#include <raylib.h>

#pragma once

class GlobalVars
{
public:
    const Color green = {173, 204, 96, 255};
    const Color darkGreen = {43, 51, 24, 255};
    const int cellCount = 30;
    const int cellSize = 25;
    const int offset = 75;
};

const GlobalVars g_globalVars;