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



struct LinkedPath
{
    Point *point;
    LinkedPath *nextPoint;
};



LinkedPath *copyLinkedPath(const LinkedPath *original);

Point getRandomPoint(int screenWidth, int screenHeight);

void ShiftPathAt(int pos, LinkedPath *path);

void FreeLinkedPath(LinkedPath* head) ;

int calcPathLength(LinkedPath *path);

long fact(int x);




#endif // UTILS_H
