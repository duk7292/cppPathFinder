#include "BruteForce.h"
BruteForce::BruteForce(Point *points, int p_Amount)
{
    for (int i = 0; i < p_Amount; i++)
    {
        Line *line = new Line();

        if (i == p_Amount - 1)
        {
            line->A = &points[i];
            line->B = &points[0];
        }
        else
        {
            line->A = &points[i];
            line->B = &points[i + 1];
        }

        if (i == 0)
        {
            List->line = line;
        }
        else
        {
            List->nextNode = new LineLinkedList();
            List->nextNode->line = line;
            List = List->nextNode;
        }
    }
    List->nextNode = nullptr;
}

LineLinkedList *BruteForce::getShortesPathHead()
{
    return ShortestPathHead;
}

void BruteForce::iterate(int reps)
{
}

LineLinkedList *BruteForce::getPathById(int id)
{
}
