#include <stdio.h>
#include "boolean.h"

/*
POINT
- Baca posisi pemain & save

*/

#include "ADT/point.c"
int main() {
    POINT P;
    BacaPOINT (&P); 
    TulisPOINT(P);
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

// #include "ADT/matriks.c"

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
