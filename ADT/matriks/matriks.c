/* File: matriks.c */

#include "matriks.h"
#include "../boolean.h"
#include <stdio.h>

/* *** Konstruktor membentuk MATRIKS *** */
void MakeMatriks (int NBrs, int NKol, MATRIKS * M) 
/* I.S. Sembarang */
/* F.S. Membuat sebuah Matriks dengan border */
{ 
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

void TulisMATRIKS (MATRIKS M) 
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
*****
*123*
*456*
*890*
*****
*/
{
    indeks i, j;
    for (i = 0; i < NBrsEff(M)+2; i++) {
        for (j = 0; j < NKolEff(M)+2; j++) {
            printf("%c", Elmt(M,i,j));
        }
        printf("\n");
    }
}

ElType GetElmt (MATRIKS M, int NB, int NK) 
/* Mengirimkan nilai elemen pada posisi NB, NK */
{
    return Elmt(M, NB, NK);
}

void SetElmt (MATRIKS * M, int NB, int NK, ElType X) 
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) diisi sesuai dengan inputan */
/* Proses: mengubah elemen pada posisi NB, NK menjadi X */
{
    Elmt(*M, NB, NK) = X;
}


boolean IdxValid (int Brs, int Kol) 
/* Mengirimkan true apabila index berada dalam range baris dan kolom*/
{
    return (Brs < BrsMax && Brs >= BrsMin && Kol < KolMax && Kol >= KolMin);
}

POINT GetPoint(MATRIKS M, ElType X) 
/* Mengirimkan Point dimana elemen X berada */
{
    indeks i, j;
    boolean found = false;
    for (i = 1; i < NBrsEff(M)+2 && !found; i++) {
        for (j = 1; j < NKolEff(M)+2 && !found; j++) {
            if (Elmt(M,i,j) == X) {
                found = true;
            }
        }
    }
    POINT posisi = MakePOINT(i-1,j-1);
    return posisi;
}