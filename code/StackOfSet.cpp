#include "StackOfSet.h"

#include "Set.h"
#include <cstdio>

StackOfSet::StackOfSet() : ptrSet(NULL), next(NULL) { }

StackOfSet::StackOfSet(Set* s, StackOfSet* n) : ptrSet(s), next(n) { } 

void StackOfSet::Push(Set* s) {
	if (this->ptrSet == NULL) {
		this->ptrSet = s;
		return;
	}
	StackOfSet* new_Set = new StackOfSet(s, this->next);
	this->next = new_Set;
}