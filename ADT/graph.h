#ifndef GRAPH
#define GRAPH

#include "../boolean.h"

#define Nil 0

typedef struct tNode *adrNode;
typedef struct sNode *adrSuccNode;
typedef struct tNode {
    int id;
    adrSuccNode Trail;
    adrNode Next;
} Node;

typedef struct sNode {
    int id;
    adrSuccNode Next;
} SuccNode;

typedef struct {
    adrNode First;
} Graph;

/* *** SELEKTOR *** */
#define First(G) (G).First
#define id(G) (G)->id
#define Trail(G) (G)->Trail
#define Next(G) (G)->Next


void CreateGraph(Graph* G, int X);
    
adrNode AlokNode(int X);

adrSuccNode AlokSuccNode(int X);

void DealokNode(adrNode P);

void InsertNode(Graph* G, int A);

void InsertSuccNode(Graph* G, int A, int B);

void printGraph(Graph G);

#endif