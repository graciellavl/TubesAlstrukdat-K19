/* File: matriks.c */

#include "matriks.h"
#include "../boolean.h"
#include <stdio.h>

/* *** Konstruktor membentuk MATRIKS *** */
void MakeMatriks (int NBrs, int NKol, MATRIKS * M) { 
    NBrsEff(*M) = NBrs;
    NKolEff(*M) = NKol;
    indeks i;
    indeks j;
    for (i = 0; i < NBrs+2; i++) {
        for (j = 0; j < NKol+2; j++) {
            if ((i == 0) || (i == NBrs+1)) {
                Elmt(*M,i,j) = '*';
            } else if ((j == 0) || (j == NKol+1)){
                Elmt(*M,i,j) = '*';
            } else {
                Elmt(*M,i,j) = ' ';
            }
        }
    }
}

ElType GetElmt (MATRIKS M, int NB, int NK) {
    return Elmt(M, NB, NK);
}

void SetElmt (MATRIKS * M, int NB, int NK, ElType X) {
    Elmt(*M, NB, NK) = X;
}

void TulisMATRIKS (MATRIKS M) {
    indeks i, j;
    for (i = 0; i < NBrsEff(M)+2; i++) {
        for (j = 0; j < NKolEff(M)+2; j++) {
            printf("%c", Elmt(M,i,j));
        }
        printf("\n");
    }
}

boolean IdxValid (int Brs, int Kol) {
    return (Brs < BrsMax && Brs >= BrsMin && Kol < KolMax && Kol >= KolMin);
}