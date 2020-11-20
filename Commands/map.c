/*
MAP

Konfigurasi map (Baca dari file luar)
Line pertama    : MakeMatriks
Line kedua      : iterasi loop
Line ke3 - n    : SetEl
Line ke n+1     : TulisMatriks, MakeGraph
*/

#include "../ADT/matriks.c"
#include <stdio.h>

int main() {
    printf("tes\n");
    MATRIKS M;
    indeks kol, brs;
    scanf("%d", &brs); // nanti ganti baca dari file konfigurasi
    scanf("%d", &kol); // nanti ganti baca dari file konfigurasi
    if (!IdxValid(brs, kol)) {
        printf("Baris atau kolom tidak valid.\n");
    } else {
        MakeMatriks(brs, kol, &M);
        TulisMATRIKS(M);
        SetElmt(&M, 2, 2, '3'); // nanti fungsinya ada di main
        TulisMATRIKS(M);
        printf("%c", GetElmt(M,2,2)); // nanti fungsinya ada di main
    }
    return 0;
}
