#include "BruteForce.h"

BruteForce::BruteForce(Point *points, int p_Amount) {
    Checkpoints = new LinkedPath[p_Amount - 2]; 
    counter = new int[p_Amount-2];

  
    LinkedPath *current = &Checkpoints[0];
    for (int i = 0; i < p_Amount; i++) {
        current->point = &points[i]; 
        if (i < p_Amount - 1) {
            current->nextPoint = new LinkedPath();
            current = current->nextPoint;       
        } else {
            current->nextPoint = nullptr; 
        }
    }
    for (int i = 1; i < p_Amount - 2; i++) {
        Checkpoints[i] = *copyLinkedPath(&Checkpoints[0]);
        counter[i] =  0;
    }
    maxPathCount = fact(p_Amount-1)-1;
    shortestPath = &Checkpoints[0];
}


void BruteForce::iterate(int reps)
{
    int toIteration = iterations+reps;

    while(iterations < toIteration && iterations < maxPathCount)
    {
        if(counter[chNum] < chNum+1)
        {
            ShiftPathAt(chNum+2,&Checkpoints[chNum]);
            counter[chNum]++;

            //checklength
            int len = calcPathLength(&Checkpoints[chNum]);
            if(len < shortestPathLength)
            {
                shortestPath = copyLinkedPath(&Checkpoints[chNum]);
                shortestPathLength = len;
            }

            iterations++;
        }else
        {
            counter[chNum] = 0;
            chNum+=1;
            continue;
        }
        if(chNum != 0)
        {
            while (chNum != 0)
            {
                chNum--;
                Checkpoints[chNum] = *copyLinkedPath(&Checkpoints[chNum+1]);
            }
        }
    }
}

LinkedPath *BruteForce::getShortestPath()
{
    return shortestPath;
}

