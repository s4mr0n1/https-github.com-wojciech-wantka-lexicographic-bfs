#include "ArrayOfVertex.h"

ArrayOfVertex::ArrayOfVertex(int len, bool init) : length(len) {
    v = new Vertex* [len];
    if (init) {
        for (int i = 0; i < len; i++) {
            v[i] = new Vertex(i + 1);
        }
    }
}

ArrayOfVertex::~ArrayOfVertex() {
    for (int i = 0; i < length; i++) {
        delete v[i];
    }
    delete[] v;
}
