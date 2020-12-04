#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

void CreateGraph(Graph* G, int X) 
/* I.S. Sembarang */
/* F.S. Membuat sebuah Graph dengan satu Node */
{
    adrNode P = AlokNode(X);
    First(*G) = P;
}

adrNode AlokNode(int X) 
/* Menghasilkan address dari sebuah Node */
{
    adrNode P;
    P = (adrNode) malloc (sizeof(Node));
    if (P != Nil) {
        id(P) = X;
        Trail(P) = Nil;
        Next(P) = Nil;
        return P;
    } 
    return Nil;
}

adrSuccNode AlokSuccNode(int X) 
/* Menghasilkan address dari sebuah SuccNode */
{
    adrSuccNode P;
    P = (adrSuccNode) malloc (sizeof(SuccNode));
    if (P != Nil) {
        Next(P) = Nil;
        id(P) = X;
        return P;
    }
    return Nil;
}

void DealokNode(adrNode P) 
/* I.S. Node terdefinisi */
/* F.S. Node di dealokasi */
{
    free(P);
}

void InsertNode(Graph* G, int A) 
/* I.S. Graph terdefinisi */
/* F.S. A menjadi id dari Node pada Graph */
{
    adrNode P = AlokNode(A);
    if (P != Nil) {
        if (First(*G) == Nil) {
            First(*G) = P;
        } else {
            adrNode temp = First(*G);
            while (Next(temp) != Nil) {
                temp = Next(temp);
            }
            Next(temp) = P;
        }
    }
}

void InsertSuccNode(Graph* G, int A, int B) 
/* I.S. Graph terdefinisi */
/* F.S. B menjadi id SuccNode danri Node A */
{
    adrSuccNode P = AlokSuccNode(B);
    if (P != Nil) {
        adrNode temp = First(*G);
        while (id(temp) != A) {
            temp = Next(temp);
        }
        adrSuccNode tempSucc = Trail(temp);
        if (tempSucc == Nil) {
            Trail(temp) = P;
        } else {
            while (Next(tempSucc) != Nil) {
                tempSucc = Next(tempSucc);
            }
            Next(tempSucc) = P;
        }
    }
}

void PrintGraph(Graph G) 
/* I.S. Graph terdefinisi */
/* F.S. Graph tercetak pada layar */
{
    adrNode P = First(G);
    while (P != Nil) {
        printf("%d > ", id(P));
        adrSuccNode temp = Trail(P); 
        while (temp != Nil) {
            printf("%d ", id(temp));
            temp = Next(temp);
        }
        printf("\n");
        P = Next(P);
    }
}