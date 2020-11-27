#ifndef GRAPH
#define GRAPH

#include "../boolean.h"

#define Nil "..."

typedef int adrNode;
typedef int adrSuccNode;
typedef struct {
    int id;
    int NPred;
    adrNode Trail;
    adrNode Next;
} Node;

typedef struct {
    adrNode Succ;
    adrSuccNode Next;
} SuccNode;

typedef struct {
    adrNode First;
} Graph;

#endif