#pragma once

#include "StackOfSet.h"
#include "Set.h"

struct StackOfSet {
	Set* ptrSet;
	StackOfSet* next;

	StackOfSet();
	StackOfSet(Set* s, StackOfSet* n);
	
	void Push(Set* s);
};