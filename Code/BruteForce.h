// BruteForce.h
#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H
#include "utils.h"
class BruteForce
{
private:
    LineLinkedList *List = new LineLinkedList();
    LineLinkedList *ListHead = List;

    int shortestPathLength = INT_MAX;

    LineLinkedList *ShortestPathHead = List;

    LineLinkedList *getPathById(int id);

    int PathId = 0;

public:
    BruteForce(Point *points, int p_Amount);
    LineLinkedList *getShortesPathHead();
    void iterate(int reps);
};

#endif
