#include "Enums.h"

struct Set;

struct Vertex {
    int key;
    StateOfVertex state;

    Vertex* prev;
    Vertex* next;

    Set* ptrSet;

    Vertex(int k);
};
