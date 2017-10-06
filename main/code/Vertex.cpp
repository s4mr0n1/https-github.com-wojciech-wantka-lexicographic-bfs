#include "Vertex.h"

#include <cstdio>

#include "Enums.h"

Vertex::Vertex(int k) : key(k), prev(NULL), next(NULL), ptrSet(NULL), state(NOT_VISITED) {
}
