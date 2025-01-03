// utils.h
#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

struct Point
{
    int x;
    int y;
};

struct Line
{
    Point *A;
    Point *B;
};

struct LineLinkedList
{
    Line *line;
    LineLinkedList *nextNode;
};

Point getRandomPoint(int screenWidth, int screenHeight);

int calcLineLength(Line *line);

int calcPathLength(LineLinkedList *lineLinkedList);

#endif // UTILS_H
