// utils.h
#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <limits.h>
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

struct LinkedPath
{
    Point *point;
    LinkedPath *nextPoint;
};

struct LineLinkedList
{
    Line *line;
    LineLinkedList *nextNode;
};

LinkedPath *copyLinkedPath(const LinkedPath *original);

Point getRandomPoint(int screenWidth, int screenHeight);

void ShiftPathAt(int pos, LinkedPath *path);

int calcLineLength(Line *line);

int calcPathLength(LineLinkedList *lineLinkedList);

#endif // UTILS_H
