#include <cstdio>

#include "Enums.h"
#include "Vertex.h"

Vertex::Vertex(int k) : key(k), prev(NULL), next(NULL), ptrSet(NULL), state(NOT_VISITED) {
}
