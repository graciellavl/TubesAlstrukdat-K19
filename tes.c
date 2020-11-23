#include <stdio.h>
#include "boolean.h"
#include "ADT/matriks.c"
#include "ADT/point.c"

/*
POINT
- Baca posisi pemain & save

*/

int main() {
    POINT P;
    BacaPOINT (&P); 
    TulisPOINT(P);
    MATRIKS M;
    MakeMatriks(10, 10, &M);
    SetElmt(&M, Absis(P), Ordinat(P), 'B');
    printf("\n");
    TulisMATRIKS(M);
    printf("\n");
    printf("%c", GetElmt(M, Absis(P), Ordinat(P)));
}


// ---------------------------------------------------------
/*
MAP

Konfigurasi map (Baca dari file luar)
Line pertama    : MakeMatriks
Line kedua      : iterasi loop
Line ke3 - n    : SetEl
Line ke n+1     : TulisMatriks, MakeGraph
*/


// int main() {
//     printf("tes\n");
//     MATRIKS M;
//     indeks kol, brs;
//     if (!IdxValid(brs, kol)) {
//         printf("Baris atau kolom tidak valid.\n");
//     } else {
//         MakeMatriks(brs, kol, &M);
//         TulisMATRIKS(M);
//         SetElmt(&M, 2, 2, '3'); // nanti fungsinya ada di main
//         TulisMATRIKS(M);
//         printf("%c", GetElmt(M,2,2)); // nanti fungsinya ada di main
//     }
//     return 0;
// }
