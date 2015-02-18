#include "Vertex.h"

#include "Enums.h"
#include <cstdio>

Vertex::Vertex(int k) : key(k), prev(NULL), next(NULL), ptrSet(NULL), state(NOT_VISITED) { }