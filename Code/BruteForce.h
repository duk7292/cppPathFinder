// BruteForce.h
#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H
#include "utils.h"
class BruteForce
{
private:
    LineLinkedList *List = new LineLinkedList();
    LineLinkedList *ListHead = List;

public:
    BruteForce(Point *points, int p_Amount);
    LineLinkedList *getCurrentLinkedListHead();
    void iterate();
};

#endif