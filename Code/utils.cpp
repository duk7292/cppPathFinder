#include "utils.h"

Point getRandomPoint(int screenWidth, int screenHeight)
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

    Point r_p;
    r_p.x = x_pos;
    r_p.y = y_pos;

    return r_p;
}

int calcPathLength(LineLinkedList *path)
{
    int Length = 0;
    LineLinkedList *current = path;

    while (current)
    {
        Length += calcLineLength(current->line);
        current = current->nextNode;
    }
    return Length;
}
int calcLineLength(Line *line)
{
    int x1 = line->A->x;
    int y1 = line->A->y;
    int x2 = line->B->x;
    int y2 = line->B->y;

    int SideA = x1 - x2;
    int SideB = y1 - y2;

    return sqrt((SideA * SideA) + (SideB * SideB));
}