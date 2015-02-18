#include "ArrayOfVertex2D.h"
#include "ArrayOfVertex.h"

ArrayOfVertex2D::ArrayOfVertex2D(int len) : length(len) { a = new ArrayOfVertex* [len]; }

ArrayOfVertex2D::~ArrayOfVertex2D() {
	int i;
	for (i = 0; i < length; i++) delete [] a[i]->v;
}