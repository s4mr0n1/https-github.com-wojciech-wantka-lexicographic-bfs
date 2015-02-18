#include "StackOfVertex.h"

#include "Vertex.h"
#include <cstdio>

StackOfVertex::StackOfVertex() : ptrVertex(NULL), next(NULL) { }

StackOfVertex::StackOfVertex(Vertex* v, StackOfVertex* n) : ptrVertex(v), next(n) { }

void StackOfVertex::Push(Vertex* v) {
	if (this->ptrVertex == NULL) {
		this->ptrVertex = v;
		return;
	}
	StackOfVertex* new_Vertex = new StackOfVertex(v, this->next);
	this->next = new_Vertex;
}