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


LinkedPath *copyLinkedPath(const LinkedPath *original)
{
    if (!original)
        return nullptr; // Handle empty list

    // Create a new head node
    LinkedPath *newHead = new LinkedPath{original->point, nullptr};
    LinkedPath *currentNew = newHead;
    const LinkedPath *currentOriginal = original->nextPoint;

    // Traverse the original list and copy nodes
    while (currentOriginal)
    {
        // Create a new node
        LinkedPath *newNode = new LinkedPath{currentOriginal->point, nullptr};
        // Link the new node to the new list
        currentNew->nextPoint = newNode;
        // Advance both pointers
        currentNew = newNode;
        currentOriginal = currentOriginal->nextPoint;
    }

    return newHead;
}
void ShiftPathAt(int pos, LinkedPath* path) {
    if (!path || pos <= 0) return; // Handle edge cases

    LinkedPath* current = path;
    LinkedPath* targetNode = nullptr;
    LinkedPath* targetNextNode = nullptr;
    LinkedPath* lastNode = nullptr;
    LinkedPath* secondToLastNode = nullptr;

    int length = 0;

    // Find the length of the path
    while (current) {
        ++length;
        current = current->nextPoint;
    }

    if (pos > length) return; // If position is out of bounds

    // Reset current pointer to head
    current = path;

    // Traverse the path again to find key nodes
    for (int i = 1; current; ++i) {
        if (i == length - pos) targetNode = current; // Node at (length - pos)
        if (i == length - pos + 1) targetNextNode = current; // Node after targetNode
        if (i == length) lastNode = current; // Last node
        if (i == length - 1) secondToLastNode = current; // Second-to-last node

        current = current->nextPoint;
    }

    // Rearrange pointers
    if (targetNode && lastNode && secondToLastNode && targetNextNode) {
        targetNode->nextPoint = lastNode;       // Target node points to last node
        lastNode->nextPoint = targetNextNode;  // Last node points to targetNextNode
        secondToLastNode->nextPoint = nullptr; // Second-to-last node is disconnected
    }
}
int calcPathLength(LinkedPath *path)
{
    int x1 ;
    int y1 ;
    int x2 ;
    int y2 ;

    int SideA;
    int SideB;

   
    int length = 0;
    LinkedPath *current = path;
    Point * first = current->point;
    while (current->nextPoint)
    { 
        x1 = current->point->x;
        y1 = current->point->y;
        x2 = current->nextPoint->point->x;
        y2 = current->nextPoint->point->y;

        SideA = x1 - x2;
        SideB = y1 - y2;

        length+=sqrt((SideA * SideA) + (SideB * SideB));
       
        current = current->nextPoint;
    }
        x1 = current->point->x;
        y1 = current->point->y;
        x2 = first->x;
        y2 = first->y;

        SideA = x1 - x2;
        SideB = y1 - y2;

        length+=sqrt((SideA * SideA) + (SideB * SideB));
    

    return length;
}

long fact(int x)
{
    long r = 1;
    for(int i = 0; i < x; i++)
    {
        r *= i+1;
    }
return r;  

}
void FreeLinkedPath(LinkedPath* head) {
    LinkedPath* current = head;
    LinkedPath* nextNode = nullptr;

    while (current != nullptr) {
        nextNode = current->nextPoint;
        delete current;               
        current = nextNode;           
    }
}


