#include <cstdio>

#include "ArrayOfVertex.h"
#include "ArrayOfVertex2D.h"
#include "Enums.h"
#include "Set.h"
#include "StackOfSet.h"
#include "StackOfVertex.h"
#include "Vertex.h"

Set* initSet = new Set;    // initial set
Set* firstSet = initSet;

void loadGraph(ArrayOfVertex2D** neighbourhood, ArrayOfVertex** tableOfVertices) {
    int howManyVertices;    
    int howManyNeighbours;  
    int key;

    scanf("%d", &howManyVertices);

    *tableOfVertices = new ArrayOfVertex(howManyVertices, true);
    *neighbourhood = new ArrayOfVertex2D(howManyVertices);

    for (int i = 0; i < howManyVertices; i++) {
        scanf("%d", &howManyNeighbours);
        (*neighbourhood)->a[i] = new ArrayOfVertex(howManyNeighbours, false);

        for (int j = 0; j < howManyNeighbours; j++) {
            scanf("%d", &key);
            (*neighbourhood)->a[i]->v[j] = (*tableOfVertices)->v[key - 1];
        }
    }
}

bool RemoveVertexFromSet(Vertex* v) {
    Set* new_Set = v->ptrSet->newSet;
    Set* old_Set = v->ptrSet;
    bool isSetRemoved = false;

    if (v == old_Set->firstVertex && v == old_Set->lastVertex) {
        if (old_Set != initSet) {
            if (old_Set == firstSet) {
                firstSet = firstSet->nextSet;
            }
            delete old_Set;
            isSetRemoved = true;
        } else {
            old_Set->firstVertex = NULL;
            old_Set->lastVertex = NULL;
        }
    } else {
        if (v == old_Set->firstVertex) {
            old_Set->firstVertex = v->next;
        }
        if (v == old_Set->lastVertex) {
            old_Set->lastVertex = v->prev;
        }
    }

    if (v->prev) {
        v->prev->next = v->next;
    }
    if (v->next) {
        v->next->prev = v->prev;
    }

    v->prev = NULL;
    v->next = NULL;
    v->ptrSet = new_Set;

    return isSetRemoved;
}

void AddVertexToSet(Vertex* v) {
    Set* new_Set = v->ptrSet;

    // if set is not empty
    if (new_Set->lastVertex) {
        v->prev = new_Set->lastVertex;
        new_Set->lastVertex->next = v;
    } else { // if set is empty
        new_Set->firstVertex = v;
        // if there is another set "at the front side"
        if (new_Set->prevSet) {
            v->prev = new_Set->prevSet->lastVertex;
            new_Set->prevSet->lastVertex->next = v;
        }
        // else v->prev = NULL (this is initially fulfilled)
    }

    // if there is another set "at the back side"
    if (new_Set->nextSet) {
        v->next = new_Set->nextSet->firstVertex;
        // initial set may be empty
        if (new_Set->nextSet->firstVertex) {
            new_Set->nextSet->firstVertex->prev = v;
        }
    }
    // else v->next = NULL

    new_Set->lastVertex = v;
}

void RelocateVertex(Vertex* v, StackOfSet* listOfDividedSets) {
    Set* old_Set = v->ptrSet;
    bool isSetRemoved;

    if (!old_Set->isDivided) {
        old_Set->newSet = new Set(old_Set);
        if (old_Set == firstSet) {
            firstSet = old_Set->newSet;
        }
    }

    isSetRemoved = RemoveVertexFromSet(v);
    AddVertexToSet(v);

    if (!isSetRemoved) {
        listOfDividedSets->Push(old_Set);
        old_Set->isDivided = true;
    }
}

Vertex* InitListOfVertices(ArrayOfVertex* tableOfVertices, Mode mode) {
    int u;
    Vertex* first;
    Vertex* prev;

    scanf("%d", &u);
    prev = tableOfVertices->v[u - 1];
    first = prev;
    first->ptrSet = initSet;

    if (mode == PLUS) {
        Vertex* next;
        int length = tableOfVertices->length;
        int i;

        for (i = 0; i < length - 1; i++) {
            scanf("%d", &u);
            next = tableOfVertices->v[u - 1];
            next->ptrSet = initSet;
            next->prev = prev;
            prev->next = next;
            prev = next;
        }
    }

    return first;
}

void LexBFS(ArrayOfVertex* tableOfVertices, ArrayOfVertex2D* neighbourhood, Mode mode) {
    int rank;

    Vertex* firstVertex = InitListOfVertices(tableOfVertices, mode);
    Vertex* neighbour;
    ArrayOfVertex* tableOfNeighbourhood;
    StackOfSet* listOfDividedSets;
    StackOfSet* tmp1;
    StackOfVertex* listOfPrintedVertices = new StackOfVertex;
    StackOfVertex* tmp2;

    AddVertexToSet(firstVertex);
    firstVertex->state = VISITED;

    // while list is not empty
    while (firstVertex) {
        printf("%d ", firstVertex->key);
        firstVertex->state = PRINTED;
        listOfPrintedVertices->Push(firstVertex);
        tableOfNeighbourhood = neighbourhood->a[firstVertex->key - 1];
        RemoveVertexFromSet(firstVertex);
        rank = tableOfNeighbourhood->length;
        listOfDividedSets = new StackOfSet;
        for (int i = 0; i < rank; i++) {
            neighbour = tableOfNeighbourhood->v[i];
            if (neighbour->state == NOT_VISITED) {
                neighbour->ptrSet = initSet;
                AddVertexToSet(neighbour);
                neighbour->state = VISITED;
            }
            if (neighbour->state == NOT_VISITED || neighbour->state == VISITED) {
                RelocateVertex(neighbour, listOfDividedSets);
            }
        }
        if (listOfDividedSets->ptrSet != NULL) while (listOfDividedSets != NULL) {
            tmp1 = listOfDividedSets;
            tmp1->ptrSet->isDivided = false;
            tmp1->ptrSet->newSet = NULL;
            listOfDividedSets = tmp1->next;
            delete tmp1;
        }

        firstVertex = firstSet->firstVertex;
    }

    while (listOfPrintedVertices != NULL) {
        tmp2 = listOfPrintedVertices;
        tmp2->ptrVertex->state = NOT_VISITED;
        listOfPrintedVertices = tmp2->next;
        delete tmp2;
    }

    printf("\n");
}

void main() {
    int n;                  // number of graphs
    int k;                  // number of test of given graph
    int t;                  // type of test

    ArrayOfVertex2D* neighbourhood;
    ArrayOfVertex* tableOfVertices;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        loadGraph(&neighbourhood, &tableOfVertices);
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &t);
            if (t == 1) {
                LexBFS(tableOfVertices, neighbourhood, BASIC);
            } else {
                LexBFS(tableOfVertices, neighbourhood, PLUS);
            }
        }
        delete tableOfVertices;
        delete neighbourhood;
    }

    delete initSet;
}
