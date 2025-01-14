// BruteForce.h
#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H
#include "utils.h"
class BruteForce
{
private:
    int iterations = 0;
    int chNum = 0;

    int maxPathCount;

    int shortestPathLength = INT_MAX;

    int* counter;

    LinkedPath* Checkpoints;

    LinkedPath* shortestPath;

public:
    BruteForce(Point *points, int p_Amount);
   
    void iterate(int reps);

    LinkedPath* getShortestPath();

    
};

#endif
