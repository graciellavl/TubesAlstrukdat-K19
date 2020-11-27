#include <stdio.h>
#include "boolean.h"
#include "ADT/matriks.c"
#include "ADT/point.c"
#include "ADT/list.c"
#include "ADT/mesinkar.c"
#include "ADT/mesinkata.c"

// int main() {
//     char* string;
//     char* nama;
//     string = "kata";
//     nama = string;
//     printf("ini string %s\n", string);
//     printf("ini kata %s\n", nama);
//     Kata tes;
//     tes = toKata("hi\n");
//     int i;
//     for (i = 0; i < tes.Length; i++) {
//         printf("%c", tes.TabKata[i]);
//     }
//     printf("%d", tes.Length);
// }

/*
LIST

*/

int main() {
    List L = MakeList();
    if (IsEmpty(L)) {
        printf("kosong\n");
    }
    printf("%d\n", Length(L));
    InsertLast(&L, "tes", 1);
    printf("%s\n", L.A[0].nama);
    printf("%d\n", L.A[0].jumlah);
    UpdateList(&L, "tes", -1);
    printf("%s\n", L.A[0].nama);
    printf("%d\n", L.A[0].jumlah);
}

/*
POINT
- Baca posisi pemain & save

*/

// int main() {
//     POINT P;
//     BacaPOINT (&P); 
//     TulisPOINT(P);
//     MATRIKS M;
//     MakeMatriks(10, 10, &M);
//     SetElmt(&M, Absis(P), Ordinat(P), 'B');
//     printf("\n");
//     TulisMATRIKS(M);
//     printf("\n");
//     printf("%c", GetElmt(M, Absis(P), Ordinat(P)));
// }


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
