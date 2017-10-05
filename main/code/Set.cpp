#include <cstdio>

#include "Set.h"

Set::Set(Set* old) : firstVertex(NULL), lastVertex(NULL), prevSet(old->prevSet), nextSet(old), newSet(NULL), isDivided(false) {
    if (old->prevSet) {
        old->prevSet->nextSet = this;
    }
    old->prevSet = this;
}

Set::Set() : firstVertex(NULL), lastVertex(NULL), prevSet(NULL), nextSet(NULL), newSet(NULL), isDivided(false) {
}

Set::~Set() {
    if (this->prevSet) {
        this->prevSet->nextSet = this->nextSet;
    }
    if (this->nextSet) {
        this->nextSet->prevSet = this->prevSet;
    }
}
