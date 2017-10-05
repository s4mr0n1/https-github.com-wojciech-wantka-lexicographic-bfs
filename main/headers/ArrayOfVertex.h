#include "Vertex.h"

struct ArrayOfVertex {
    int length;
    Vertex** v;

    ArrayOfVertex(int len, bool init);

    ~ArrayOfVertex();
};
