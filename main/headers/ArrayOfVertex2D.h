#include "ArrayOfVertex.h"

struct ArrayOfVertex2D {
    int length;
    ArrayOfVertex** a;

    ArrayOfVertex2D(int len);
    ~ArrayOfVertex2D();
};
