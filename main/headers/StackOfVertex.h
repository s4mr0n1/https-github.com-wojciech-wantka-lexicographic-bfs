#include "Vertex.h"

struct StackOfVertex {
    Vertex* ptrVertex;
    StackOfVertex* next;

    StackOfVertex();
    StackOfVertex(Vertex* v, StackOfVertex* n);

    void Push(Vertex* v);
};
