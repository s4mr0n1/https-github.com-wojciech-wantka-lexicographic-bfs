#include "Set.h"
#include "StackOfSet.h"

struct StackOfSet {
    Set* ptrSet;
    StackOfSet* next;

    StackOfSet();
    StackOfSet(Set* s, StackOfSet* n);

    void Push(Set* s);
};
