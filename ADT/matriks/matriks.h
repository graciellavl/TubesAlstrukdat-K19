/* File: matriks.h */

#ifndef MATRIKS_H
#define MATRIKS_H

#include "../boolean.h"
#include "../point/point.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define BrsMin 10
#define BrsMax 21
#define KolMin 10
#define KolMax 31

/* Definisi tipe yang digunakan */

typedef int indeks; // Tipe indeks
typedef char ElType; // Tipe elemen dalam matriks, 
                     // dapat berupa *, angka dan huruf P, S, B
typedef struct {
    ElType Mem[BrsMax+1][KolMax+1];
    int NBrsEff; /* Ukuran baris yang terdefinisi */
    int NKolEff; /* Ukuran kolom yang terdefinisi */
} MATRIKS; 

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */ 

/* *** Selektor *** */
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define Elmt(M,i,j) (M).Mem[(i)][(j)]

/* *** Konstruktor membentuk MATRIKS *** */
void MakeMatriks (int NBrs, int NKlm, MATRIKS * M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Matriks dengan border */

void TulisMATRIKS (MATRIKS M);
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

void SetElmt (MATRIKS *M, int NB, int NK, ElType X);
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) diisi sesuai dengan inputan */
/* Proses: mengubah elemen pada posisi NB, NK menjadi X */

boolean IdxValid (int Brs, int Kol);
/* Mengirimkan true apabila index berada dalam range baris dan kolom*/

ElType GetElmt (MATRIKS M, int NB, int NK);
/* Mengirimkan nilai elemen pada posisi NB, NK */

POINT GetPoint(MATRIKS M, ElType X);
/* Mengirimkan Point dimana elemen X berada */

#endif