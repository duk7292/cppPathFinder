#include "utils.h"

pair<int, int> getRandomPoint(int screenWidth, int screenHeight)
{
    // Seed the random number generator (only do this once in your program)
    static bool isSeeded = false;
    if (!isSeeded)
    {
        std::srand(std::time(nullptr));
        isSeeded = true;
    }

    // Generate random positions within the screen dimensions
    int x_pos = std::rand() % screenWidth;
    int y_pos = std::rand() % screenHeight;

    return make_pair(x_pos, y_pos);
}
